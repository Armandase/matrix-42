#include "../inc/Vector.hpp"
#include "../inc/Matrix.hpp"
#include <stdexcept>
#include <cmath>

Vector::Vector(std::vector<K> numbers){
    if (numbers.size() < 2){
        throw std::runtime_error("the numbers given as parameters can't be used as vector");
    }
    _values = numbers;
}


Vector::Vector(size_t size){
    if (size <= 0){
        throw std::runtime_error("Wrong provided size to create vector.");
    }

    _values = std::vector<K>(size, 0);
}


std::vector<K> Vector::get_values() const{
    return _values;
}

usize_t Vector::get_size() const{
    return _values.size();
}

K Vector::get_value(size_t i) const {
    if (i > this->get_size()){
        throw std::runtime_error("impossible to get a value outside the vector");
    }
    return _values[i];
}


void    Vector::set_values(std::vector<K>& vec)
{
   this-> _values = vec;
}
void    Vector::set_specific_value (size_t i, K value){
    if (i >= _values.size()){
        throw std::runtime_error("impossible to set a value outside the vector");
    }
    _values[i] = value;
}

void    Vector::add(Vector add){
    std::vector<K> add_values = add.get_values();
    usize_t size = add_values.size();

    if (size != _values.size()){
        throw std::runtime_error("impossible to add two vectors of different size");
    }
    for (usize_t i = 0; i < size; i++){
        _values[i] += add_values[i];
    }
}

void    Vector::sub(Vector sub){
    std::vector<K> sub_values = sub.get_values();
    usize_t size = sub_values.size();

    if (size != _values.size()){
        throw std::runtime_error("impossible to subtract two vectors of different size");
    }
    for (usize_t i = 0; i < size; i++){
        _values[i] -= sub_values[i];
    }
}

void    Vector::scl(K scalar){
    usize_t size = _values.size();
    for (usize_t i = 0; i < size; i++){
        _values[i] *= scalar;
    }
}

/*
    positif => les vecteurs pointent dans des directions similaires (angle aigu).
    nul => les vecteurs sont orthogonaux (perpendiculaires / angle droit).
    négatif => les vecteurs pointent dans des directions opposées (angle obtus).

    Somme des produits des coordonnées des vecteurs
*/
K   Vector::dot(Vector dot){
    usize_t size = _values.size();
    if (size != dot.get_size()){
        throw std::runtime_error("impossible to add two vectors of different size");
    }
    std::vector<K> dot_values = dot.get_values();
    K result = 0;
    for (usize_t i = 0; i < size; i++){
        if (i == 0){
            result = _values[i] * dot_values[i];
            continue ;
        }
        result += _values[i] * dot_values[i];
    }
    return result;
}

/*
cos(θ) = 1 : colinéaires et pointent dans la même direction (angle de 0°).
cos⁡(θ) = 0 : orthogonaux (angle de 90°).
cos(θ) = −1: colinéaires mais pointent dans des directions opposées (angle de 180°).
*/
K   Vector::angle_cos(Vector &v){
    if (this->get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a different size");
    }

    K dot = this->dot(v);
    K u_norm = this->norm();
    K v_norm = v.norm();
    
    if (u_norm == 0 || v_norm == 0){
        throw std::runtime_error("A vector provided has a null norm");
    }
    return (dot / (u_norm * v_norm));
}

/*
Le produit renvoie un vecteur perpendiculaire aux deux vecteurs en entrée.
/!\ pas commutatif
*/
Vector   Vector::cross_product(Vector &v){
    if (this->get_size() != 3 || this->get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a wrong size");
    }
    std::vector<K> result_vec;

    K y1z2 = this->get_value(1) * v.get_value(2);
    K z1y2 = this->get_value(2) * v.get_value(1);

    K z1x2 = this->get_value(2) * v.get_value(0);
    K x1z2 = this->get_value(0) * v.get_value(2);

    K x1y2 = this->get_value(0) * v.get_value(1);
    K y1x2 = this->get_value(1) * v.get_value(0);

    result_vec.push_back(y1z2 - z1y2);
    result_vec.push_back(z1x2 - x1z2);
    result_vec.push_back(x1y2 - y1x2);
    return (Vector (result_vec));
}

Matrix   Vector::outer_product(Vector &v){
    size_t size_a = this->get_size();
    size_t size_b = v.get_size();
    Matrix res(size_a, size_b);
    double a = 0;
    double b = 0;
    
    for (size_t i = 0; i < size_a; i++){
        a = this->get_value(i);
        for (size_t j = 0; j < size_b; j++){
            b = v.get_value(j);
            res.set_specific_value(i, j, a * b);
        }
    }
    return res;
}

// La norme d'un vecteur est une mesure de sa longueur / taille.
// norme 1 : somme des valeurs absolues des coordonnées 
K   Vector::norm_1(){
    usize_t size = _values.size();
    K   result = (_values[0] < 0) ? -_values[0] : _values[0];
    K   abs;
    for (usize_t i = 1; i < size; i++){
        abs = (_values[i] < 0) ? -_values[i] : _values[i];
        result += abs;
    }
    return (result);
}

static K abs(K value) {
    return (value < 0) ? -value : value;
}

K  pow(K value, int power) {
    K result = 1;
    for (int i = 0; i < power; i++){
        result *= value;
    }
    return (result);
}

K   sqrt(K value) {
    if (value < 0)
        return -1;
    else if (value == 0 || value == 1)
        return value;
    
    K result = value;  // Initial guess
    K previous;
    K epsilon = std::numeric_limits<K>::epsilon();  // Tolerance

    do {
        previous = result;
        // Newton-Raphson method formula
        result = (result + value / result) / 2;
    } while (abs(result - previous) > epsilon);  // Converge within epsilon tolerance

    return (result);
}

// norme 2 : racine carrée de la somme des carrés des coordonnées
K   Vector::norm(){
    usize_t size = _values.size();
    K   tmp;
    K   abs = (_values[0] < 0) ? -_values[0] : _values[0];
    K   result = pow(abs, 2);

    for (usize_t i = 1; i < size; i++){
        abs = (_values[i] < 0) ? -_values[i] : _values[i];
        tmp = pow(abs, 2);
        result += tmp;
    }
    return (sqrt(result));
}
// norme infinie : valeur absolue de la coordonnée la plus grande
K   Vector::norm_inf(){
    usize_t size = _values.size();
    K   abs = (_values[0] < 0) ? -_values[0] : _values[0];
    K   result = abs;

    for (usize_t i = 1; i < size; i++){
        abs = (_values[i] < 0) ? -_values[i] : _values[i];
        if (abs > result){
            result = abs;
        }
    }
    return (result);
}

K Vector::average() const{
    K ret = 0.;
    const usize_t size = this->get_size();
    K scalar = 1. / size;

    for (usize_t i = 0; i < size; i++){
        ret += (_values[i] * scalar);
    }
    return ret;
}

// VAR  ∑ (x - x̄)²/N
K Vector::variance_population() const{
    K ret = 0;
    usize_t size = this->get_size();

    if (size == 0)
        return 0;

    K avg = this->average();

    for (usize_t i = 0; i < size; i++){
        ret += pow((this->get_value(i) - avg), 2);
    }
    return ret / size;
}

// VAR  ∑ (x - x̄)²/N -1
K Vector::variance_sample() const{
    K ret = 0;
    usize_t size = this->get_size();

    if (size == 0)
        return 0;

    K avg = this->average();

    for (usize_t i = 0; i < size; i++){
        ret += pow((this->get_value(i) - avg), 2);
    }
    return ret / (size - 1);
}

K Vector::std(bool sample) const{
    K variance = 0;
    if (sample == true){
        variance = this->variance_sample();
    } else {
        variance = this->variance_population();
    }
    return (sqrt(variance));
}


// COV  ∑ (xi - X) (yi - Y)/N
K Vector::covariance(const Vector& y, bool sample) const {
    K ret = 0.;
    usize_t size = this->get_size();
    if (size != y.get_size() || size == 0)
        return 0.;
    K mean_x = this->average();
    K mean_y = y.average();

    for (usize_t i = 0; i < size; i++){
        ret += ((this->get_values()[i] - mean_x) * (y.get_values()[i] - mean_y));
    }

    if (sample == true)
        return ret / (size - 1);
    return ret / size;
}

Vector Vector::projection(const Vector& a){
    std::vector<K> result_vec = this->_values;
    Vector res(result_vec);
    double scalar = 0;


    scalar = this->dot(a);
    scalar /= pow(this->norm(), 2);

    res = res * scalar;
    return res;
}

Vector& Vector::operator + (const Vector& add_overload)
{
	this->add(add_overload);
	return (*this);
}

Vector& Vector::operator - (const Vector& sub_overload)
{
	this->sub(sub_overload);
	return (*this);
}

Vector& Vector::operator * (const K scalar)
{
	this->scl(scalar);
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Vector& values)
{
    std::vector<K> vector = values.get_values();
    usize_t size = vector.size();
    for (usize_t i = 0; i < size; i++){
        os << "[" << vector[i] << "]\n";
    }
	return (os);
}


Matrix covariance_matrix(const std::vector<Vector>& list_vec, bool sample){
    size_t list_size = list_vec.size();
    Matrix ret(list_size, list_size);

    for (size_t i = 0; i < list_size; i++){
        for (size_t j = 0; j < list_size; j++){
            // size_t vec_size = list_vec[i].get_size();

            // if (() != vec_size){
                // throw std::runtime_error("Can't compute covariance matrix with differents vector sizes.");
            // }
            K value = list_vec[i].covariance(list_vec[j], sample);
            std::cout << "Set: " << value << " to " << j << ";" << i << std::endl;
            ret.set_specific_value(j, i, value);
        }
    }
    return ret;
}

// Each vector is mutilpled by it corresponding coefficients
// The result is the sum of every vector
// And the result's vector start with the first vector and end at the sum of every vector
Vector   linear_combination(std::vector<Vector > &e_vectors, std::vector<K> &e_coefs){
    if (e_vectors.empty()){
        throw std::runtime_error("Vector's array provided as input is empty.");
    }
    usize_t nb_vector = e_vectors.size();
    usize_t vec_size = e_vectors[0].get_size();
    if (nb_vector != e_coefs.size()){
        throw std::runtime_error("Arrays provided as input are not of the same size.");
    }
    for (usize_t i = 0; i < nb_vector; i++){
        if (vec_size != e_vectors[i].get_size()){
            throw std::runtime_error("Vectors provided as input are not of the same size.");
        }
        e_vectors[i].scl(e_coefs[i]);
        if (i > 0){
            e_vectors[0].add(e_vectors[i]);
        }
    }
    return (e_vectors[0]);
}

/*
cos(θ) = 1 : colinéaires et pointent dans la même direction (angle de 0°).
cos⁡(θ) = 0 : orthogonaux (angle de 90°).
cos(θ) = −1: colinéaires mais pointent dans des directions opposées (angle de 180°).
*/
K   angle_cos(Vector &u, Vector &v){
    if (u.get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a different size");
    }

    K dot = u.dot(v);
    K u_norm = u.norm();
    K v_norm = v.norm();
    
    if (u_norm == 0 || v_norm == 0){
        throw std::runtime_error("A vector provided has a null norm");
    }
    return (dot / (u_norm * v_norm));
}

/*
Le produit renvoie un vecteur perpendiculaire aux deux vecteurs en entrée.
/!\ pas commutatif
*/
Vector   cross_product(Vector &u, Vector &v){
    if (u.get_size() != 3 || u.get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a wrong size");
    }
    std::vector<K> result_vec;
    std::vector<K> u_vec = u.get_values();
    std::vector<K> v_vec = v.get_values();

    K y1z2 = u_vec[1] * v_vec[2];
    K z1y2 = u_vec[2] * v_vec[1];

    K z1x2 = u_vec[2] * v_vec[0];
    K x1z2 = u_vec[0] * v_vec[2];

    K x1y2 = u_vec[0] * v_vec[1];
    K y1x2 = u_vec[1] * v_vec[0];

    result_vec.push_back(y1z2 - z1y2);
    result_vec.push_back(z1x2 - x1z2);
    result_vec.push_back(x1y2 - y1x2);
    return (Vector (result_vec));
}
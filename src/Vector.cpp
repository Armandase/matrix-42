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


// // COV  ∑ (xi - X) (yi - Y)/N
// K Vector::covariance(const Vector& x_tmp, const Vector& y){
//     Vector x = x_tmp;
//     K ret = 0.;
//     usize_t size = x.get_size();
//     if (size != y.get_size() || size == 0)
//         return 0.;
//     K mean_x = x.average();
//     K mean_y = y.average();

//     for (usize_t i = 0; i < size; i++){
//         ret += ((x.get_values()[i] - mean_x) * (y.get_values()[i] - mean_y));
//     }
//     return ret / size;
// }

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

// Matrix Vector::covariance_matrix(const std::vector<Vector>& list_vec, bool sample){
//     size_t list_size = list_vec.size();
//     Matrix ret(list_size + 1, list_size + 1);


//     Vector a(this->get_size());
//     Vector b(this->get_size());

//     for (size_t i = 0; i < list_size; i++){
//         for (size_t j = 0; j < list_size; j++){
//             size_t vec_size = list_vec[i].get_size();

//             if (this->get_size() != vec_size){
//                 throw std::runtime_error("Can't compute covariance matrix with differents vector sizes.");
//             }
//             K value = 0;
//             a = list_vec[i];
//             b = list_vec[j];
//             if (i == 0){
//                 a = *this;
//             }
//             if (j == 0){
//                 b = *this;
//             }
//             value = a.covariance(b, sample);
//             std::cout << "Set: " << value << " to " << j << ";" << i << std::endl;
//             ret.set_specific_value(j, i, value);
//         }
//     }
//     return ret;
// }


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
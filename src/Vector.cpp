#include "../inc/Vector.hpp"
#include <stdexcept>
#include <cmath>

Vector::Vector(std::vector<K> numbers){
    if (numbers.size() < 2){
        throw std::runtime_error("the numbers given as parameters can't be used as vector");
    }
    _values = numbers;
}

std::vector<K> Vector::get_values() const{
    return _values;
}

usize_t Vector::get_size() const{
    return _values.size();
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

static K  pow(K value, int power) {
    K result = 1;
    for (int i = 0; i < power; i++){
        result *= value;
    }
    return (result);
}

static K   sqrt(K value) {
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

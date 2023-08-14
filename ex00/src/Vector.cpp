#include "../inc/Vector.hpp"
#include <stdexcept>

Vector::Vector(std::vector<double> numbers){
    if (numbers.size() < 2){
        throw std::runtime_error("the numbers given as parameters can't be used as vector");
    }
    _values = numbers;
}

std::vector<double> Vector::get_values() const{
    return _values;
}

void    Vector::add(Vector add){
    std::vector<double> add_values = add.get_values();
    usize_t size = add_values.size();

    if (size != _values.size()){
        throw std::runtime_error("impossible to add two vectors of different size");
    }
    for (usize_t i = 0; i < size; i++){
        _values[i] += add_values[i];
    }
}

void    Vector::sub(Vector sub){
    std::vector<double> sub_values = sub.get_values();
    usize_t size = sub_values.size();

    if (size != _values.size()){
        throw std::runtime_error("impossible to subtract two vectors of different size");
    }
    for (usize_t i = 0; i < size; i++){
        _values[i] -= sub_values[i];
    }
}

void    Vector::scl(double scalar){
    usize_t size = _values.size();
    for (usize_t i = 0; i < size; i++){
        _values[i] *= scalar;
    }
}

std::ostream& operator<<(std::ostream& os, const Vector& values)
{
    std::vector<double> vector = values.get_values();
    usize_t size = vector.size();
    for (usize_t i = 0; i < size; i++){
        os << "[" << vector[i] << "]\n";
    }
	return (os);
}
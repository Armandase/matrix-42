#include "../inc/Vector.hpp"
#include <stdexcept>

template <typename K>
Vector<K>::Vector(std::vector<K> numbers){
    if (numbers.size() < 2){
        throw std::runtime_error("the numbers given as parameters can't be used as vector");
    }
    _values = numbers;
}

template <typename K>
std::vector<K> Vector<K>::get_values() const{
    return _values;
}

template <typename K>
usize_t Vector<K>::get_size() const{
    return _values.size();
}


template <typename K>
void    Vector<K>::add(Vector add){
    std::vector<K> add_values = add.get_values();
    usize_t size = add_values.size();

    if (size != _values.size()){
        throw std::runtime_error("impossible to add two vectors of different size");
    }
    for (usize_t i = 0; i < size; i++){
        if (check_overflow(_values[i], add_values[i], '+') == true){
            throw std::runtime_error("An addition generate an overflow.");
        }
        _values[i] += add_values[i];
    }
}

template <typename K>
void    Vector<K>::sub(Vector sub){
    std::vector<K> sub_values = sub.get_values();
    usize_t size = sub_values.size();

    if (size != _values.size()){
        throw std::runtime_error("impossible to subtract two vectors of different size");
    }
    for (usize_t i = 0; i < size; i++){
        if (check_overflow(_values[i], sub_values[i], '-') == true){
            throw std::runtime_error("A subtraction generate an overflow.");
        }
        _values[i] -= sub_values[i];
    }
}

template <typename K>
void    Vector<K>::scl(K scalar){
    usize_t size = _values.size();
    for (usize_t i = 0; i < size; i++){
        if (check_overflow(_values[i], scalar, '*') == true){
            throw std::runtime_error("A multiplication generate an overflow.");
        }
        _values[i] *= scalar;
    }
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K>& values)
{
    std::vector<K> vector = values.get_values();
    usize_t size = vector.size();
    for (usize_t i = 0; i < size; i++){
        os << "[" << vector[i] << "]\n";
    }
	return (os);
}

template <typename K>
bool Vector<K>::check_overflow(K a, K b, char op){
    K result;
    if (op == '+')
        result = a + b;
    else if (op == '-')
        result = a - b;
    else if (op == '*')
        result = a * b;

    if((a > 0 && b > 0 && result < 0) 
        || (a < 0 && b < 0 && result > 0))
        return true;
    return false;
}
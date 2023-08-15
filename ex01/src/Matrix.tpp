#include "../inc/Matrix.hpp"
#include <stdexcept>

template <typename K>
Matrix<K>::Matrix(std::vector<std::vector<K> > numbers){
    usize_t rows = numbers.size();
    if (rows < 2){
        throw std::runtime_error("Wrong number of rows");
    }
    usize_t columns = numbers[0].size();
    if (columns < 2){
        throw std::runtime_error("Wrong number of columns");
    }
    for (usize_t i = 0; i < rows; i++){
        if ((numbers[i]).size() != columns){
            throw std::runtime_error("The size of the columns is not fixed");
        }
    }
    _n = rows;
    _m = columns;
    _values = numbers;
}

template <typename K>
std::vector<std::vector<K> > Matrix<K>::get_values() const{
    return _values;
}

template <typename K>
int Matrix<K>::get_rows() const{
    return _n;
}

template <typename K>
int Matrix<K>::get_columns() const{
    return _m;
}

template <typename K>
void    Matrix<K>::add(Matrix add){
    std::vector<std::vector<K> > add_values = add.get_values();
    usize_t rows_add_values = add.get_rows();
    usize_t columns_add_values = add.get_columns();
    if (rows_add_values != _n || columns_add_values != _m){
        throw std::runtime_error("impossible to add two matrices of different size");
    }
    for (usize_t i = 0; i < rows_add_values; i++){
        for (usize_t j = 0; j < columns_add_values; j++){
            if (isOverflow(_values[i][j], add_values[i][j], '+') == true){
                throw std::runtime_error("An addition generate an overflow.");
            }
           _values[i][j] += add_values[i][j];
        }
    }
}

template <typename K>
void    Matrix<K>::sub(Matrix sub){
    std::vector<std::vector<K> > sub_values = sub.get_values();
    usize_t rows_sub_values = sub.get_rows();
    usize_t columns_sub_values = sub.get_columns();
    if (rows_sub_values != _n || columns_sub_values != _m){
        throw std::runtime_error("impossible to subtract two matrices of different size");
    }
    for (usize_t i = 0; i < rows_sub_values; i++){
        for (usize_t j = 0; j < columns_sub_values; j++){
            if (isOverflow(_values[i][j], sub_values[i][j], '-') == true){
                throw std::runtime_error("A subtraction generate an overflow.");
            }
            _values[i][j] -= sub_values[i][j];
        }
    }
}

template <typename K>
void    Matrix<K>::scl(K scalar){
    for (usize_t i = 0; i < _n; i++){
        for (usize_t j = 0; j < _m; j++){
            if (isOverflow(_values[i][j], scalar, '*') == true){
                throw std::runtime_error("A multiplication generate an overflow.");
            }
            _values[i][j] *= scalar;
        }
    }
}

template <typename K>
std::ostream& operator<<(std::ostream& os, const Matrix<K>& values)
{
    std::vector<std::vector<K> > matrix = values.get_values();
    usize_t rows = values.get_rows();
    usize_t columns = values.get_columns();
    for (usize_t i = 0; i < rows; i++){
        os << "[";
        for (usize_t j = 0; j < columns; j++){
            os << matrix[i][j];
            if (j + 1 < columns)
                os << ", ";
        }
        os <<"]\n";

    }
	return (os);
}

template <typename K>
bool Matrix<K>::isOverflow(K a, K b, char op){
    K result;
    if (op == '+')
        result = a + b;
    else if (op == '-')
        result = a - b;
    else if (op == '*'){
        if (a == 0 || b == 0)
            return false;
        result = a * b;
        return (a == result / b) ? false : true;
    }

    if((a > 0 && b > 0 && result < 0) 
        || (a < 0 && b < 0 && result > 0))
        return true;
    return false;
}
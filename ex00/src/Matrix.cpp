#include "../inc/Matrix.hpp"
#include <stdexcept>

Matrix::Matrix(std::vector<std::vector<double> > numbers){
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

std::vector<std::vector<double> > Matrix::get_values() const{
    return _values;
}

int Matrix::get_rows() const{
    return _n;
}

int Matrix::get_columns() const{
    return _m;
}

void    Matrix::add(Matrix add){
    std::vector<std::vector<double> > add_values = add.get_values();
    usize_t rows_add_values = add.get_rows();
    usize_t columns_add_values = add.get_columns();
    if (rows_add_values != _n || columns_add_values != _m){
        throw std::runtime_error("impossible to add two matrices of different size");
    }
    for (usize_t i = 0; i < rows_add_values; i++)
        for (usize_t j = 0; j < columns_add_values; j++)
            _values[i][j] += add_values[i][j];
}

void    Matrix::sub(Matrix sub){
    std::vector<std::vector<double> > sub_values = sub.get_values();
    usize_t rows_sub_values = sub.get_rows();
    usize_t columns_sub_values = sub.get_columns();
    if (rows_sub_values != _n || columns_sub_values != _m){
        throw std::runtime_error("impossible to subtract two matrices of different size");
    }
    for (usize_t i = 0; i < rows_sub_values; i++)
        for (usize_t j = 0; j < columns_sub_values; j++)
            _values[i][j] -= sub_values[i][j];
}

void    Matrix::scl(double scalar){
    for (usize_t i = 0; i < _n; i++)
        for (usize_t j = 0; j < _m; j++)
            _values[i][j] *= scalar;
}

std::ostream& operator<<(std::ostream& os, const Matrix& values)
{
    std::vector<std::vector<double> > matrix = values.get_values();
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
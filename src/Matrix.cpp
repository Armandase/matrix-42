#include "../inc/Matrix.hpp"
#include <stdexcept>
#include <cmath>

Matrix::Matrix(std::vector<std::vector<K> > numbers){
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

std::vector<std::vector<K> > Matrix::get_values() const{
    return _values;
}

int  Matrix::get_rows() const{
    return _n;
}

int  Matrix::get_columns() const{
    return _m;
}

void     Matrix::add(Matrix add){
    std::vector<std::vector<K> > add_values = add.get_values();
    usize_t rows_add_values = add.get_rows();
    usize_t columns_add_values = add.get_columns();
    if (rows_add_values != _n || columns_add_values != _m){
        throw std::runtime_error("impossible to add two matrices of different size");
    }
    for (usize_t i = 0; i < rows_add_values; i++){
        for (usize_t j = 0; j < columns_add_values; j++){
           _values[i][j] += add_values[i][j];
        }
    }
}

void     Matrix::sub(Matrix sub){
    std::vector<std::vector<K> > sub_values = sub.get_values();
    usize_t rows_sub_values = sub.get_rows();
    usize_t columns_sub_values = sub.get_columns();
    if (rows_sub_values != _n || columns_sub_values != _m){
        throw std::runtime_error("impossible to subtract two matrices of different size");
    }
    for (usize_t i = 0; i < rows_sub_values; i++){
        for (usize_t j = 0; j < columns_sub_values; j++){
            _values[i][j] -= sub_values[i][j];
        }
    }
}

 void     Matrix::scl(K scalar){
    for (usize_t i = 0; i < _n; i++){
        for (usize_t j = 0; j < _m; j++){
            _values[i][j] *= scalar;
        }
    }
}

 std::vector<std::vector<K> > createMatrixWithoutRow(usize_t row,  Matrix matrix){
    std::vector<std::vector<K> > result;
    std::vector<std::vector<K> > currentMatrix = matrix.get_values();
    usize_t size = matrix.get_columns();

    for (usize_t i = 1; i < size; i++){
        std::vector<K> tmp;
        for (usize_t j = 0; j < size; j++){
            if (j == row)
                continue ;
            tmp.push_back(currentMatrix[i][j]);
        }
        result.push_back(tmp);
    }
    return (result);
}

 K  Matrix::recursive_det( Matrix matrix){
    std::vector<std::vector<K> > matrix_values = matrix.get_values();
    usize_t size = matrix.get_rows();
    if (size == 2) {
        K ad = matrix_values[0][0] * matrix_values[1][1];

        K bc = matrix_values[1][0] * matrix_values[0][1];
        return (ad - bc);
    }

    K       result = 0;
    K       tmp;
    K       cofactor;
    for (usize_t i = 0; i < size; i++){
        Matrix  smaller_matrix(createMatrixWithoutRow(i, matrix));
        tmp = recursive_det(smaller_matrix);

        cofactor = std::pow(-1, i) * matrix_values[0][i];

        result += tmp * cofactor;
    }
    return result;
}

 K    Matrix::determinant(){
    if (this->_n != this->_m){
        throw std::runtime_error("You can't compute determinant with a non square matrix");
    }
    return (recursive_det(*this));
}


Matrix&  Matrix::operator + (const  Matrix& add_overload)
{
	this->add(add_overload);
	return (*this);
}

  Matrix&  Matrix::operator - (const  Matrix& sub_overload)
{
	this->sub(sub_overload);
	return (*this);
}

  Matrix&  Matrix::operator * (const K scalar)
{
	this->scl(scalar);
	return (*this);
}

 std::ostream& operator<<(std::ostream& os, const  Matrix& values)
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
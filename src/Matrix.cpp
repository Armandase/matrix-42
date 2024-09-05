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
    _values = numbers;
}

Matrix::Matrix(const Matrix& matrix)
{
    _values = matrix.get_values();
}

Matrix Matrix::operator = (const Matrix& matrix)
{
    _values = matrix.get_values();
    return (*this);
}

std::vector<std::vector<K> > Matrix::get_values() const{
    return _values;
}

size_t  Matrix::get_rows() const{
    return this->_values.size();
}

size_t  Matrix::get_columns() const{
    if (this->_values.size() == 0)
        return 0;
    return this->_values.begin()->size();
}

void Matrix::set_specific_value (size_t i, size_t j, K value){
    if (i >= this->get_rows() || j >= this->get_columns()){
        throw std::runtime_error("impossible to set a value outside the matrix");
    }
    _values[i][j] = value;
}

void    Matrix::swap_columns(usize_t column1, usize_t column2){
    for (usize_t i = 0; i < this->get_rows(); i++){
        K tmp = this->get_specific_value(i, column1);
        this->set_specific_value(i, column1, this->get_specific_value(i, column2));
        this->set_specific_value(i, column2, tmp);
    }
}

void Matrix::swap_rows(usize_t row1, usize_t row2){
    for (usize_t i = 0; i < this->get_columns(); i++){
        K tmp = this->get_specific_value(row1, i);
        this->set_specific_value(row1, i, this->get_specific_value(row2, i));
        this->set_specific_value(row2, i, tmp);
    }
}

void     Matrix::add(Matrix add){
    std::vector<std::vector<K> > add_values = add.get_values();
    usize_t rows_add_values = add.get_rows();
    usize_t columns_add_values = add.get_columns();
    if (rows_add_values != this->get_rows() || columns_add_values != this->get_columns()){
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
    if (rows_sub_values != this->get_rows() || columns_sub_values != this->get_columns()){
        throw std::runtime_error("impossible to subtract two matrices of different size");
    }
    for (usize_t i = 0; i < rows_sub_values; i++){
        for (usize_t j = 0; j < columns_sub_values; j++){
            _values[i][j] -= sub_values[i][j];
        }
    }
}

 void     Matrix::scl(K scalar){
    for (usize_t i = 0; i < this->get_rows(); i++){
        for (usize_t j = 0; j < this->get_columns(); j++){
            _values[i][j] *= scalar;
        }
    }
}
/*
    Pour multiplier une matrice par un vecteur,
    on multiplie chaque ligne de la matrice par chaque élément du vecteur
    (ligne 1 multiplier par element 1)
*/
Vector   Matrix::mul_vec(Vector& vec){
    usize_t size = vec.get_size();
    std::vector<K> vec_values = vec.get_values();
    if (size != this->get_columns()){
        throw std::runtime_error("Size incompatible for multiplying a vector by a matrix.");
    }

    std::vector<K> numbers;
    for (usize_t j = 0; j < this->get_rows(); j++){
        numbers.push_back(_values[j][0]);
    }
    Vector result(numbers);
    result.scl(vec_values[0]);
    for (usize_t i = 1; i < size; i++){
        numbers.clear();
        for (usize_t j = 0; j < this->get_rows(); j++){
            numbers.push_back(_values[j][i]);
        }
        Vector tmp(numbers);
        tmp.scl(vec_values[i]);
        result.add(tmp);
    }
    return(result);
}

/*
    Pour multiplier deux matrices,
    il faut faire le produit scalaire de chaque ligne de la première matrice avec chaque colonne de la deuxième matrice
    (ligne 1 de M1 dot colonne 1 de M2)
    cf. https://www.mathsisfun.com/algebra/matrix-multiplying.html
*/

Matrix   Matrix::mul_mat(Matrix& matrix){
    if (this->get_columns() != matrix.get_rows()){
        throw std::runtime_error("Size incompatible for multiplying two matrices.");
    }

    Matrix result(std::vector<std::vector<K> >(this->get_rows(), std::vector<K>(matrix.get_columns(), 0)));
    Vector column(std::vector<K>(matrix.get_rows()));
    Vector row(std::vector<K>(this->get_columns()));

    for (size_t i = 0; i < this->get_rows(); i++){
        for (size_t j = 0; j < matrix.get_columns(); j++){
            for (size_t k = 0; k < this->get_columns(); k++){
                column.set_specific_value(k, matrix.get_specific_value(k, j));
                row.set_specific_value(k, this->get_specific_value(i, k));
            }
            result.set_specific_value(i, j, row.dot(column));
        }
    }

    return result;
};

/*
    La trace d'une matrice est la somme des éléments de la diagonale principale
    utile pour calculer le rang ou l'ordre d'une matrice
*/
K   Matrix::trace() const {
    if (this->get_rows() != this->get_columns()){
        throw std::runtime_error("Can't compute the trace with a non-square matrix.");
    }

    K result;
    for (usize_t i = 0; i < this->get_rows(); i++){
        if (i == 0){
            result = _values[i][i];
            continue ;
        }
        result += _values[i][i];
    }
    return (result);
}

/*
    La matrice transpose d'une matrice est obtenue en échangeant les lignes et les colonnes
*/
Matrix   Matrix::transpose() const {
    std::vector<std::vector<K> > vec_result;

    for (usize_t i = 0; i < this->get_rows(); i++){
        std::vector<K> tmp;
        for (usize_t j = 0; j < this->get_columns(); j++){
            if (i == 0){
                tmp.clear();
                tmp.push_back(_values[i][j]);
                vec_result.push_back(tmp);
                continue ;
            }
            vec_result[j].push_back(_values[i][j]);
        }
    }
    return (Matrix (vec_result));
}

int found_non_zero_column(usize_t row_start, const Matrix& matrix){
    usize_t rows = matrix.get_rows();
    usize_t columns = matrix.get_columns();
    for (usize_t i = 0; i < columns; i++){
        for (usize_t j = row_start; j < rows; j++){
            if (matrix.get_specific_value(j, i) != 0){
                return i;
            }
        }
    }
    return -1;
}

Matrix   Matrix::row_echelon_form() const {
    Matrix result(*this);

    if (result.get_rows() == 0 || result.get_columns() == 0){
        throw std::runtime_error("Can't compute the row echelon form of an empty matrix.");
    }

    // form left to right and top to bottom
    for (size_t i = 0; i < result.get_rows(); i++){
        // find the first non-zero column
        int column_non_empty = found_non_zero_column(i, result);
        // if there is just zero column, stop
        if (column_non_empty == -1)
            return result;
        // if the non-zero column is not in the diagonal change the index row
        if (column_non_empty != static_cast<int>(i))
            i = column_non_empty - 1;

        // pivot is the first non-zero element of the unprocess row
        K pivot = result.get_specific_value(i, column_non_empty);
        // if the pivot is null and there is a non-zero element in the same column, swap the rows
        if (pivot == 0.){
            size_t j = i + 1;
            while (j < result.get_rows()){
                if (result.get_specific_value(j, column_non_empty)){
                    result.swap_rows(i, j);
                    break ;
                }
                j++;
            }
            if (j == result.get_rows())
                continue ;
        }

        // normalize the row
        K factor = 1 / pivot;
        for (size_t j = 0; j < result.get_columns(); j++){
            result.set_specific_value(i, j, result.get_specific_value(i, j) * factor);
        }

        // zero the other rows
        for (size_t j = i + 1; j < result.get_rows(); j++){
            K factor_to_zero = (result.get_specific_value(j, column_non_empty)) * -1;
            for (size_t k = 0; k < result.get_columns(); k++){
                result.set_specific_value(j, k, result.get_specific_value(j, k) + factor_to_zero * result.get_specific_value(i, k));
            }
        }
    }

    return result;
}

Matrix Matrix::reduced_row_echelon_form() const{
    //get the row echelon form
    Matrix result(this->row_echelon_form());

    usize_t columns = result.get_columns();
    for (usize_t i = result.get_rows() - 1; i > 0; i--){
        int column_non_empty = found_non_zero_column(i, result);
        if (column_non_empty == -1)
            return result;  
        for (usize_t j = 0; j < i; j++){
            K factor_to_zero = (result.get_specific_value(j, column_non_empty)) * -1;
            for (usize_t k = 0; k < columns; k++){
                result.set_specific_value(j, k, result.get_specific_value(j, k) + factor_to_zero * result.get_specific_value(i, k));
            }
        }
    }
    return result;
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
    if (this->get_rows() != this->get_columns()){
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
K Matrix::get_specific_value (int i, int j) const{
    return _values[i][j];
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
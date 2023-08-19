#include "../inc/Matrix.hpp"
#include <stdexcept>
#include <cmath>

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
std::vector<std::vector<K> > createMatrixWithoutRow(usize_t row, Matrix<K> matrix){
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

template <typename K>
K Matrix<K>::recursive_det(Matrix<K> matrix){
    std::vector<std::vector<K> > matrix_values = matrix.get_values();
    usize_t size = matrix.get_rows();
    if (size == 2) {
        if (isOverflow(matrix_values[0][0], matrix_values[1][1], '*') == true)
            throw std::runtime_error("A multiplication generate an overflow.");
        K ad = matrix_values[0][0] * matrix_values[1][1];

        if (isOverflow(matrix_values[1][0], matrix_values[0][1], '*') == true)
            throw std::runtime_error("A multiplication generate an overflow.");
        K bc = matrix_values[1][0] * matrix_values[0][1];
        
        if (isOverflow(ad, bc, '-') == true)
            throw std::runtime_error("A substraction generate an overflow.");
        return (ad - bc);
    }

    K       result = 0;
    K       tmp;
    K       cofactor;
    for (usize_t i = 0; i < size; i++){
        Matrix  smaller_matrix(createMatrixWithoutRow(i, matrix));
        tmp = recursive_det(smaller_matrix);

        if (isOverflow(std::pow(-1, i), matrix_values[0][i], '*') == true)
            throw std::runtime_error("A multiplication generate an overflow.");
        cofactor = std::pow(-1, i) * matrix_values[0][i];

        if (isOverflow(tmp, cofactor, '*') == true)
            throw std::runtime_error("A multiplication generate an overflow.");
        else if (isOverflow(result, tmp * cofactor, '+') == true)
            throw std::runtime_error("An addition generate an overflow.");
        result += tmp * cofactor;
    }
    return result;
}

template <typename K>
K   Matrix<K>::determinant(){
    if (this->_n != this->_m){
        throw std::runtime_error("You can't compute determinant with a non square matrix");
    }
    return (recursive_det(*this));
}

template <typename K>
Vector<K>   Matrix<K>::mul_vec(Vector<K> vec){
    usize_t size = vec.get_size();
    std::vector<K> vec_values = vec.get_values();
    if (size != this->_m){
        throw std::runtime_error("Size incompatible for multiplying a vector by a matrix.");
    }

    std::vector<K> numbers;
    for (usize_t j = 0; j < this->_n; j++){
        numbers.push_back(_values[j][0]);
    }
    Vector<K> result(numbers);
    result.scl(vec_values[0]);
    for (usize_t i = 1; i < size; i++){
        numbers.clear();
        for (usize_t j = 0; j < _n; j++){
            numbers.push_back(_values[j][i]);
        }
        Vector<K> tmp(numbers);
        tmp.scl(vec_values[i]);
        result.add(tmp);
    }
    return(result);
}

template <typename K>
Matrix<K>   Matrix<K>::mul_mat(Matrix<K> matrix){
    if (this->_n != usize_t(matrix.get_rows()) || this->_m != usize_t(matrix.get_columns())){
        throw std::runtime_error("Size incompatible for multiplying two matrices.");
    }

    std::vector<std::vector<K> > matrix_numbers = matrix.get_values();
    std::vector<std::vector<K> > result_numbers;

    std::vector<K> numbers;
    for (usize_t j = 0; j < this->_n; j++){
        numbers.push_back(matrix_numbers[j][0]);
    }
    Vector<K> vec_tmp(numbers);
    Vector<K> multiplied_vec = mul_vec(vec_tmp);

    std::vector<K> values_multiplied_vec = multiplied_vec.get_values();
    for (usize_t i = 0; i < multiplied_vec.get_size(); i++){
        std::vector<K> tmp;
        tmp.push_back(values_multiplied_vec[i]);
        result_numbers.push_back(tmp);
    }
     
    for (usize_t i = 1; i < _m; i++){
        numbers.clear();
        for (usize_t j = 0; j < _n; j++){
            numbers.push_back(matrix_numbers[j][i]);
        }
        Vector<K> vec(numbers);
        Vector<K> multiplied_vec = mul_vec(vec);
        std::vector<K> values_multiplied_vec = multiplied_vec.get_values();
        for (usize_t i = 0; i < multiplied_vec.get_size(); i++){
            result_numbers[i].push_back(values_multiplied_vec[i]);
        }
    }
    return (Matrix (result_numbers));
};

template <typename K>
K   Matrix<K>::trace(){
    if (this->_n != this->_m){
        throw std::runtime_error("Can't compute the trace with a non-square matrix.");
    }

    K result;
    for (usize_t i = 0; i < _n; i++){
        if (i == 0){
            result = _values[i][i];
            continue ;
        }
        if (isOverflow(result, _values[i][i], '+') == true)
            throw std::runtime_error("An addition generate an overflow.");
        result += _values[i][i];
    }
    // use to compute rank or order of a matrix
    return (result);
}

template <typename K>
Matrix<K>   Matrix<K>::transpose(){
    std::vector<std::vector<K> > vec_result;

    for (usize_t i = 0; i < _n; i++){
        std::vector<K> tmp;
        for (usize_t j = 0; j < _m; j++){
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

template <typename K>
bool Matrix<K>::isOverflow(K a, K b, char op){
    K result;
    if (op == '+'){
        result = a + b;
        if((a > 0 && b > 0 && result < 0) 
            || (a < 0 && b < 0 && result > 0))
            return true;
        return false;
    }
    else if (op == '-'){
        result = a - b;
        if (result > a && b > 0)
            return true;
        else
            return false;
    }
    else if (op == '*'){
        if (a == 0 || b == 0)
            return false;
        result = a * b;
        return (a == result / b) ? false : true;
    }
    return false;
}

template <typename K>
Matrix<K>& Matrix<K>::operator + (const Matrix<K>& add_overload)
{
	this->add(add_overload);
	return (*this);
}

template <typename K>
Matrix<K>& Matrix<K>::operator - (const Matrix<K>& sub_overload)
{
	this->sub(sub_overload);
	return (*this);
}

template <typename K>
Matrix<K>& Matrix<K>::operator * (const K scalar)
{
	this->scl(scalar);
	return (*this);
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
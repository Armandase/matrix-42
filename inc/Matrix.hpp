#ifndef _MATRIX_HPP_
# define _MATRIX_HPP_

# include <vector>
# include <ostream>
#include <iostream>
# include "Vector.hpp"
#include "Complex.hpp"

# define PRECISION 1e-6

typedef long unsigned int usize_t;
typedef float K;
// typedef Complex K;

class Matrix{
    public:
        Matrix(std::vector<std::vector<K> >);
        Matrix(const Matrix& matrix);
        Matrix operator = (const Matrix& matrix);

        std::vector<std::vector<K> > get_values() const;
        K       get_specific_value (int i, int j) const;
        void    set_specific_value (size_t i, size_t j, K value);
        size_t  get_rows() const;
        size_t  get_columns() const;
        void    swap_columns(usize_t column1, usize_t column2);
        void    swap_rows(usize_t row1, usize_t row2);

        void    sub(Matrix);
        void    add(Matrix);
        void    scl(K);
        Matrix  mul_mat(Matrix& matrix);
        Vector  mul_vec(Vector& vec);
        K       trace() const;
        Matrix  transpose() const;
        Matrix  row_echelon_form() const;
        Matrix  reduced_row_echelon_form() const;
        K       determinant() const;
        Matrix  identity() const;
        int     found_non_identity_column(size_t row_start, const Matrix& matrix) const;
        Matrix  row_echelon_form_on_pair(Matrix& mirror) const;
        Matrix  inverse() const;
        usize_t rank() const;
    

        Matrix& operator + (const Matrix&); 
		Matrix& operator - (const Matrix&);
		Matrix& operator * (const K);

    private:
        K   recursive_det(Matrix matrix) const;

        std::vector<std::vector<K> > _values;
};

std::ostream& operator<<(std::ostream& os, const Matrix& values);

#endif
#pragma once

# include <vector>
# include <ostream>
#include <iostream>
# include <tuple>
# include <functional>
# include "Vector.hpp"
#include "Complex.hpp"

# define PRECISION 1e-6

typedef long unsigned int usize_t;

# ifdef COMPLEX
typedef Complex K;
# else
typedef double K;
# endif

class Matrix{
    public:
        Matrix(std::vector<std::vector<K> >);
        Matrix(size_t size_x, size_t size_y);
        Matrix(const Matrix& matrix);
        Matrix operator = (const Matrix& matrix);

        std::vector<std::vector<K> > get_values() const;
        K       get_specific_value (int i, int j) const;
        void    set_specific_value (size_t i, size_t j, K value);
        std::vector<K> get_row(int i) const;
        size_t  get_rows() const;
        size_t  get_columns() const;
        size_t  get_nb_values() const;
        void    swap_columns(usize_t column1, usize_t column2);
        void    swap_rows(usize_t row1, usize_t row2);
        void    reset();
        void    append_column(const Matrix& b);
        void    append_row(const Matrix& b);

        void    sub(Matrix);
        void    add(Matrix);
        void    scl(K);

        Vector  mul_vec(Vector& vec);
        Matrix  mul_mat(const Matrix& matrix);
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
        Matrix  kronecker_product(const Matrix& other) const;
    
        std::tuple<std::vector<Vector>, std::vector<double> > eigh() const;

        Matrix& operator + (const Matrix&); 
		Matrix& operator - (const Matrix&);
		Matrix& operator * (const K);
		Matrix operator * (const Matrix&);

    private:
        K   recursive_det(Matrix matrix) const;

        std::vector<std::vector<K> > _values;
};

std::ostream& operator<<(std::ostream& os, const Matrix& values);
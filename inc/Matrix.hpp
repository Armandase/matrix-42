#ifndef _MATRIX_HPP_
# define _MATRIX_HPP_

# include <vector>
# include <ostream>
# include "Vector.hpp"

typedef long unsigned int usize_t;
typedef float K;

class Matrix{
    public:
        Matrix(std::vector<std::vector<K> >);

        std::vector<std::vector<K> > get_values() const;
        K get_specific_value (int i, int j) const;
        void set_specific_value (size_t i, size_t j, K value);
        size_t get_rows() const;
        size_t get_columns() const;

        void    sub(Matrix);
        void    add(Matrix);
        void    scl(K);
        Matrix  mul_mat(Matrix& matrix);
        Vector  mul_vec(Vector& vec);
        K       determinant();

        Matrix& operator + (const Matrix&); 
		Matrix& operator - (const Matrix&);
		Matrix& operator * (const K);

    private:
        K   recursive_det(Matrix matrix);

        std::vector<std::vector<K> > _values;
};

std::ostream& operator<<(std::ostream& os, const Matrix& values);

#endif
#ifndef _MATRIX_HPP_
# define _MATRIX_HPP_

# include <vector>
# include <ostream>

typedef long unsigned int usize_t;
typedef float K;

class Matrix{
    public:
        Matrix(std::vector<std::vector<K> >);

        std::vector<std::vector<K> > get_values() const;
        int get_rows() const;
        int get_columns() const;

        void    sub(Matrix);
        void    add(Matrix);
        void    scl(K);
        K       determinant();

        Matrix& operator + (const Matrix&); 
		Matrix& operator - (const Matrix&);
		Matrix& operator * (const K);
    private:
        K   recursive_det(Matrix matrix);

        // rows
        usize_t _n;
        // columns
        usize_t _m;
        std::vector<std::vector<K> > _values;
};

std::ostream& operator<<(std::ostream& os, const Matrix& values);

#endif
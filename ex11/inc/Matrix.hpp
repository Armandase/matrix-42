#ifndef _MATRIX_HPP_
# define _MATRIX_HPP_

# include <vector>
# include <ostream>

typedef long unsigned int usize_t;

template <typename K>
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

        Matrix<K>& operator + (const Matrix<K>&);
		Matrix<K>& operator - (const Matrix<K>&);
		Matrix<K>& operator * (const K);
    private:
        bool isOverflow(K a, K b, char op);
        K   recursive_det(Matrix<K> matrix);

        // rows
        usize_t _n;
        // columns
        usize_t _m;
        std::vector<std::vector<K> > _values;
};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Matrix<K>& values);

#endif
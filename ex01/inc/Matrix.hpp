#ifndef _MATRIX_HPP_
# define _MATRIX_HPP_

# include <vector>
# include <ostream>

typedef long unsigned int usize_t;

class Matrix{
    public:
        Matrix(std::vector<std::vector<double> >);

        std::vector<std::vector<double> > get_values() const;
        int get_rows() const;
        int get_columns() const;

        void    sub(Matrix);
        void    add(Matrix);
        void    scl(double);
    private:
        // rows
        usize_t _n;
        // columns
        usize_t _m;
        std::vector<std::vector<double> > _values;
};

std::ostream& operator<<(std::ostream& os, const Matrix& values);

#endif
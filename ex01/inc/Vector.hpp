#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

# include <vector>
# include <ostream>

typedef long unsigned int usize_t;

class Vector{
    public:
        Vector(std::vector<double>);

        std::vector<double> get_values() const;
        usize_t get_size() const;

        void    sub(Vector);
        void    add(Vector);
        void    scl(double);
    private:
        std::vector<double> _values;
};

std::ostream& operator<<(std::ostream& os, const Vector& values);

#endif
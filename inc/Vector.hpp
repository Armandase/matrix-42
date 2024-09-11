#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

# include <vector>
# include <ostream>
# include "Complex.hpp"

typedef long unsigned int usize_t;
// typedef Complex K;
typedef float K;

class Vector{
    public:
        Vector(std::vector<K>);

        std::vector<K> get_values() const;
        usize_t get_size() const;
        void    set_values(std::vector<K>& vec);
        void    set_specific_value (size_t i, K value);

        void    sub(Vector);
        void    add(Vector);
        void    scl(K);
        // determine a quel point les vecteurs pointent dans la meme direction
        K    dot(Vector);
        K    norm_1();
        K    norm();
        K    norm_inf();

        Vector& operator + (const Vector&);
		Vector& operator - (const Vector&);
		Vector& operator * (const K);
    private:
        std::vector<K> _values;
};

std::ostream& operator<<(std::ostream& os, const Vector& values);

#endif
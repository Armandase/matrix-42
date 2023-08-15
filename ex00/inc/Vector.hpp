#ifndef _VECTOR_HPP_
# define _VECTOR_HPP_

# include <vector>
# include <ostream>

typedef long unsigned int usize_t;

template <typename K>
class Vector{
    public:
        Vector(std::vector<K>);

        std::vector<K> get_values() const;
        usize_t get_size() const;

        void    sub(Vector);
        void    add(Vector);
        void    scl(K);
    private:
        bool check_overflow(K a, K b, char op);
        
        std::vector<K> _values;
};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K>& values);

#endif
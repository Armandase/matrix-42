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
        K    dot(Vector);
        K    norm_1();
        K    norm();
        K    norm_inf();

        Vector<K>& operator + (const Vector<K>&);
		Vector<K>& operator - (const Vector<K>&);
		Vector<K>& operator * (const K);
    private:
        bool isOverflow(K a, K b, char op);
        
        std::vector<K> _values;
};

template <typename K>
std::ostream& operator<<(std::ostream& os, const Vector<K>& values);

#endif
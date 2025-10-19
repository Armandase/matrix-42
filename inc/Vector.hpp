#pragma once

# include <vector>
# include <ostream>
# include "Complex.hpp"

typedef long unsigned int usize_t;

class Matrix;

# ifdef COMPLEX
typedef Complex K;
# else
typedef double K;
# endif

class Vector{
    public:
        Vector(std::vector<K>);
        Vector(size_t size);

        std::vector<K> get_values() const;
        K get_value(size_t i) const;
        usize_t get_size() const;
        void    set_values(std::vector<K>& vec);
        void    set_specific_value (size_t i, K value);

        void    sub(Vector);
        void    add(Vector);
        void    scl(K);
        // determine a quel point les vecteurs pointent dans la meme direction
        K    dot(Vector);
        K    angle_cos(Vector &v);
        Vector   cross_product(Vector &v);
        K    norm_1();
        K    norm();
        K    norm_inf();
        K    average() const;

        K variance_population() const;
        K variance_sample() const;
        K std(bool sample=false) const;
        K covariance(const Vector& y, bool sample=false) const;
        // Matrix covariance_matrix(const Vector& vec);
        
        
        
        Vector& operator + (const Vector&);
		Vector& operator - (const Vector&);
		Vector& operator * (const K);
        private:
        // K covariance(const Vector& x, const Vector& y);
        
        std::vector<K> _values;
    };
    
std::ostream& operator<<(std::ostream& os, const Vector& values);
Matrix covariance_matrix(const std::vector<Vector>& list_vec, bool sample=false);
Vector   linear_combination(std::vector<Vector > &e_vectors, std::vector<K> &e_coefs);
K   angle_cos(Vector &u, Vector &v);
Vector   cross_product(Vector &u, Vector &v);
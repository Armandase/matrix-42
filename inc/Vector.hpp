#pragma once

# include <vector>
# include <ostream>
# include <algorithm>
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
        Vector  cross_product(Vector &v);
        Matrix  outer_product(Vector &v);
        Vector  hadamard_product(const Vector &v) const;
        K    norm_1();
        K    norm();
        K    norm_inf();
        K    average() const;
        Vector  sort() const;
        Vector  as_rank() const;
        Vector  projection(const Vector& a);
        Vector  rotation2d(double theta, bool degre=false);
        Vector  rotation3d(double theta, const Vector& axis, bool degre=false);

        K variance_population() const;
        K variance_sample() const;
        K std(bool sample=false) const;
        K covariance(const Vector& y, bool sample=false) const;
        K pearson_correlation(const Vector& y) const;
        K spearman_correlation(const Vector& y) const;
        K mahalanobis_distance(const Vector& y)const;

        
        Vector& operator + (const Vector&);
		Vector& operator - (const Vector&);
		Vector& operator * (const K);
        K& operator[](usize_t index);
        const K& operator[](usize_t index) const;
        private:
            std::vector<K> _values;
    };
    
std::ostream& operator<<(std::ostream& os, const Vector& values);
Matrix covariance_matrix(const std::vector<Vector>& list_vec, bool sample=false);
Vector   linear_combination(std::vector<Vector > &e_vectors, std::vector<K> &e_coefs);
K   angle_cos(Vector &u, Vector &v);
Vector   cross_product(Vector &u, Vector &v);
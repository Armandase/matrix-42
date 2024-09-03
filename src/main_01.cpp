#include <iostream>

#include "../inc/Vector.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"

// Each vector is mutilpled by it corresponding coefficients
// The result is the sum of every vector
// And the result's vector start with the first vector and end at the sum of every vector
Vector   linear_combination(std::vector<Vector > &e_vectors, std::vector<K> &e_coefs){
    if (e_vectors.empty()){
        throw std::runtime_error("Vector's array provided as input is empty.");
    }
    usize_t nb_vector = e_vectors.size();
    usize_t vec_size = e_vectors[0].get_size();
    if (nb_vector != e_coefs.size()){
        throw std::runtime_error("Arrays provided as input are not of the same size.");
    }
    for (usize_t i = 0; i < nb_vector; i++){
        if (vec_size != e_vectors[i].get_size()){
            throw std::runtime_error("Vectors provided as input are not of the same size.");
        }
        e_vectors[i].scl(e_coefs[i]);
        if (i > 0){
            e_vectors[0].add(e_vectors[i]);
        }
    }
    return (e_vectors[0]);
}

int main(void) {
    // VECTOR
    std::cout << "LINEAR COMBINATION: \n";
    try {
        {
            std::vector<K> vec_e1 = {1., 0., 0.};
            std::vector<K> vec_e2 = {0., 1., 0.};
            std::vector<K> vec_e3 = {0., 0., 1.};

            Vector e1(vec_e1);
            Vector e2(vec_e2);
            Vector e3(vec_e3);

            std::vector<Vector > e_vectors = {e1, e2, e3};
            std::vector<K> e_coefs = {10., -2., 0.5};
            std::cout << UNDERLINE <<"EXEMPLE 00:" << END << std::endl;
            std::cout << "Initials vectors: " << std::endl;
            for (auto &vec : e_vectors)
                std::cout << vec << std::endl;
            std::cout << "Coefficients: " << std::endl;
            for (auto &coef : e_coefs)
                std::cout << coef << std::endl;
            std::cout << BOLD << "Linear combination:\n" << END << linear_combination(e_vectors, e_coefs) << std::endl;
        }
        {
            std::cout << UNDERLINE << "EXEMPLE 01:" << END << std::endl;
            std::vector<K> vec_v1 = {1., 2., 3.};
            std::vector<K> vec_v2 = {0., 10., -100.};
            Vector v1(vec_v1);
            Vector v2(vec_v2);
            std::vector<Vector   > v_vectors = {v1, v2};
            std::vector<K> v_coefs = {10., -2.};
            std::cout << "Initials vectors: " << std::endl;
            for (auto &vec : v_vectors)
                std::cout << vec << std::endl;
            std::cout << "Coefficients: " << std::endl;
            for (auto &coef : v_coefs)
                std::cout << coef << std::endl;
            std::cout << BOLD << "Linear combination:\n" << END << linear_combination(v_vectors, v_coefs) << std::endl;
        }

    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
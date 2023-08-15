#include <iostream>

#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"

template <typename K>
Vector<K>   linear_combination(std::vector<Vector<K> > &e_vectors, std::vector<K> &e_coefs){
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
        std::vector<float> vec_e1 = {1., 0., 0.};
        std::vector<float> vec_e2 = {0., 1., 0.};
        std::vector<float> vec_e3 = {0., 0., 1.};
        std::vector<float> vec_v1 = {1., 2., 3.};
        std::vector<float> vec_v2 = {0., 10., -100.};

        Vector e1(vec_e1);
        Vector e2(vec_e2);
        Vector e3(vec_e3);
        Vector v1(vec_v1);
        Vector v2(vec_v2);

        std::vector<Vector<float> > e_vectors = {e1, e2, e3};
        std::vector<float> e_coefs = {10., -2., 0.5};
        std::cout << "First one:\n" << linear_combination<float>(e_vectors, e_coefs) << std::endl;

        std::vector<Vector<float> > v_vectors = {v1, v2};
        std::vector<float> v_coefs = {10., -2.};
        std::cout << "Second:\n" << linear_combination<float>(v_vectors, v_coefs) << std::endl;

    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
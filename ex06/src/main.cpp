#include <iostream>

#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"

template <typename K>
Vector<K>   cross_product(Vector<K> &u, Vector<K> &v){
    if (u.get_size() != 3 || u.get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a wrong size");
    }
    return ();
}

int main(void) {
    std::cout << "COSINE: \n";
    try {
        {
            std::vector<float> vec_u = {0., 0., 1.};
            std::vector<float> vec_v = {1., 0., 0.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << cross_product(u, v) << std::endl;
        }
        {
            std::vector<float> vec_u = {1., 2., 3.};
            std::vector<float> vec_v = {4., 5., 6.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << cross_product(u, v) << std::endl;
        }
        {
            std::vector<float> vec_u = {4., 2., -3.};
            std::vector<float> vec_v = {-2., -5., 16.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << cross_product(u, v) << std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
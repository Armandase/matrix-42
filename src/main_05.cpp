#include <iostream>

#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"

template <typename K>
float   angle_cos(Vector<K> &u, Vector<K> &v){
    if (u.get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a different size");
    }

    K dot = u.dot(v);
    float u_norm = u.norm();
    float v_norm = v.norm();
    
    if (u_norm == 0 || v_norm == 0){
        throw std::runtime_error("A vector provided has a null norm");
    }
    return (dot / (u_norm * v_norm));
}

int main(void) {
    std::cout << "COSINE: \n";
    try {
        {
            std::vector<float> vec_u = {1., 0.};
            std::vector<float> vec_v = {1., 0.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << angle_cos(u, v) << std::endl;
        }
        {
            std::vector<float> vec_u = {1., 0.};
            std::vector<float> vec_v = {0., 1.};
            Vector u(vec_u);
            Vector v(vec_v);
            
            std::cout << angle_cos(u, v) << std::endl;
        }
        {
            std::vector<float> vec_u = {-1., 1.};
            std::vector<float> vec_v = {1., -1.};
            Vector u(vec_u);
            Vector v(vec_v);
            
            std::cout << angle_cos(u, v) << std::endl;
        }
        {
            std::vector<float> vec_u = {2., 1.};
            std::vector<float> vec_v = {4., 2.};
            Vector u(vec_u);
            Vector v(vec_v);
            
            std::cout << angle_cos(u, v) << std::endl;
        }
        {
            std::vector<float> vec_u = {1., 2., 3.};
            std::vector<float> vec_v = {4., 5., 6.};
            Vector u(vec_u);
            Vector v(vec_v);
            
            std::cout << angle_cos(u, v) << std::endl;
        }
        
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
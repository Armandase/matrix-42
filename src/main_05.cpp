#include <iostream>

#include "../inc/Vector.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"
/*
cos(θ) = 1 : colinéaires et pointent dans la même direction (angle de 0°).
cos⁡(θ) = 0 : orthogonaux (angle de 90°).
cos(θ) = −1: colinéaires mais pointent dans des directions opposées (angle de 180°).
*/
K   angle_cos(Vector &u, Vector &v){
    if (u.get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a different size");
    }

    K dot = u.dot(v);
    K u_norm = u.norm();
    K v_norm = v.norm();
    
    if (u_norm == 0 || v_norm == 0){
        throw std::runtime_error("A vector provided has a null norm");
    }
    return (dot / (u_norm * v_norm));
}

int main(void) {
    std::cout << UNDERLINE << "COSINE: \n" << END;
    try {
        {
            std::vector<K> vec_u = {10., 0.};
            std::vector<K> vec_v = {10., 0.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << "Vector u: \n" << u;
            std::cout << "Vector v: \n" << v;
            std::cout << "Cosine angle: " << angle_cos(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {10., 0.};
            std::vector<K> vec_v = {0., 10.};
            Vector u(vec_u);
            Vector v(vec_v);
            
            std::cout << "Vector u: \n" << u;
            std::cout << "Vector v: \n" << v;
            std::cout << "Cosine angle: " << angle_cos(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {10., 0.};
            std::vector<K> vec_v = {-10., 0.};
            Vector u(vec_u);
            Vector v(vec_v);
            
            std::cout << "Vector u: \n" << u;
            std::cout << "Vector v: \n" << v;
            std::cout << "Cosine angle: " << angle_cos(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {1., 2., 3.};
            std::vector<K> vec_v = {4., 5., 6.};
            Vector u(vec_u);
            Vector v(vec_v);
            
            std::cout << "Vector u: \n" << u;
            std::cout << "Vector v: \n" << v;
            std::cout << "Cosine angle: " << angle_cos(u, v) << "\n" << std::endl;
        }
        
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
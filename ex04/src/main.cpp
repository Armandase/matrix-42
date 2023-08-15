#include <iostream>

#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"

int main(void) {
    std::cout << "NORM: \n";
    try {
        {
            std::vector<float> vec_u = {0., 0., 0.};
            Vector u(vec_u);
            std::cout << u.norm_1() << ", ";
            std::cout << u.norm() << ", ";
            std::cout << u.norm_inf() << std::endl;
        }
        {
            std::vector<float> vec_u = {1., 2., 3.};
            Vector u(vec_u);
            std::cout << u.norm_1() << ", ";
            std::cout << u.norm() << ", ";
            std::cout << u.norm_inf() << std::endl;
        }
        {
            std::vector<float> vec_u = {-1., -2.};
            Vector u(vec_u);
            std::cout << u.norm_1() << ", ";
            std::cout << u.norm() << ", ";
            std::cout << u.norm_inf() << std::endl;
        }
        
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
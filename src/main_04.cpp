#include <iostream>

#include "../inc/Vector.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"

int main(void) {
    std::cout << UNDERLINE << "NORM: \n" << END;
    try {
        {
            std::vector<K> vec_u = {0., 0., 0.};
            Vector u(vec_u);
            std::cout << "Vector: \n" << u;
            std::cout << "L1 norm: " << u.norm_1() << std::endl;
            std::cout << "L2 norm: " << u.norm() << std::endl;;
            std::cout << "∞-norm: " << u.norm_inf() << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {1., 2., 3.};
            Vector u(vec_u);
            std::cout << "Vector: \n" << u;
            std::cout << "L1 norm: " << u.norm_1() << std::endl;
            std::cout << "L2 norm: " << u.norm() << std::endl;;
            std::cout << "∞-norm: " << u.norm_inf() << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {-1., -2.};
            Vector u(vec_u);
            std::cout << "Vector: \n" << u;
            std::cout << "L1 norm: " << u.norm_1() << std::endl;
            std::cout << "L2 norm: " << u.norm() << std::endl;;
            std::cout << "∞-norm: " << u.norm_inf() << "\n" << std::endl;
        }
        
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
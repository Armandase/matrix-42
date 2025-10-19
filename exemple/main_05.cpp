#include <iostream>

#include "../inc/Vector.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"

int main(void) {
    std::cout << UNDERLINE << "COSINE: \n" << END;
    try {
        {
            std::vector<K> vec_u = {1., 0.};
            std::vector<K> vec_v = {1., 0.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << "Vector u: \n" << u;
            std::cout << "Vector v: \n" << v;
            std::cout << "Cosine angle: " << angle_cos(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {1., 0.};
            std::vector<K> vec_v = {0., 1.};
            Vector u(vec_u);
            Vector v(vec_v);
            
            std::cout << "Vector u: \n" << u;
            std::cout << "Vector v: \n" << v;
            std::cout << "Cosine angle: " << angle_cos(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {-1., 1.};
            std::vector<K> vec_v = {1., -1.};
            Vector u(vec_u);
            Vector v(vec_v);
            
            std::cout << "Vector u: \n" << u;
            std::cout << "Vector v: \n" << v;
            std::cout << "Cosine angle: " << angle_cos(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {2., 1.};
            std::vector<K> vec_v = {4., 2.};
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
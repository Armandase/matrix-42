#include <iostream>

#include "../inc/Vector.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"

int main(void) {
    std::cout << BOLD << "DOT PRODUCT: \n" << END;
    try {
        {
            std::vector<K> vec_u = {0., 0.};
            std::vector<K> vec_v = {1., 1.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << "Vec 1\n" << u << "Vec 2\n" << v << "Result" << u.dot(v) << std::endl;
        }
        {
            std::vector<K> vec_u = {1., 1.};
            std::vector<K> vec_v = {1., 1.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << "Vec A\n" << u << "Vec B\n" << v << "Result: " << u.dot(v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {-1.52, 1.98};
            std::vector<K> vec_v = {4., 0.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << "Vec A\n" << u << "Vec B\n" << v << "Result: " << u.dot(v) << "\n" << std::endl;
        }
        {
            std::vector<float> vec_u = {1., 1.};
            std::vector<float> vec_v = {-1., 1.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << "Vec A\n" << u << "Vec B\n" << v << "Result: " << u.dot(v) << "\n" << std::endl;
        }
        
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
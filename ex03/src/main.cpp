#include <iostream>

#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"

int main(void) {
    std::cout << "DOT PRODUCT: \n";
    try {
        {
            std::vector<float> vec_u = {0., 0.};
            std::vector<float> vec_v = {1., 1.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << u.dot(v) << std::endl;
        }
        {
            std::vector<float> vec_u = {1., 1.};
            std::vector<float> vec_v = {1., 1.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << u.dot(v) << std::endl;
        }
        {
            std::vector<float> vec_u = {-1., 6.};
            std::vector<float> vec_v = {3., 2.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << u.dot(v) << std::endl;
        }
        {
            std::vector<float> vec_u = {1., 1.};
            std::vector<float> vec_v = {-1., 1.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << "When the numbers returned is 0, Vectors are perpendicular:\n" 
            << u.dot(v) << std::endl;
        }
        
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
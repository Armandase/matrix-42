#include <iostream>

#include "../inc/Vector.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"

int main(void) {
    std::cout << UNDERLINE<<"CROSS PRODUCT: \n" << END;
    try {
        {
            std::vector<K> vec_u = {0., 0., 1.};
            std::vector<K> vec_v = {1., 0., 0.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << "Vector U\n" << u << "Vector V\n" << v << "Result\n" << cross_product(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {1., 2., 3.};
            std::vector<K> vec_v = {4., 5., 6.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << "Vector U\n" << u << "Vector V\n" << v << "Result\n" << cross_product(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {4., 2., -3.};
            std::vector<K> vec_v = {-2., -5., 16.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << "Vector U\n" << u << "Vector V\n" << v << "Result\n" << cross_product(u, v) << "\n" << std::endl;
            std::cout << "Dot product of the result with vector u: " << cross_product(u, v).dot(u) << std::endl;
            std::cout << "Dot product of the result with vector v: " << cross_product(u, v).dot(v) << std::endl;
            std::cout << "Dot product should be 0 if the vectors are perpendicular" << std::endl;
        }
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
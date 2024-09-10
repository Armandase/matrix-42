#include <iostream>

#include "../inc/Matrix.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"

int main(void) {
    std::cout << UNDERLINE << "TRACE: \n" << END;
    try {
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., 0.},
                {0., 1.},
            };
            Matrix u(matrix_u);
            std::cout << "Matrix U\n" << u << "Trace\n" << u.trace() << "\n" << std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {2., -5., 0.},
                {4., 3., 7.},
                {-2., 3., 4.},
            };
            Matrix u(matrix_u);
            std::cout << "Matrix U\n" << u << "Trace\n" << u.trace() << "\n" << std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {-2., -8., 4.},
                {1., -23., 4.},
                {0., 6., 4.},
            };
            Matrix u(matrix_u);
            std::cout << "Matrix U\n" << u << "Trace\n" << u.trace() << "\n" << std::endl;
        }
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
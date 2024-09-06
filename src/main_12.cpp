#include <iostream>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "INVERSE: \n";
    try {
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., 0., 0.},
                {0., 1., 0.},
                {0., 0., 1.},
            };
            Matrix u(matrix_u);
            
            std::cout << "Matrix U\n" << u << "Inverse\n" << u.inverse() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {2., 0., 0.},
                {0., 2., 0.},
                {0., 0., 2.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Inverse\n" << u.inverse() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {8., 5., -2.},
                {4., 7., 20.},
                {7., 6., 1.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Inverse\n" << u.inverse() << "\n"<< std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
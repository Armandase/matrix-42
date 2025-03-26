#include <iostream>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "DETERMINANT: \n";
    try {
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., -1.},
                {-1., 1.},
            };
            Matrix u(matrix_u);
            
            std::cout << "Matrix U\n" << u << "Determinant\n" << u.determinant() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {2., 0., 0.},
                {0., 2., 0.},
                {0., 0., 2.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Determinant\n" << u.determinant() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {8., 5., -2.},
                {4., 7., 20.},
                {7., 6., 1.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Determinant\n" << u.determinant() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {8., 5., -2., 4.},
                {4., 2.5, 20., 4.},
                {8., 5., 1., 4.},
                {28., -4., 17., 1.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Determinant\n" << u.determinant() << "\n"<< std::endl;
        }
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
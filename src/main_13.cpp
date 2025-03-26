#include <iostream>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "RANK: \n";
    try {
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., 0., 0.},
                {0., 1., 0.},
                {0., 0., 1.},
            };
            Matrix u(matrix_u);
            
            std::cout << "Matrix U\n" << u << "Rank\n" << u.rank() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., 2., 0., 0.},
                {2., 4., 0., 0.},
                {-1., 2., 1., 1.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Rank\n" << u.rank() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {8., 5., -2.},
                {4., 7., 20.},
                {7., 6., 1.},
                {21., 18., 7.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Rank\n" << u.rank() << "\n"<< std::endl;
        }
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
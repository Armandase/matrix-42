#include <iostream>

#include "../inc/Matrix.hpp"
#include "../src/Matrix.tpp"

int main(void) {
    std::cout << "Inverse: \n";
    try {
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 0., 0.},
                {0., 1., 0.},
                {0., 0., 1.},
            };
            Matrix u(matrix_u);

            std::cout << u.inverse() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {2., 0., 0.},
                {0., 2., 0.},
                {0., 0., 2.},
            };
            Matrix u(matrix_u);

            std::cout << u.inverse() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {8., 5., -2.},
                {4., 7., 20.},
                {7., 6., 1.},
            };
            Matrix u(matrix_u);

            std::cout << u.inverse() << std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
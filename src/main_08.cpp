#include <iostream>

#include "../inc/Matrix.hpp"
#include "../src/Matrix.tpp"

int main(void) {
    std::cout << "Trace: \n";
    try {
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 0.},
                {0., 1.},
            };
            Matrix u(matrix_u);

            std::cout << u.trace() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {2., -5., 0.},
                {4., 3., 7.},
                {-2., 3., 4.},
            };
            Matrix u(matrix_u);

            std::cout << u.trace() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {-2., -8., 4.},
                {1., -23., 4.},
                {0., 6., 4.},
            };
            Matrix u(matrix_u);

            std::cout << u.trace() << std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
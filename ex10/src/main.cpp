#include <iostream>

#include "../inc/Matrix.hpp"
#include "../src/Matrix.tpp"

int main(void) {
    std::cout << "Trace: \n";
    try {
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 0., 0.},
                {0., 1., 0.},
                {0., 0., 1.},
            };
            Matrix u(matrix_u);

            std::cout << u.row_echelon() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 2.,},
                {3., 4.,},
            };
            Matrix u(matrix_u);

            std::cout << u.row_echelon() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 2.,},
                {2., 4.,}
            };
            Matrix u(matrix_u);

            std::cout << u.row_echelon() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {8., 5., -2., 4., 28.},
                {4., 2.5, 20., 4., -4.},
                {8., 5., 1., 4., 17.},
            };
            Matrix u(matrix_u);

            std::cout << u.row_echelon() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 2.},
                {2., 3.},
                {2., 5.},
                {-1., -11.},
            };
            Matrix u(matrix_u);

            std::cout << u.row_echelon() << std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
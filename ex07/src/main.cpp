#include <iostream>

#include "../inc/Matrix.hpp"
#include "../src/Matrix.tpp"
#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"

int main(void) {
    std::cout << "Determinant: \n";
    try {
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 0.},
                {0., 1.},
            };
            std::vector<float> vec_v = {4., 2.};
            Matrix u(matrix_u);
            Vector v(vec_v);

            std::cout << u.mul_vec(v) << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {2., 0.},
                {0., 2.},
            };
            std::vector<float> vec_v = {4., 2.};
            Matrix u(matrix_u);
            Vector v(vec_v);

            std::cout << u.mul_vec(v) << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {2., -2.},
                {-2., 2.},
            };
            std::vector<float> vec_v = {4., 2.,};
            Matrix u(matrix_u);
            Vector v(vec_v);

            std::cout << u.mul_vec(v) << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 0.},
                {0., 1.},
            };
            std::vector<std::vector<float> > matrix_v = {
                {1., 0.},
                {0., 1.},
            };
            Matrix u(matrix_u);
            Matrix v(matrix_v);

            std::cout << u.mul_mat(v) << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 0.},
                {0., 1.},
            };
            std::vector<std::vector<float> > matrix_v = {
                {2., 1.},
                {4., 2.},
            };
            Matrix u(matrix_u);
            Matrix v(matrix_v);

            std::cout << u.mul_mat(v) << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {3., -5.},
                {6., 8.},
            };
            std::vector<std::vector<float> > matrix_v = {
                {2., 1.},
                {4., 2.},
            };
            Matrix u(matrix_u);
            Matrix v(matrix_v);

            std::cout << u.mul_mat(v) << std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
#include <iostream>

#include "../inc/Matrix.hpp"
#include "../inc/Vector.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"

int main(void) {
    std::cout << UNDERLINE << "MATRIX MULTIPLICATION: \n" << END;
    try {
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., 0.},
                {0., 1.},
            };
            std::vector<K> vec_v = {4., 2.};
            Matrix u(matrix_u);
            Vector v(vec_v);
            
            std::cout << "Matrix U\n" << u << "Vector V\n" << v << "Result\n" << u.mul_vec(v) << std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {2., 0.},
                {0., 2.},
            };
            std::vector<K> vec_v = {4., 2.};
            Matrix u(matrix_u);
            Vector v(vec_v);

            std::cout << "Matrix U\n" << u << "Vector V\n" << v << "Result\n" << u.mul_vec(v) << std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {2., -2.},
                {-2., 2.},
            };
            std::vector<K> vec_v = {4., 2.,};
            Matrix u(matrix_u);
            Vector v(vec_v);

            std::cout << "Matrix U\n" << u << "Vector V\n" << v << "Result\n" << u.mul_vec(v) << std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., 0.},
                {0., 1.},
            };
            std::vector<std::vector<K> > matrix_v = {
                {1., 0.},
                {0., 1.},
            };
            Matrix u(matrix_u);
            Matrix v(matrix_v);

            std::cout << "Matrix U\n" << u << "Matrix V\n" << v << "Result\n" << u.mul_mat(v) << std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., 0.},
                {0., 1.},
            };
            std::vector<std::vector<K> > matrix_v = {
                {2., 1.},
                {4., 2.},
            };
            Matrix u(matrix_u);
            Matrix v(matrix_v);

            std::cout << "Matrix U\n" << u << "Matrix V\n" << v << "Result\n" << u.mul_mat(v) << std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {3., -5.},
                {6., 8.},
            };
            std::vector<std::vector<K> > matrix_v = {
                {2., 1.},
                {4., 2.},
            };
            Matrix u(matrix_u);
            Matrix v(matrix_v);

            std::cout << "Matrix U\n" << u << "Matrix V\n" << v << "Result\n" << u.mul_mat(v) << std::endl;
        }
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., 2., 3.},
                {4., 5., 6.},
            };
            std::vector<std::vector<K> > matrix_v = {
                {7., 8.},
                {9., 10.},
                {11., 12.},
            };
            Matrix u(matrix_u);
            Matrix v(matrix_v);

            std::cout << "Matrix U\n" << u << "Matrix V\n" << v << "Result\n" << u.mul_mat(v) << std::endl;
        }
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
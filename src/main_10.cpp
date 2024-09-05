#include <iostream>

#include "../inc/Matrix.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"

int main(void) {
    std::cout << UNDERLINE  << "REDUCED ROW ECHELON FORM: \n" << END;
    try {
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 0., 0.},
                {0., 1., 0.},
                {0., 0., 1.},
            };
            Matrix u(matrix_u);
            std::cout << "Matrix U\n" << u << "Reduced Row Echelon\n" << u.reduced_row_echelon_form() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 2.},
                {3., 4.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Reduced Row Echelon\n" << u.reduced_row_echelon_form() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., 2.},
                {2., 4.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Reduced Row Echelon\n" << u.reduced_row_echelon_form() << "\n"<< std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {8., 5., -2., 4., 28.},
                {4., 2.5, 20., 4., -4.},
                {8., 5., 1., 4., 17.},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Row Echelon\n" << u.reduced_row_echelon_form() << "\n"<< std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
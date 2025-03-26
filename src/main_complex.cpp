#include <iostream>

#include "../inc/Matrix.hpp"

#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define END "\033[0m"

int main(void) {
    std::cout << "COMPLEX: \n";
    try {
        Complex c1(4., 6.);
        Complex c2(-8., 3.);

        std::cout << "c1: " << c1 << std::endl;
        std::cout << "c2: " << c2 << std::endl;
        std::cout << "c1 / c2: " << c1 / c2 << std::endl;
        std::cout << "Result should be: -0.19178 + 0.82191i\n";
        std::cout << "c1 * c2: " << c1 * c2 << std::endl;
        std::cout << "Result should be: -50 - 36i\n";
        std::cout << "c1 + c2: " << c1 + c2 << std::endl;
        std::cout << "Result should be: -4 + 9i\n";
        std::cout << "c1 - c2: " << c1 - c2 << std::endl;
        std::cout << "Result should be: 12 + 3i\n";
        std::cout << "c1 == c2: " << (c1 == c2) << std::endl;
        std::cout << "Result should be: 0\n";
        std::cout << "c1 != c2: " << (c1 != c2) << std::endl;
        std::cout << "Result should be: 1\n";
        std::cout << "c1 * 3: " << c1 * 3 << std::endl;
        std::cout << "Result should be: 12 + 18i\n";
        std::cout << "c1 + 3: " << c1 + 3 << std::endl;
        std::cout << "Result should be: 7 + 6i\n";
        {
            std::vector<std::vector<K> > matrix_u = {
                {{1.,  1.}, {0., 0.}, {0., 0.}},
                {{0., 0.}, {1., 1.},  {0., 0.}},
                {{0., 0.}, {0., 0.}, {1., 1.}},
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
                {{8.}, {5.}, {-2.}},
                {{4.}, {7.}, {20}},
                {{7.}, {6.}, {1.}},
                {{21.}, {18.}, {7.}},
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
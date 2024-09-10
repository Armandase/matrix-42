#include <iostream>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "RANK: \n";
    // try {
        // Complex c1(1., 0.);
        // Complex c2(0., 2.);

        // std::cout << "c1: " << c1 << std::endl;
        // std::cout << "c2: " << c2 << std::endl;
        // std::cout << "c1 / c2: " << c1 / c2 << std::endl;
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
            // std::vector<std::vector<K> > matrix_u = {
            //     {{8., 8.}, {5., 5.}, {-2., -2.}},
            //     {{4., 4.}, {7., 7.}, {20., 20}},
            //     {{7., 7.}, {6., 6.}, {1., 1.}},
            //     {{21., 21.}, {18., 18.}, {7., 7.}},
            // };
            std::vector<std::vector<K> > matrix_u = {
                {{8.}, {5.}, {-2.}},
                {{4.}, {7.}, {20}},
                {{7.}, {6.}, {1.}},
                {{21.}, {18.}, {7.}},
            };
            Matrix u(matrix_u);

            std::cout << "Matrix U\n" << u << "Rank\n" << u.rank() << "\n"<< std::endl;
        }
    // } catch (std::exception& e){
    //     std::cout << e.what() << std::endl; 
    //     return (1);
    // }
    
    return (0);
}
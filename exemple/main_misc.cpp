#include <iostream>
#include <iomanip>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "Misc: \n";
    // try {
        // {
        //     std::vector<std::vector<K> > mat_a = {
        //         {2.5,  2.4,  0.5, 5.5,  4.4,  6.5},
        //         {0.5,  0.7, -0.1, 1.5,  1.7,  0.9},
        //         {2.2,  2.9,  0.3, 4.2,  4.9,  3.3},
        //         {1.9,  2.2,  0.4, 3.9,  4.2,  3.4},
        //         {3.1,  3.0,  0.5, 5.1,  5.0,  6.5},
        //         {2.3,  2.7,  0.6, 4.3,  4.7,  5.6},
        //         {2,    1.6, -0.1, 3.8,  3.2,  4.8},
        //     };
        //     Matrix a(mat_a);

        //     std::cout << "Matrix a\n" << a << "\n";
        //     // std::cout << a.PCA() << "\n"<< std::endl;
        //     a.PCA();
        //     // a.eigen();
        // }
        {
            std::vector<std::vector<K> > mat_a = {
                {3, 5, 7},
                {2, 9, 1},
                {9, 0, 6}
            };
            Matrix a(mat_a);

            std::cout << "Matrix a\n" << a << "\n";
            // std::cout << a.PCA() << "\n"<< std::endl;
            auto qr = a.qr_decomposition();
            std::cout << "Q:" << qr.first << "\n R:" << qr.second << std::endl; 
            std::cout << "A:" << qr.first * qr.second << std::endl; 
            // a.eigen();
        }

    // } catch (std::exception& e){
    //     std::cout << e.what() << std::endl; 
    //     return (1);
    // }
    
    return (0);
}
#include <iostream>
#include <iomanip>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "Misc: \n";
    // try {
        // {
        //     // orthogonalization test
        //     std::vector<std::vector<K> > mat_a = {
        //         {2.5,  2.4,  0.5},
        //         {0.5,  0.7, -0.1},
        //         {2.2,  2.9,  0.3},
        //     };
        //     Matrix a(mat_a);

        //     std::cout << "Vec a\n" << a << "gram schmidt\n" << a.gramSchmidt() << "\n"<< std::endl;
        //     Matrix gram = a.gramSchmidt();
        //     auto res1 = Vector(gram.get_row(0));
        //     auto res2 = Vector(gram.get_row(1));
        //     auto res3 = Vector(gram.get_row(2));
            
        //     std::cout << std::fixed << std::setprecision(5) << a;
        //     std::cout << "Row 1 & 2: " << res1.dot(res2) << "\n";
        //     std::cout << "Row 1 & 3: " << res1.dot(res3) << "\n";
        //     std::cout << "Row 2 & 3: " << res2.dot(res3) << std::endl;
        //     // a.eigen();
        // }
        {
            std::vector<std::vector<K> > mat_a = {
                {2.5,  2.4,  0.5, 5.5,  4.4,  6.5},
                {0.5,  0.7, -0.1, 1.5,  1.7,  0.9},
                {2.2,  2.9,  0.3, 4.2,  4.9,  3.3},
                {1.9,  2.2,  0.4, 3.9,  4.2,  3.4},
                {3.1,  3.0,  0.5, 5.1,  5.0,  6.5},
                {2.3,  2.7,  0.6, 4.3,  4.7,  5.6},
                {2,    1.6, -0.1, 3.8,  3.2,  4.8},
            };
            Matrix a(mat_a);

            std::cout << "Matrix a\n" << a << "\n";
            // std::cout << a.PCA() << "\n"<< std::endl;
            a.PCA();
            // a.eigen();
        }

    // } catch (std::exception& e){
    //     std::cout << e.what() << std::endl; 
    //     return (1);
    // }
    
    return (0);
}
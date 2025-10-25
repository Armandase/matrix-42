#include <iostream>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "Misc: \n";
    // try {
        // {
        //     std::vector<K>vec_a = {
        //         {1., 2., 3., 4.},
        //     };
        //     Vector a(vec_a);

        //     Vector b(
        //         {5., 6., 7., 8.}
        //     );
            
        //     std::cout << "Vec a\n" << a << "outer\n" << a.outer_product(b) << "\n"<< std::endl;
        // }
        // {
        //     std::vector<K>vec_a = {
        //         {2., 1.},
        //     };
        //     Vector a(vec_a);

        //     double theta =  90;
        //     std::cout << "Vec a\n" << a << "outer\n" << a.rotation(theta, true) << "\n"<< std::endl;
        // }
        {
            std::vector<std::vector<K> > matrix_u = {
                {1., 2.},
                {2., 4.},
            };
            Matrix u(matrix_u);

            std::vector<std::vector<K> > matrix_v = {
                {1., 2.},
                {2., 4.},
                {5., 6.},
            };
            Matrix v(matrix_v);
            std::cout << "Matrix U\n" << u << "\n"<< std::endl;
            std::cout << "Kronecker\n" << u.kronecker_product(v) << "\n"<< std::endl;
        }

    // } catch (std::exception& e){
    //     std::cout << e.what() << std::endl; 
    //     return (1);
    // }
    
    return (0);
}
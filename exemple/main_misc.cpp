#include <iostream>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "eigen values & eigen vectors: \n";
    try {
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
        {
            std::vector<K>vec_a = {
                {2., 1.},
            };
            Vector a(vec_a);

            double theta =  90;
            std::cout << "Vec a\n" << a << "outer\n" << a.rotation(theta, true) << "\n"<< std::endl;
        }
        // {
        //     std::vector<std::vector<K> > matrix_u = {
        //         {1., 2., 0., 0.},
        //         {2., 4., 0., 0.},
        //         {-1., 2., 1., 1.},
        //     };
        //     Matrix u(matrix_u);

        //     std::cout << "Matrix U\n" << u << "Rank\n" << u.rank() << "\n"<< std::endl;
        // }

    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
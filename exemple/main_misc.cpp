#include <iostream>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "eigen values & eigen vectors: \n";
    try {
        {
            std::vector<K>vec_u = {
                {3., 1.},
            };
            Vector u(vec_u);

            Vector v({1., 3.});
            
            std::cout << "Vec U\n" << u << "proj\n" << u.projection(v) << "\n"<< std::endl;
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
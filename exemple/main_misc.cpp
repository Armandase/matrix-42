#include <iostream>

#include "../inc/Matrix.hpp"

int main(void) {
    std::cout << "Misc: \n";
    // try {
        // {
        //     std::vector<K>vec_a = {
        //         {-1 ,-2 ,-3 ,-4},
        //     };
        //     Vector a(vec_a);

        //     Vector b(
        //         {1 ,2 ,3 ,6}
        //     );
            
        //     std::cout << "Vec a\n" << a << "pearson correl\n" << a.spearman_correlation(b) << "\n"<< std::endl;
        // }
        {
            std::vector<std::vector<K> > mat_a = {
                {2.5,  2.4,  0.5},
                {0.5,  0.7, -0.1},
                {2.2,  2.9,  0.3},
                {1.9,  2.2,  0.0},
                {3.1,  3.0,  0.7}
            };
            Matrix a(mat_a);
            
            std::cout << "Vec a\n" << a << "mahalanobis dist\n" << a.mahalanobis_distance(true) << "\n"<< std::endl;
        }
        // {
        //     std::vector<K>vec_a = {
        //         {2., 1.},
        //     };
        //     Vector a(vec_a);

        //     double theta =  90;
        //     std::cout << "Vec a\n" << a << "outer\n" << a.rotation(theta, true) << "\n"<< std::endl;
        // }
        // {
        //     std::vector<std::vector<K> > matrix_u = {
        //         {1., 2.},
        //         {2., 4.},
        //     };
        //     Matrix u(matrix_u);

        //     std::vector<std::vector<K> > matrix_v = {
        //         {1., 2.},
        //         {2., 4.},
        //     };
        //     Matrix v(matrix_v);
        //     std::cout << "Matrix U\n" << u << "\n"<< std::endl;
        //     std::cout << "Kronecker\n" << u.kronecker_product(v) << "\n"<< std::endl;
        // }

    // } catch (std::exception& e){
    //     std::cout << e.what() << std::endl; 
    //     return (1);
    // }
    
    return (0);
}
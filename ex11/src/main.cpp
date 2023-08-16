#include <iostream>

#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"

template <typename K>
Vector<K>   cross_product(Vector<K> &u, Vector<K> &v){
    if (u.get_size() != 3 || u.get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a wrong size");
    }
    return ();
}

int main(void) {
    std::cout << "COSINE: \n";
    try {
        {
            std::vector<std::vector<float> > matrix_u = {
                {1., -1.},
                {-1., 1.},
            };
            Matrix u(matrix_u);

            std::cout << u.determinant() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {2., 0., 0.},
                {0., 2., 0.},
                {0., 0., 2.},
            };
            Matrix u(matrix_u);

            std::cout << u.determinant() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {8., 5., -2.},
                {4., 7., 20.},
                {7., 6., 1.},
            };
            Matrix u(matrix_u);

            std::cout << u.determinant() << std::endl;
        }
        {
            std::vector<std::vector<float> > matrix_u = {
                {8., 5., -2., 4.},
                {4., 2.5, 20., 4.},
                {8., 5., 1., 4.},
                {28., -4., 17., 1.},
            };
            Matrix u(matrix_u);

            std::cout << u.determinant() << std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
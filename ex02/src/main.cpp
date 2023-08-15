#include <iostream>

#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"
#include "../inc/Matrix.hpp"
#include "../src/Matrix.tpp"

template <typename V>
V   lerp(V u, V v, float t){
    if (t < 0 || t > 1){
        throw std::runtime_error("t must be 0 >= t <= 1");
    } else if (t == 0){
        return u;
    } else if (t == 1){
        return v;
    }
    return (u * (1 - t) + v * t);
}

int main(void) {
    std::cout << "LINEAR INTERPOLATION: \n";
    try {
        std::cout << "numbers:\n" << lerp(0., 1., 0.) << std::endl;
        std::cout << lerp(0., 1., 1.) << std::endl;
        std::cout << lerp(0., 1., 0.5) << std::endl;
        std::cout << lerp(21., 42., 0.3) << std::endl;

        std::vector<float> vec_v1 = {2., 1.};
        std::vector<float> vec_v2 = {4., 2.};
        Vector v1(vec_v1);
        Vector v2(vec_v2);
        std::cout << "Vectors:\n" << lerp(v1, v2, 0.3) << std::endl;

        std::vector<std::vector<float> > matrix_m1 = {
            {2., 1.},
            {3., 4.},
        };
        std::vector<std::vector<float> > matrix_m2 = {
            {20., 10.},
            {30., 40.},
        };
        Matrix m1(matrix_m1);
        Matrix m2(matrix_m2);
        std::cout << "Matrix:\n" << lerp(m1, m2, 0.5) << std::endl;
        
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
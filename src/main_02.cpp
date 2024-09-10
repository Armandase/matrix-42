#include <iostream>

#include "../inc/Vector.hpp"
#include "../inc/Matrix.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"


// Linear interpolation between two values
// u: first value
// v: second value
// t: interpolation factor
// return: interpolate's value
// (a value which starts at the origin and ends at a percentage between u and v scaled by t)
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
    std::cout << UNDERLINE << "LINEAR INTERPOLATION: \n" << END;
    try {
        std::cout << BOLD << "numbers:\n" << END << "scalar: 0 between 0 and 10 "<< lerp(0., 10., 0.) << std::endl;
        std::cout << "scalar: 1 between 0 and 10 " << lerp(0., 10., 1.) << std::endl;
        std::cout << "scalar: 0.5 between 0 and 10 " << lerp(0., 10., 0.5) << std::endl;
        std::cout << "scalar: 0.3 between 21 and 42 " << lerp(21., 42., 0.3) << std::endl;

        std::vector<K> vec_v1 = {2., 1.};
        std::vector<K> vec_v2 = {4., 2.};
        Vector v1(vec_v1);
        Vector v2(vec_v2);
        std::cout << BOLD << "Vectors:\n" << END << "scalar: 0.3 between \n" << v1 << " and \n" << v2 << "Result: \n" << lerp(v1, v2, 0.3) << std::endl;

        std::vector<std::vector<K> > matrix_m1 = {
            {2., 1.},
            {3., 4.},
        };
        std::vector<std::vector<K> > matrix_m2 = {
            {20., 10.},
            {30., 40.},
        };
        Matrix m1(matrix_m1);
        Matrix m2(matrix_m2);
        std::cout << BOLD << "Matrix:\n" << END << "scalar: 0.5 between\n" << m1 << " and\n" << m2 << "Result: \n" << lerp(m1, m2, 0.5) << std::endl;
        
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
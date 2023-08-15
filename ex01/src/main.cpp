#include <iostream>
#include "../inc/Vector.hpp"
#include "../inc/Matrix.hpp"

std::vector<K> linear_combination(const std::vector<std::vector<K>>& u, const std::vector<K>& coefs) {
    
}

int main(void) {
    // VECTOR
    std::cout << "VECTOR: \n";
    try {
        std::vector<double> vec_e1 = {1., 0., 0.};
        std::vector<double> vec_e2 = {0., 1., 0.};
        std::vector<double> vec_e3 = {0., 0., 1.};
        std::vector<double> vec_v1 = {1., 2., 3.};
        std::vector<double> vec_v2 = {0., 10., -100.};

        Vector e1(vec_e1);
        Vector e2(vec_e2);
        Vector e3(vec_e3);
        Vector v1(vec_v1);
        Vector v2(vec_v2);

        std::cout << linear_combination()
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
#include <iostream>

#include "../inc/Vector.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"


int main(void) {
    // VECTOR
    std::cout << "LINEAR COMBINATION: \n";
    try {
        {
            std::vector<K> vec_e1 = {1., 0., 0.};
            std::vector<K> vec_e2 = {0., 1., 0.};
            std::vector<K> vec_e3 = {0., 0., 1.};

            Vector e1(vec_e1);
            Vector e2(vec_e2);
            Vector e3(vec_e3);

            std::vector<Vector > e_vectors = {e1, e2, e3};
            std::vector<K> e_coefs = {10., -2., 0.5};
            std::cout << UNDERLINE <<"EXEMPLE 00:" << END << std::endl;
            std::cout << "Initials vectors: " << std::endl;
            for (auto &vec : e_vectors)
                std::cout << vec << std::endl;
            std::cout << "Coefficients: " << std::endl;
            for (auto &coef : e_coefs)
                std::cout << coef << std::endl;
            std::cout << BOLD << "Linear combination:\n" << END << linear_combination(e_vectors, e_coefs) << std::endl;
        }
        {
            std::cout << UNDERLINE << "EXEMPLE 01:" << END << std::endl;
            std::vector<K> vec_v1 = {1., 2., 3.};
            std::vector<K> vec_v2 = {0., 10., -100.};
            Vector v1(vec_v1);
            Vector v2(vec_v2);
            std::vector<Vector   > v_vectors = {v1, v2};
            std::vector<K> v_coefs = {10., -2.};
            std::cout << "Initials vectors: " << std::endl;
            for (auto &vec : v_vectors)
                std::cout << vec << std::endl;
            std::cout << "Coefficients: " << std::endl;
            for (auto &coef : v_coefs)
                std::cout << coef << std::endl;
            std::cout << BOLD << "Linear combination:\n" << END << linear_combination(v_vectors, v_coefs) << std::endl;
        }

    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
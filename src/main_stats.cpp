#include <iostream>

#include "../inc/Matrix.hpp"
#include "../inc/Vector.hpp"

int main(void) {
    std::cout << "Stats: \n";
    try {
        {
            std::vector<K> vec = {2, 3, 4};
            Vector x(vec);

            std::cout << "x:" << x << " var:"<< x.variance_population() << std::endl;
        }
        // {

        //     std::vector<K> vec = {2, 3};
        //     Vector x(vec);
        //     std::vector<K> sub = {5, 7};
        //     Vector y(sub);

        //     Matrix cov = x.covariance_matrix(y);
        //     std::cout << "x cov y is equal to:\n"
        //                 << cov << std::endl;
        // }
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
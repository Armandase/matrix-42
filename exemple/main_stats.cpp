#include <iostream>

#include "../inc/Matrix.hpp"
#include "../inc/Vector.hpp"

int main(void) {
    std::cout << "Stats: \n";
    try {
        // {
        //     std::vector<K> vec = {2, 2.5, 3, 3.5, 4, 7};
        //     Vector x(vec);

        //     std::cout << "x:" << x << " var pop:"<< x.variance_population() << std::endl;
        //     std::cout << " var sample:"<< x.variance_sample() << std::endl;
        //     std::cout << " avg :"<< x.average() << std::endl;
        //     std::cout << " std pop:"<< x.std() << std::endl;
        //     std::cout << " std sample:"<< x.std(true) << std::endl;
        // }
        // {
        //     std::vector<K> vec_a = {10,34,23,54,9};
        //     Vector a(vec_a);
        //     std::vector<K> vec_b = {4,5,11,15,20};
        //     Vector b(vec_b);

        //     K cov = a.covariance(b, true);
        //     std::cout << "x cov y is equal to:\n"
        //                 << cov << std::endl;
        //     std::cout << "\n" << std::endl;
        // }
        // {

        //     std::vector<K> vec_a = {11, 12, 12, 14, 16, 19, 19, 20, 21, 21};
        //     Vector a(vec_a);
        //     std::vector<K> vec_b = {16, 16, 16, 17, 18, 19, 22, 24, 25, 32};
        //     Vector b(vec_b);
        //     std::vector<K> vec_c = {18, 18, 19, 21, 21, 22, 22, 23, 24, 26};
        //     Vector c(vec_c);

        //     std::vector<Vector> vecs = {a, b, c};
        //     // Matrix cov = a.covariance_matrix(vecs, true);
        //     Matrix cov = covariance_matrix(vecs, true);
        //     std::cout << "x cov y is equal to:\n"
        //                 << cov << std::endl;
        // }
        {

            // std::vector<K> vec_a = {11, 12, 12, 14, 16, 19, 19, 20, 21, 21};
            std::vector<K> vec_a = {2, 4, 1};
            Vector a(vec_a);
            // std::vector<K> vec_b = {16, 16, 16, 17, 18, 19, 22, 24, 25, 32};
            std::vector<K> vec_b = {3, 5, 2};
            Vector b(vec_b);

            K dist = a.lp_distance(b, 3);
            std::cout << "Distance bewteen\n" << a << "\n"<< b << ":\n is equal to: "
                        << dist << std::endl;
        }
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
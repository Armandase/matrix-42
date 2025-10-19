#include <iostream>

#include "../inc/Matrix.hpp"
#include <chrono>

int main(void) {
    std::cout << "Time test: \n";
    int nb_iter = 10000;
    int based_nb_iter = nb_iter;
    std::chrono::microseconds average_duration(0);

    // start clock
    auto start = std::chrono::high_resolution_clock::now();
    try {
        while(nb_iter > 0){
            {
                auto inline_start = std::chrono::high_resolution_clock::now();
                std::vector<std::vector<K> > matrix_u = {
                    {8., 5., -2.},
                    {4., 7., 20.},
                    {7., 6., 1.},
                    {21., 18., 7.},
                };
                Matrix u(matrix_u);

                Matrix res = u.row_echelon_form();
                res = u.row_echelon_form();
                res = u.row_echelon_form();
                // std::cout << "Matrix res\n" << res << "\n"<< std::endl;
                auto inline_stop = std::chrono::high_resolution_clock::now();
                auto inline_duration = std::chrono::duration_cast<std::chrono::microseconds>(inline_stop - inline_start);
                average_duration += inline_duration;
            }
            --nb_iter;
        }
        // stop clock
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Time taken by function: "
                << duration.count() << " microseconds" << std::endl;
        std::cout << "Average time taken by function: "
                << (average_duration.count() / based_nb_iter) << " microseconds" << std::endl;
    } catch (std::exception& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
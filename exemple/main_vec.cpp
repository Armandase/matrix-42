#include <iostream>
#include <iomanip>

#include "../inc/Vector.hpp"

# define M_PI 3.14159265358979323846

int main(void) {
    std::cout << "Misc: \n";
    // try 
    // rotation for 3d vector
            std::vector<K> vec_a({2, 3, 1});
            Vector a(vec_a);

            std::cout << "Vector a\n" << a << "\n";
            auto rot_a = a.rotation3d(M_PI/16, Vector({1, 0, 0}));
            std::cout << "Vector a rotated\n" << rot_a << "\n";

    // } catch (std::exception& e){
    //     std::cout << e.what() << std::endl; 
    //     return (1);
    // }
    
    return (0);
}
#include <iostream>

#include "../inc/Vector.hpp"

#define BOLD "\e[1m"
#define UNDERLINE "\e[4m"
#define END "\e[0m"

/*
Le produit renvoie un vecteur perpendiculaire aux deux vecteurs en entrée.
/!\ pas commutatif
*/
Vector   cross_product(Vector &u, Vector &v){
    if (u.get_size() != 3 || u.get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a wrong size");
    }
    std::vector<K> result_vec;
    std::vector<K> u_vec = u.get_values();
    std::vector<K> v_vec = v.get_values();

    K y1z2 = u_vec[1] * v_vec[2];
    K z1y2 = u_vec[2] * v_vec[1];

    K z1x2 = u_vec[2] * v_vec[0];
    K x1z2 = u_vec[0] * v_vec[2];

    K x1y2 = u_vec[0] * v_vec[1];
    K y1x2 = u_vec[1] * v_vec[0];

    result_vec.push_back(y1z2 - z1y2);
    result_vec.push_back(z1x2 - x1z2);
    result_vec.push_back(x1y2 - y1x2);
    return (Vector (result_vec));
}

int main(void) {
    std::cout << UNDERLINE<<"CROSS PRODUCT: \n" << END;
    try {
        {
            std::vector<K> vec_u = {0., 0., 1.};
            std::vector<K> vec_v = {1., 0., 0.};
            Vector u(vec_u);
            Vector v(vec_v);
            std::cout << "Vector U\n" << u << "Vector V\n" << v << "Result\n" << cross_product(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {1., 2., 3.};
            std::vector<K> vec_v = {4., 5., 6.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << "Vector U\n" << u << "Vector V\n" << v << "Result\n" << cross_product(u, v) << "\n" << std::endl;
        }
        {
            std::vector<K> vec_u = {4., 2., -3.};
            std::vector<K> vec_v = {-2., -5., 16.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << "Vector U\n" << u << "Vector V\n" << v << "Result\n" << cross_product(u, v) << "\n" << std::endl;
            std::cout << "Dot product of the result with vector u: " << cross_product(u, v).dot(u) << std::endl;
            std::cout << "Dot product of the result with vector v: " << cross_product(u, v).dot(v) << std::endl;
            std::cout << "Dot product should be 0 if the vectors are perpendicular" << std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
#include <iostream>

#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"

Vector<K>   cross_product(Vector<K> &u, Vector<K> &v){
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
    //this result is perpendicular to both a and b
    return (Vector (result_vec));
}

int main(void) {
    std::cout << "COSINE: \n";
    try {
        {
            std::vector<float> vec_u = {0., 0., 1.};
            std::vector<float> vec_v = {1., 0., 0.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << cross_product(u, v) << std::endl;
        }
        {
            std::vector<float> vec_u = {1., 2., 3.};
            std::vector<float> vec_v = {4., 5., 6.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << cross_product(u, v) << std::endl;
        }
        {
            std::vector<float> vec_u = {4., 2., -3.};
            std::vector<float> vec_v = {-2., -5., 16.};
            Vector u(vec_u);
            Vector v(vec_v);

            std::cout << cross_product(u, v) << std::endl;
        }
    } catch (std::runtime_error& e){
        std::cout << e.what() << std::endl; 
        return (1);
    }
    
    return (0);
}
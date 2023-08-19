#include <iostream>

#include "../inc/Vector.hpp"
#include "../src/Vector.tpp"

template <typename K>
bool isOverflow(K a, K b, char op){
    K result;
    if (op == '+'){
        result = a + b;
        if((a > 0 && b > 0 && result < 0) 
            || (a < 0 && b < 0 && result > 0))
            return true;
        return false;
    }
    else if (op == '-'){
        result = a - b;
        if (result > a && b > 0)
            return true;
        else
            return false;
    }
    else if (op == '*'){
        if (a == 0 || b == 0)
            return false;
        result = a * b;
        return (a == result / b) ? false : true;
    }
    return false;
}

template <typename K>
Vector<K>   cross_product(Vector<K> &u, Vector<K> &v){
    if (u.get_size() != 3 || u.get_size() != v.get_size()){
        throw std::runtime_error("Vectors given as input have a wrong size");
    }
    std::vector<K> result_vec;
    std::vector<K> u_vec = u.get_values();
    std::vector<K> v_vec = v.get_values();

    if (isOverflow(u_vec[1], v_vec[2], '*') == true || isOverflow(u_vec[2], v_vec[1], '*') == true){
        throw std::runtime_error("A multiplication generate an overflow");
    }
    K y1z2 = u_vec[1] * v_vec[2];
    K z1y2 = u_vec[2] * v_vec[1];

    if (isOverflow(u_vec[2], v_vec[0], '*') == true || isOverflow(u_vec[0], v_vec[2], '*') == true){
        throw std::runtime_error("A multiplication generate an overflow");
    }
    K z1x2 = u_vec[2] * v_vec[0];
    K x1z2 = u_vec[0] * v_vec[2];

    if (isOverflow(u_vec[0], v_vec[1], '*') == true || isOverflow(u_vec[1], v_vec[0], '*') == true){
        throw std::runtime_error("A multiplication generate an overflow");
    }
    K x1y2 = u_vec[0] * v_vec[1];
    K y1x2 = u_vec[1] * v_vec[0];

    if (isOverflow(y1z2, z1y2, '-') == true
        || isOverflow(z1x2, x1z2, '-') == true
        || isOverflow(x1y2, y1x2, '-') == true){
        throw std::runtime_error("A subtraction generate an overflow");
    }

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
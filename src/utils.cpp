# include "../inc/utils.hpp"

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


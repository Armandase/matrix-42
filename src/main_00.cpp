#include <iostream>

#include "../inc/Vector.hpp"
#include "../inc/Matrix.hpp"

int main(void)
{
    std::cout << "SUBJECT TEST: \n"
              << std::endl;
    std::cout << "VECTOR: \n";
    try
    {
        {
            {
                std::vector<K> vec = {2, 3};
                Vector u(vec);
                std::cout << "u is equal to:\n"
                          << u << std::endl;

                std::vector<K> add = {5, 7};
                Vector v(add);
                std::cout << "v is equal to:\n"
                          << v << std::endl;
                u.add(v);
                std::cout << "u + v is equal to:\n"
                          << u << std::endl;
            }
            {
                std::vector<K> vec = {2, 3};
                Vector u(vec);
                std::vector<K> sub = {5, 7};
                Vector v(sub);
                u.sub(v);
                std::cout << "u - v is equal to:\n"
                          << u << std::endl;
            }
            {
                std::vector<K> vec = {2, 3};
                Vector u(vec);
                u.scl(2);
                std::cout << "Vector u multiplied by 2 is equal to:\n"
                          << u << std::endl;
            }
        }
        std::cout << "MATRIX: \n";
        {
            {
                std::vector<std::vector<K>> vec = {
                    {1, 2},
                    {3, 4}};
                Matrix m1(vec);
                std::cout << "m1 is equal to:\n"
                          << m1 << std::endl;

                std::vector<std::vector<K>> add = {
                    {7, 4},
                    {-2, 2}};

                Matrix m2(add);
                std::cout << "m2 is equal to:\n"
                          << m2 << std::endl;
                m1.add(m2);
                std::cout << "m1 + m2 is equal to:\n"
                          << m1 << std::endl;
            }

            {
                std::vector<std::vector<K>> vec = {
                    {1, 2},
                    {3, 4}};
                Matrix m1(vec);
                std::vector<std::vector<K>> sub = {
                    {7, 4},
                    {-2, 2}};
                Matrix m2(sub);
                m1.sub(m2);
                std::cout << "m1 - m2 is equal to:\n"
                          << m1 << std::endl;
            }
            {
                std::vector<std::vector<K>> vec = {
                    {1, 2},
                    {3, 4}};
                Matrix m1(vec);
                m1.scl(2);
                std::cout << "Matrix m1 multiplied by 2 is equal to:\n"
                          << m1 << std::endl;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }

    std::cout << "OWN TEST: \n";
    // VECTOR
    std::cout << "VECTOR: \n";
    try
    {
        std::vector<K> vec = {2.1, -4.5, 4.0};
        Vector u(vec);
        std::cout << "u is equal to:\n"
                  << u << std::endl;

        std::vector<K> add = {1.9, 7.5, 4.0};
        Vector v(add);
        std::cout << "v is equal to:\n"
                  << v << std::endl;
        u.add(v);
        std::cout << "u + v is equal to:\n"
                  << u << std::endl;
        u.scl(2.5);
        std::cout << "This result multiplied by 2.5 is equal to:\n"
                  << u << std::endl;
        u.sub(v);
        std::cout << "This result subtracted v equal to:\n"
                  << u << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    // MATRIX
    std::cout << "MATRIX: \n";
    try
    {
        std::vector<std::vector<K>> vec = {
            {1.5, -7.0, 9.8},
            {4.0, 5.1, 22.0},
            {11.9, 0.0, 2.2}};
        Matrix m1(vec);
        std::cout << "m1 is equal to:\n"
                  << m1 << std::endl;

        std::vector<std::vector<K>> add = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };
        Matrix m2(add);
        std::cout << "m2 is equal to:\n"
                  << m2 << std::endl;
        m1.add(m2);
        std::cout << "m1 + m2 is equal to:\n"
                  << m1 << std::endl;
        m1.scl(2.5);
        std::cout << "This result multiplied by 2.5 is equal to:\n"
                  << m1 << std::endl;
        m1.sub(m2);
        std::cout << "This result subtracted m2 equal to:\n"
                  << m1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }

    return (0);
}
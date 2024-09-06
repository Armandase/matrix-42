#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>

class Complex{
	public:
		Complex();
		~Complex();
		Complex(float real, float imaginary);
		Complex(float real);
		Complex(const Complex &copy);
		Complex& operator = (const Complex& fixed);
		bool operator > (const Complex& fixed);
		bool operator < (const Complex& fixed);
		bool operator >= (const Complex& fixed);
		bool operator <= (const Complex& fixed);
		bool operator == (const Complex& fixed);
		bool operator != (const Complex& fixed);
		Complex& operator + (const Complex& fixed);
		Complex& operator += (const Complex& fixed);
		Complex& operator - (const Complex& fixed);
		Complex& operator - (void);
		Complex& operator -= (const Complex& fixed);
		Complex& operator * (const Complex& fixed);
		Complex& operator *= (const Complex& fixed);
		Complex& operator / (const Complex& fixed);
		Complex& operator /= (const Complex& fixed);
		Complex operator ++ (int);//postfix
		Complex& operator ++ (void);//prefix
		Complex operator -- (int);
		Complex& operator -- (void);
		Complex& operator pow (const Complex& fixed, int power);
		Complex& operator sqrt (void);
	private:
		float	_real;
		float	_imaginary;
};

std::ostream& operator<<(std::ostream& os, const Complex& data);

#endif

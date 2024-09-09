#ifndef _FIXED_HPP_
# define _FIXED_HPP_

# include <iostream>
# include <stdexcept>

class Complex{
	public:
		Complex();
		~Complex();
		Complex(float real, float imaginary);
		Complex(float real);
		Complex(const Complex &copy);
		Complex& operator = (const Complex& cplx);
		bool operator > (const Complex& cplx);
		bool operator < (const Complex& cplx);
		bool operator >= (const Complex& cplx);
		bool operator <= (const Complex& cplx);
		bool operator == (const Complex& cplx);
		bool operator != (const Complex& cplx);
		Complex& operator + (const Complex& cplx);
		Complex& operator + (int cplx);
		Complex& operator + (double cplx);
		Complex& operator += (const Complex& cplx);
		Complex& operator - (const Complex& cplx);
		Complex& operator - (void);
		Complex& operator -= (const Complex& cplx);
		Complex& operator * (const Complex& cplx);
		Complex& operator * (double cplx);
		Complex& operator *= (const Complex& cplx);
		Complex& operator / (const Complex& cplx);
		Complex& operator /= (const Complex& cplx);
		Complex operator ++ (int);//postfix
		Complex& operator ++ (void);//prefix
		Complex operator -- (int);
		Complex& operator -- (void);
		bool operator ! (void);

		float	getReal() const;
		float	getImaginary() const;
	private:
		float	_real;
		float	_imaginary;
};

std::ostream& operator<<(std::ostream& os, const Complex& data);

#endif

#include "Complex.hpp"

Complex::Complex()
{
	this->_real = 0;
	this->_imaginary = 0;
}

Complex::Complex(float real, float imaginary)
{
	this->_real = real;
	this->_imaginary = imaginary;
}

Complex::Complex(float real)
{
	this->_real = real;
	this->_imaginary = 0;
}

Complex::~Complex()
{
}

Complex::Complex(const Complex &copy){
	Complex::operator=(copy);
}

std::ostream& operator<<(std::ostream& os, const Complex& data)
{
	os << ->_real << " + " << data._imaginary << "i";
	return (os);
}

Complex& Complex::operator=(const Complex &fixed)
{
	this->_real = fixed._real;
	this->_imaginary = fixed._imaginary;
	return *this;
}

bool Complex::operator>(const Complex& fixed)
{
	if (this->_real > fixed._real && this->_imaginary > fixed._imaginary
	|| this->_real > fixed._real && this->_imaginary == fixed._imaginary
	|| this->_real == fixed._real && this->_imaginary > fixed._imaginary)	
		return (true);
	return (false);
}

bool Complex::operator<(const Complex& fixed)
{
	if (this->_real < fixed._real && this->_imaginary < fixed._imaginary
	|| this->_real < fixed._real && this->_imaginary == fixed._imaginary
	|| this->_real == fixed._real && this->_imaginary < fixed._imaginary)
		return (true);
	return (false);
}

bool Complex::operator>=(const Complex& fixed)
{
	if (this->_real >= fixed._real && this->_imaginary >= fixed._imaginary)
		return (true);
	return (false);
}

bool Complex::operator<=(const Complex& fixed)
{
	if (this->_real <= fixed._real && this->_imaginary <= fixed._imaginary)
		return (true);
	return (false);
}

bool Complex::operator==(const Complex& fixed)
{
	if (this->_real == fixed._real && this->_imaginary == fixed._imaginary)
		return (true);
	return (false);
}

bool Complex::operator!=(const Complex& fixed)
{
	if (this->_real != fixed._real || this->_imaginary != fixed._imaginary)
		return (true);
	return (false);
}

Complex& Complex::operator + (const Complex& fixed)
{
	this->_real += fixed._real;
	this->_imaginary += fixed._imaginary;
	return (*this);
}

Complex& Complex::operator += (const Complex& fixed)
{
	this->_real += fixed._real;
	this->_imaginary += fixed._imaginary;
	return (*this);
}

Complex& Complex::operator - (const Complex& fixed)
{
	this->_real -= fixed._real;
	this->_imaginary -= fixed._imaginary;
	return (*this);
}

Complex& Complex::operator - (void)
{
	this->_real = -this->_real;
	this->_imaginary = -this->_imaginary;
	return (*this);
}


Complex& Complex::operator -= (const Complex & fixed)
{
	this->_real -= fixed._real;
	this->_imaginary -= fixed._imaginary;
	return (*this);
}

Complex& Complex::operator * (const Complex& fixed)
{
	this->_real = this->_real * fixed._real - this->_imaginary * fixed._imaginary;
	this->_imaginary = this->_real * fixed._imaginary + this->_imaginary * fixed._real;
	return (*this);
}

Complex& Complex::operator *= (const Complex& fixed)
{
	this->_real = this->_real * fixed._real - this->_imaginary * fixed._imaginary;
	this->_imaginary = this->_real * fixed._imaginary + this->_imaginary * fixed._real;
	return (*this);
}

Complex& Complex::operator / (const Complex& fixed)
{
	this->_real = (this->_real * fixed._real + this->_imaginary * fixed._imaginary) / (fixed._real * fixed._real + fixed._imaginary * fixed._imaginary);
	this->_imaginary = (this->_imaginary * fixed._real - this->_real * fixed._imaginary) / (fixed._real * fixed._real + fixed._imaginary * fixed._imaginary);
	return (*this);
}

Complex& Complex::operator /= (const Complex& fixed)
{
	this->_real = (this->_real * fixed._real + this->_imaginary * fixed._imaginary) / (fixed._real * fixed._real + fixed._imaginary * fixed._imaginary);
	this->_imaginary = (this->_imaginary * fixed._real - this->_real * fixed._imaginary) / (fixed._real * fixed._real + fixed._imaginary * fixed._imaginary);
	return (*this);
}

Complex Complex::operator ++ (int)
{
	Complex	ret = *this;
	this->_real++;
	this->_imaginary++;
	return (ret);
}

Complex& Complex::operator ++ (void)
{
	this->_real++;
	this->_imaginary++;
	return (*this);
}

Complex& Complex::operator -- (void)
{
	this->_real--;
	this->_imaginary--;
	return (*this);
}

Complex Complex::operator -- (int)
{
	Complex	ret = *this;
	this->_real--;
	this->_imaginary--;
	return (ret);
}

Complex& Complex::operator pow (const Complex& fixed, int power)
{
	this->_real = pow(a, _real);
	this->_imaginary = pow(a, _imaginary);
	return (*this);
}

Complex& Complex::operator sqrt (void)
{
	float a = this->_real;
	float b = this->_imaginary;
	this->_real = sqrt(a + sqrt(a * a + b * b) / 2);
	this->_imaginary = b / abs(b) * sqrt(-a + sqrt(a * a + b * b) / 2);
	return (*this);
}
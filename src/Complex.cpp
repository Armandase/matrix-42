#include "../inc/Complex.hpp"

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

float Complex::getReal() const
{
	return (this->_real);
}

float Complex::getImaginary() const
{
	return (this->_imaginary);
}

std::ostream& operator<<(std::ostream& os, const Complex& data)
{
	os << data.getReal() << " + " << data.getImaginary() << "i";
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
	if ((this->_real > fixed._real && this->_imaginary > fixed._imaginary)
	|| (this->_real > fixed._real && this->_imaginary == fixed._imaginary)
	|| (this->_real == fixed._real && this->_imaginary > fixed._imaginary))	
		return (true);
	return (false);
}

bool Complex::operator<(const Complex& fixed)
{
	if ((this->_real < fixed._real && this->_imaginary < fixed._imaginary)
	|| (this->_real < fixed._real && this->_imaginary == fixed._imaginary)
	|| (this->_real == fixed._real && this->_imaginary < fixed._imaginary))
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

Complex& Complex::operator + (int cplx)
{
	this->_real += static_cast<float>(cplx);
	return (*this);
}

Complex& Complex::operator + (double cplx)
{
	this->_real += cplx;
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
	this->_real = this->_real * fixed._real;
	this->_imaginary = this->_imaginary * fixed._imaginary;
	return (*this);
}

Complex& Complex::operator *= (const Complex& fixed)
{
	this->_real = this->_real * fixed._real;
	this->_imaginary = this->_imaginary * fixed._imaginary;
	return (*this);
}

Complex& Complex::operator / (const Complex& fixed)
{
	if (fixed._real == 0 && fixed._imaginary == 0)
		throw std::invalid_argument("Division by zero");
	
	if (fixed._real == 0)
		this->_imaginary = this->_imaginary / fixed._imaginary;
	if (fixed._imaginary == 0)
		this->_real = this->_real / fixed._real;

	if (fixed._real != 0 && fixed._imaginary != 0)
	{
		this->_real = this->_real / fixed._real;
		this->_imaginary = this->_imaginary / fixed._imaginary;
	}
	return (*this);
}

Complex& Complex::operator /= (const Complex& fixed)
{
	if (fixed._real == 0 && fixed._imaginary == 0)
		throw std::invalid_argument("Division by zero");
	
	if (fixed._real == 0)
		this->_imaginary = this->_imaginary / fixed._imaginary;
	if (fixed._imaginary == 0)
		this->_real = this->_real / fixed._real;
	if (fixed._real != 0 && fixed._imaginary != 0)
	{
		this->_real = this->_real / fixed._real;
		this->_imaginary = this->_imaginary / fixed._imaginary;
	}
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

Complex& Complex::operator*(double fixed)
{
	this->_real *= fixed;
	return (*this);
}

bool Complex::operator ! (void)
{
	if (this->_real == 0 && this->_imaginary == 0)
		return (true);
	return (false);
}
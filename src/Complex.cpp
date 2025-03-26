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

Complex::Complex(const Complex &copy)
{
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
	if (this == &fixed)
		return *this;	
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

Complex Complex::operator + (const Complex& fixed)
{
	return (Complex(this->_real + fixed._real, this->_imaginary + fixed._imaginary));
}

Complex& Complex::operator += (const Complex& fixed)
{
	this->_real += fixed._real;
	this->_imaginary += fixed._imaginary;
	return (*this);
}

Complex Complex::operator - (const Complex& fixed)
{
	return (Complex(this->_real - fixed._real, this->_imaginary - fixed._imaginary));
}

Complex Complex::operator - (void)
{
	return (Complex(-this->_real, -this->_imaginary));
}

Complex Complex::operator + (int cplx)
{
	return (Complex(this->_real + static_cast<float>(cplx), this->_imaginary));
}

Complex Complex::operator + (double cplx)
{
	return(Complex(this->_real + cplx, this->_imaginary));
}

Complex& Complex::operator -= (const Complex & fixed)
{
	this->_real -= fixed._real;
	this->_imaginary -= fixed._imaginary;
	return (*this);
}

Complex Complex::operator * (const Complex& fixed)
{
	auto tmp = this->_real;
	auto real = this->_real * fixed._real - this->_imaginary * fixed._imaginary;
	auto imaginary = tmp * fixed._imaginary + this->_imaginary * fixed._real;
	return (Complex(real, imaginary));
}

Complex& Complex::operator *= (const Complex& fixed)
{
	auto tmp = this->_real;
	this->_real = this->_real * fixed._real - this->_imaginary * fixed._imaginary;
	this->_imaginary = tmp * fixed._imaginary + this->_imaginary * fixed._real;
	return (*this);
}

Complex Complex::operator / (const Complex& fixed)
{
	if (fixed._real == 0 && fixed._imaginary == 0)
		throw std::invalid_argument("Division by zero");
	
    float denom = fixed._real * fixed._real + fixed._imaginary * fixed._imaginary;
	if (denom == 0)
		throw std::invalid_argument("Division by zero");
    float real = (this->_real * fixed._real + this->_imaginary * fixed._imaginary) / denom;
    float imaginary = (this->_imaginary * fixed._real - this->_real * fixed._imaginary) / denom;

    return Complex(real, imaginary);
}

Complex& Complex::operator /= (const Complex& fixed)
{
    if (fixed._real == 0 && fixed._imaginary == 0)
        throw std::invalid_argument("Division by zero");

    float denom = fixed._real * fixed._real + fixed._imaginary * fixed._imaginary;
	if (denom == 0)
		throw std::invalid_argument("Division by zero");
    float new_real = (this->_real * fixed._real + this->_imaginary * fixed._imaginary) / denom;
    float new_imaginary = (this->_imaginary * fixed._real - this->_real * fixed._imaginary) / denom;

    this->_real = new_real;
    this->_imaginary = new_imaginary;

    return *this;
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

Complex Complex::operator*(double scalar)
{
	return (Complex(this->_real * scalar, this->_imaginary * scalar));
}

bool Complex::operator ! (void)
{
	if (this->_real == 0 && this->_imaginary == 0)
		return (true);
	return (false);
}

bool Complex::operator == (float cplx){
	if (this->_real == cplx)
		return (true);
	return (false);
}

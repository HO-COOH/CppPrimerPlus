#include "complex0.h"

complex complex::operator+(const complex& a) const
{
	return complex(real + a.real, imaginary + a.imaginary);
}

complex complex::operator-(const complex& a) const
{
	return complex(real - a.real, imaginary - a.imaginary);
}

complex complex::operator*(double n) const
{
	return complex(n * real, n * imaginary);
}

complex complex::operator~() const
{
	return complex(real, -imaginary);
}

complex operator*(double n, const complex& a)
{
	return a * n;
}

std::istream& operator>>(std::istream& is, complex& a)
{
	std::cout << "real: ";
	is >> a.real;
	if (!is)
		return is;
	std::cout << "imaginary: ";
	is >> a.imaginary;
	return is;
}

std::ostream& operator<<(std::ostream& os, const complex& a)
{
	os << "(" << a.real << ", " << a.imaginary << "i)";
	return os;
}

complex operator*(const complex& a, const complex& b)
{
	return complex(a.real * b.real - a.imaginary * b.imaginary, a.real * b.imaginary + a.imaginary * b.real);
}
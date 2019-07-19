#pragma once
#include <iostream>

class complex
{
private:
	double real;
	double imaginary;
public:
	complex() :real(0), imaginary(0) {}
	complex(double r, double i) :real(r), imaginary(i) {}
	complex operator+(const complex& a) const;
	complex operator-(const complex& a) const;
	complex operator*(double n) const;
	complex operator~() const;
	friend complex operator*(double n, const complex& a);
	friend std::istream& operator>>(std::istream& is, complex& a);
	friend std::ostream& operator<<(std::ostream& os, const complex& a);
	friend complex operator*(const complex& a, const complex& b);
};
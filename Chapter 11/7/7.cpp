#include "7.h"

complex::complex()
{
	a = 0.0;
	b = 0.0;
}

complex::complex(double r, double m)
{
	a = r;
	b = m;
}

void complex::set(double a, double b)
{
	this->a = a;
	this->b = b;
}

complex operator+(const complex & c1, const complex & c2)
{
	complex res;
	
	res.a = c1.a + c2.a;
	res.b = c1.b + c2.b;
	return res;
}

complex operator-(const complex & c1, const complex & c2)
{
	complex res;
	
	res.a = c1.a - c2.a;
	res.b = c1.b - c2.b;
	return res;
}

complex operator*(const complex & c1, const complex & c2)
{
	complex res;
	
	res.a = c1.a * c2.a;
	res.b = c1.b * c2.b;
	return res;
}

complex operator*(double d, const complex & c2)
{
	complex res;
	res.a = c2.a * d;
	res.b = c2.b * d;
}

complex operator~(const complex & c)
{
	complex res;
	res.a = c.a;
	res.b = -c.b;
	
	return res;
}

std::ostream & operator<<(std::ostream & os, const complex & c)
{
	os << "(" << c.a << ", " << c.b << "i)";
	return os;
}

std::istream & operator>>(std::istream & is, complex & c)
{
	is >> c.a;
	is >> c.b;
	return is;
}

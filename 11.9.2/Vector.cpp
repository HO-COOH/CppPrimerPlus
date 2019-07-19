#include "Vector.h"
#include <cmath>
using namespace std;
namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);

	void Vector::pol_to_rect(double mag, double ang)
	{
		x = mag * cos(ang);
		y = mag * sin(ang);
	}
	Vector::Vector()
	{
		x = y = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1; y = n2;
		}
		else if (form == POL)
		{
			//double mag = n1; double ang = n2 / Rad_to_deg;
			pol_to_rect(n1, n2 / Rad_to_deg);
		}
		else
		{
			cout << "Incorrect 3rd argument! Values set ->0, mode -> RECT";
			Vector();
		}
	}
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT)
		{
			x = n1; y = n2;
		}
		else if (form == POL)
		{
			pol_to_rect(n1, n2 / Rad_to_deg);
		}
		else
		{
			cout << "Incorrect 3rd argument! Values set -> 0, mode -> RECT";
			x = y = 0.0;
			mode = RECT;
		}
	}

	Vector::~Vector()
	{
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}
	void Vector::rect_mode()
	{
		mode = RECT;
	}

	Vector Vector::operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const
	{
		return Vector(x * n, y * n);
	}

	Vector operator*(double n, const Vector& a)
	{
		return a * n;
	}

	std::ostream& operator<<(std::ostream& os, const Vector& v)
	{
		if (v.mode == Vector::RECT)
			os << "(x,y) = (" << v.x << ", " << v.y << " )";
		else
			os << "(m,a) = (" << v.magval() << ", " << v.angval() << " )";
		return os;
	}
}
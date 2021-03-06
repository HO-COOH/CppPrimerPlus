#pragma once
#include <iostream>
#include <math.h>
namespace VECTOR
{
	class Vector
	{
	public:enum Mode { RECT, POL };
	private:
		double x;
		double y;
		//double mag;
		//double ang;	//This is using rad unit.
		Mode mode;	//RECT or POL
	//private methods for setting values
		//void set_x();
		//void set_y();
		//void set_mag();
		//void set_ang();
		void pol_to_rect(double mag, double ang);
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();

		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return sqrt(x*x+y*y); }
		double angval() const { return atan2(y,x); }

		void polar_mode();
		void rect_mode();

		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;	//reverse sign
		Vector operator*(double n) const;//vector * n

		friend Vector operator*(double n, const Vector& a);//n * vector 
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}


#include "Stonewt.h"
#include <iostream>

//enum { Lbs_per_stn = 14 };//pounds per stone
using namespace std;
int main()
{
	Stonewt a(30);
	cout << a;
	Stonewt b(2, 11);
	cout << b;
	Stonewt c = a + b;
	cout << c;
	c.setMode(Stonewt::STONE);
	cout << c;
	c.setMode(Stonewt::FRACTIONAL_POUNDS);
	cout << c;
	c.setMode(Stonewt::WHOLE_POUNDS);
	cout << c;
}
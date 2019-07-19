#include "Classic.h"
#include <iostream>
using namespace std;

void Bravo(const Cd& disk)
{
	disk.Report();
}

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.7);
	Cd* pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report();	//use Cd method
	c2.Report();	//use Classic method

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	c2.Report();
}
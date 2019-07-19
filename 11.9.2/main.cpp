#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Vector.h"
using namespace std;
using namespace VECTOR;
int main()
{
	srand(time(0));
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double direction;
	double stepLen;
	ofstream outFile;
	outFile.open("record");
	cout << "Enter target distance (q to quit) -> ";
	while (cin >> target)
	{
		cout << endl << "Enter step length -> ";
		if (!(cin >> stepLen))
			break;
		outFile << "Target distance: " << target << ", Step Size: " << stepLen << endl;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(stepLen, direction, Vector::POL);
			result = result + step;
			outFile << steps << ": (x,y) = " << result << endl;
			++steps;
		}
		outFile << "After " << steps << "steps, the subject has the following location:\n";
		result.rect_mode();
		outFile << result << endl << "or" << endl;
		result.polar_mode();
		outFile << result << endl;
		outFile << "Average outward distance per step = " << result.magval() / steps;
		cout << "Enter target distance (q to quit) -> ";
	}
	outFile.close();
	cout << "Bye." << endl;
}

////OUTPUT:
//Target distance : 100, Step Size : 20
//0 : (x, y) = (x, y) = (19.8509, 2.43739)
//1 : (x, y) = (x, y) = (30.7437, -14.336)
//2 : (x, y) = (x, y) = (41.3421, -31.297)
//3 : (x, y) = (x, y) = (32.2623, -49.1171)
//4 : (x, y) = (x, y) = (45.9022, -34.49)
//5 : (x, y) = (x, y) = (60.0444, -20.3479)
//6 : (x, y) = (x, y) = (74.6715, -6.70794)
//7 : (x, y) = (x, y) = (68.1601, -25.6183)
//8 : (x, y) = (x, y) = (81.2813, -10.5241)
//9 : (x, y) = (x, y) = (100.6, -15.7005)
//After 10steps, the subject has the following location :
//(x, y) = (100.6, -15.7005)
//or
//(m, a) = (101.818, -0.15482)
//Average outward distance per step = 10.1818

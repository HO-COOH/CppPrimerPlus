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

//OUTPUT:
//Target distance : 100, Step Size : 20
//0 : (x, y) = (x, y) = (19.0211, 19.0211)
//1 : (x, y) = (x, y) = (35.9821, 35.9821)
//2 : (x, y) = (x, y) = (55.906, 55.906)
//3 : (x, y) = (x, y) = (68.4924, 68.4924)
//4 : (x, y) = (x, y) = (82.6345, 82.6345)
//After 5steps, the subject has the following location :
//(x, y) = (82.6345, 82.6345)
//or
//(m, a) = (116.863, 0.785398)

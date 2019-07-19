#include "Stonewt.h"
#include <iostream>
using namespace std;
int main()
{
	Stonewt a[6]{ (13.0),(14.6),(17.5) };
	Stonewt cmp{ 11 };
	Stonewt max = a[0];
	Stonewt min = a[0];
	int count = 0;
	for (auto x : a)
	{
		if (x > max)
			max = x;
		if (x < min)
			min = x;
		if (x >= cmp)
			++count;
	}
	max.show_stn();
	min.show_lbs();
	cout << endl << count;
}
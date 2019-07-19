#include <iostream>
#include "Wine.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter name of wine: ";
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: ";
	int yrs;
	cin >> yrs;

	Wine holding(lab, yrs);
	holding.GetBottles();
	holding.Show();

	const int YRS = 3;
	int y[YRS] = { 1993,1995,1998 };
	int b[YRS] = { 48,60,72 };
	//create new object, initialize using data in arrays y and b
	Wine more("Grushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Label()	//use Label() method
		<< ": " << more.Sum() << endl;				//use Sum() method
	cout << "Bye\n";
}

//OUTPUT:
//Enter name of wine : Gully Wash
//Enter number of years : 4
//Enter Gully Wash data for 4 year(s) :
//	Enter year : 1998
//	Enter bottles for that year : 42
//	Enter year : 1994
//	Enter bottles for that year : 58
//	Enter year : 1998
//	Enter bottles for that year : 122
//	Enter year : 2001
//	Enter bottles for that year : 144
//	Wine : Gully Wash
//	Year    Bottles
//	1998    42
//	1994    58
//	1998    122
//	2001    144
//	Wine : Grushing Grape Red
//	Year    Bottles
//	1993    48
//	1995    60
//	1998    72
//	Total bottles for Grushing Grape Red : 180
//	Bye
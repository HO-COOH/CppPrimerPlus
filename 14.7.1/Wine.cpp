#include "Wine.h"
#include <iostream>
Wine::Wine(const char* l, int y, const int yr[], const int bot[]):name(l),numYears(y),pair(ArrayInt(yr,y),ArrayInt(bot,y))
{
}

Wine::Wine(const char* l, int y) : name(l), numYears(y)
{
	pair.first.resize(y);
	pair.second.resize(y);
}

void Wine::GetBottles()
{
	using std::cin;
	using std::cout;
	cout << "Enter " << name << " data for " << numYears << " year(s):\n";
	for (int i = 0; i < numYears; ++i)
	{
		int year;
		int bottles;
		cout << "Enter year: ";
		cin >> year;
		cout << "Enter bottles for that year: ";
		cin >> bottles;
		pair.first[i] = year;
		pair.second[i] = bottles;
	}
}

void Wine::Show()
{
	using std::cout;
	using std::endl;
	cout << "Wine: " << name << endl;
	cout << "\tYear\tBottles"<<endl;
	for (int i = 0; i < numYears; ++i)
	{
		cout <<"\t"<< pair.first[i] << "\t" << pair.second[i] << endl;
	}
}

string& Wine::Label()
{
	return name;
}

int Wine::Sum()
{
	return pair.second.sum();
}

#include "Wine.h"

Wine::Wine(const char* l, int y, const int yr[], const int bot[]): string(l), PairArray(ArrayInt(yr,y), ArrayInt(bot,y)), numYears(y)
{
}

Wine::Wine(const char* l, int y) : string(l), PairArray(ArrayInt(y), ArrayInt(y)), numYears(y)
{
}

void Wine::GetBottles()
{
	using std::cin;
	using std::cout;
	cout << "Enter " << (const string&)*this << " data for " << numYears << " year(s):\n";
	//auto x = (PairArray&)(*this);
	for (int i = 0; i < numYears; ++i)
	{
		int year;
		int bottles;
		cout << "Enter year: ";
		cin >> year;
		cout << "Enter bottles for that year: ";
		cin >> bottles;
		((PairArray&)(*this)).first[i] = year;
		((PairArray&)(*this)).second[i] = bottles;
	}
}

void Wine::Show()
{
	using std::cout;
	using std::endl;
	cout << "Wine: " << (const string&)*this << endl;
	cout << "\tYear\tBottles" << endl;
	//auto x = (PairArray&)* this;
	for (int i = 0; i < numYears; ++i)
	{
		cout << "\t" << ((PairArray&)(*this)).first[i] << "\t" << ((PairArray&)(*this)).second[i] << endl;
	}
}

string& Wine::Label()
{
	return (string&)* this;
}

int Wine::Sum()
{
	return ((const PairArray&)* this).second.sum();
}
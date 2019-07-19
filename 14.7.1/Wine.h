#pragma once
#include <valarray>
#include <utility>
#include <string>

using std::string;
using ArrayInt=std::valarray<int>;
using PairArray=std::pair<ArrayInt, ArrayInt>;	//PairArray=pair< valarray<int>,valarray<int> >

class Wine
{
	string name;
	PairArray pair;
	int numYears;
public:
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);
	Wine() {}
	void GetBottles();
	void Show();
	string& Label();
	int Sum();
};
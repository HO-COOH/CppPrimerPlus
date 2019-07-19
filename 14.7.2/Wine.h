#pragma once
#include <valarray>
#include <utility>
#include <string>
#include <iostream>

using std::string;
using ArrayInt=std::valarray<int>;
using PairArray=std::pair<ArrayInt, ArrayInt>;

class Wine :string, PairArray
{
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


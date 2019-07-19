//The problem should be rewrite program 16.15 instead of 16.5. 
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	auto outint = [](const int& n) {cout << n << " "; };
	list<int>yadayada = { 50,100,90,180,60,210,415,88,188,201 };
	list<int>etcetera{ 50,100,90,180,60,210,415,88,188,201 };
	cout << "Original lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	yadayada.remove_if([](const int& n) {return n > 100; });
	etcetera.remove_if([](const int& n) {return n > 200; });
	cout << "Trimmed lists:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;
}

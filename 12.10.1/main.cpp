#include "Cow.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	cout << "Enter the name of the cow (q to quit) -> ";
	while (1)
	{
		char name[20];
		if (cin >> name)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
		}
		if (!strcmp(name, "q"))
			break;
		cout << "Enter the hobby of the cow -> ";
		string ho;
		cin >> ho;
		double weight;
		cout << "Enter the weight of the cow -> ";
		cin >> weight;
		Cow a(name, ho.c_str(), weight);
		a.ShowCow();
		cout << "Enter the name of the cow (q to quit) -> ";
	}
	cout << "Bye.\n";
}
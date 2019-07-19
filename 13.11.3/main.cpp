#include <iostream>
#include "DMA.h"
#include <vector>
int main()
{
	using std::cout;
	using std::endl;
	using std::vector;

	vector <base*> objArray;

	baseDMA shirt("Portabelly", 8);
	lacksDMA ballon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);
	cout << "Displaying baseDMA object:\n";
	shirt.View();
	objArray.push_back(&shirt);

	cout << "Displayingf lacksDMA object:\n";
	ballon.View();
	objArray.push_back(&ballon);

	cout << "Displaying hasDMA object:\n";
	map.View();
	objArray.push_back(&map);

	cout << "Result of lacksDMA copy:\n";
	lacksDMA ballon2(ballon);
	ballon2.View();

	cout << "Result of hasDMA assignment:\n";
	hasDMA map2;
	map2 = map;
	map2.View();

	cout << endl << "/*Base class pointers:*/\n";
	for (auto x : objArray)
		x->View();
}
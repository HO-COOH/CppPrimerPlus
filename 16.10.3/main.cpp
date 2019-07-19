#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream inFile;//("16-10-3.txt");
	inFile.open("16-10-3.txt");
	if (!inFile.is_open())
	{
		cout << "Can't open file. Bye.\n";
		cin.get();
		return -1;
	}
	string item;
	vector<string>content;
	inFile >> item;
	while (inFile)
	{
		content.push_back(item);
		cout << content.size() << ": " << item << endl;
		inFile >> item;
	}
	cout << "Done\n";
	inFile.close();
	cin.get();
}
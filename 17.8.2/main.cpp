#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
		cout << "Enter the output file as an argument!";
	else
	{
		cout << "The output file is " << argv[1] << endl;
		ofstream outFile(argv[1]);
		if (!outFile.is_open())
			cout << "The file does not exist!\n";
		else
		{
			cout << "Enter your content:\n";
			char c;
			while (cin.get(c) && !cin.eof())
				outFile << c;
			cout << "Done!\n";
			cin.get();
		}
	}
}
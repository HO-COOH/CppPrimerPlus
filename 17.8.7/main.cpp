#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

class Store
{
private:
	ofstream& out;
public:
	Store(ofstream& out) :out(out) {}
	void operator()(const string& str) 
	{ 
		size_t len = str.length();
		out.write((char*)& len, sizeof(size_t));
		out.write(str.data(), len);
	}
};

void ShowStr(const string& str)
{
	cout << str << endl;
}

void GetStrs(ifstream& fin, vector<string>&vs)
{
	while (!fin.eof())
	{
		size_t len = 0;
		fin.read((char*)& len, sizeof(size_t));
		if (fin.eof())
			break;
		string temp;
		for (size_t i = 0; i < len; ++i)
		{
			char c;
			fin.read(&c, 1);
			temp.append(1, c);
		}
		vs.push_back(temp);
	}
}

int main()
{
	vector<string>vostr;
	string temp;

	//acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is yout input.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);
	
	//store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	//recover file contents
	vector<string>vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cout << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);
}
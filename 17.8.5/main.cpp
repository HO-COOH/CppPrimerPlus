#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

const char* matFile = "mat.dat";
const char* patFile = "pat.dat";
const char* bothFile = "matnpat.dat";

int main()
{
	vector<string>mats;
	ifstream in("mat.dat");
	if (!in.is_open())
	{
		cout << "Mat.dat not open!\n";
		in.close();
		return -1;
	}
	string temp;
	cout << "Mat's guest list:\n";
	while (getline(in, temp) && !temp.empty())
	{
		mats.push_back(temp);
		cout << temp << endl;
	}

	vector<string>pats;
	in.close();
	in.open("pat.dat");
	temp.erase();
	if (!in.is_open())
	{
		cout << "pat.dat not open!\n";
		in.close();
		return -1;
	}
	cout << endl << "Pat's guest list:\n";
	while (getline(in, temp) && !temp.empty())
	{
		pats.push_back(temp);
		cout << temp << endl;
	}
	in.close();

	cout << endl << "Merged list:\n";
	vector<string>both(mats);
	both.insert(both.end(), pats.begin(), pats.end());
	sort(both.begin(), both.end());
	both.resize(distance(both.begin(),unique(both.begin(), both.end())));
	ofstream out("matnpat.dat");
	if (!out.is_open())
	{
		cout << "matnpat.dat not open\n";
		out.close();
		return -1;
	}
	ostream_iterator<string, char>display_iter(cout, "\n");
	copy(both.begin(), both.end(), display_iter);
	ostream_iterator<string, char>file_iter(out, "\n");
	copy(both.begin(), both.end(), file_iter);
	out << flush;
	out.close();
	cin.get();
}
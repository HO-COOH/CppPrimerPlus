#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<string>mats;
	string temp;
	cout << "Enter Mat's guest list (empty line to quit):\n";
	while (getline(cin, temp) && temp.size() > 0)
		mats.push_back(temp);
	ostream_iterator<string, char> out(cout, "\n");
	cout << "Mat's guest list:\n";
	copy(mats.begin(), mats.end(), out);

	temp.erase();
	vector<string>pats;
	cout << "Enter Pat's guest list (empty line to quit):\n";
	while (getline(cin, temp) && temp.size() > 0)
		pats.push_back(temp);
	cout << "Pat's guest list:\n";
	copy(pats.begin(), pats.end(), out);

	vector<string>both(mats.size()+pats.size());
	sort(mats.begin(), mats.end());
	sort(pats.begin(), pats.end());
	merge(mats.begin(), mats.end(), pats.begin(), pats.end(), both.begin());
	both.resize(distance(both.begin(),unique(both.begin(),both.end())));
	cout << "Merged list:\n";
	copy(both.begin(), both.end(), out);
}
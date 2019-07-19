#include <string>
#include <iostream>

using namespace std;

bool IsPalindrome(const string& s)
{
	string s_rev(s.rbegin(),s.rend());
	return s == s_rev;
}

int main()
{
	do
	{
		cout << "Enter a string: <q to quit> ";
		string s;
		getline(cin, s);
		if(s=="q"||s=="Q")
			break;
		cout << (IsPalindrome(s) ? "It's a palindrome." : "It's not a palindrome.") << endl;
	} while (true);
}
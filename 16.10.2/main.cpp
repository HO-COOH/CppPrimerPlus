#include <string>
#include <iostream>

using namespace std;

bool IsPalindrome(const string& s)
{
	string s_rev(s.rbegin(), s.rend());
	return s == s_rev;
}

int main()
{
	do
	{
		cout << "Enter a string: <q to quit> ";
		string s;
		char ch;
		cin.get(ch);
		if (ch == '\n')
			continue;
		while (ch != '\n')
		{
			if (isspace(ch)||ispunct(ch))
			{
				cin.get(ch);
				continue;
			}
			ch = tolower(ch);
			//s.append(&ch);
			s.push_back(ch);
			cin.get(ch);
		}
		cout << (IsPalindrome(s) ? "It's a palindrome." : "It's not a palindrome.") << endl;
		if (s == "q" || s == "Q")
			break;
	} while (true);
}
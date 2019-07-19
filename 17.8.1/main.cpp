#include <iostream>

using namespace std;

int main()
{
	char ch;
	int count = 0;
	while (cin.get(ch) && ch != '$')
		++count;
	if (ch == '$')
		cin.putback(ch);
	cout << count << " characters read\n";
	cout << "The next character is : " << (char)cin.peek() << endl;
}
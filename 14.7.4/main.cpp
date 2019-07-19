#include "Person.h"
#include <iostream>

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	Person* p[4];
	for (int i = 0; i < 4; ++i)
	{
		//cout << "Enter the Person's first name: ";
		//string fname;
		//cin >> fname;
		//cout << "And the last name: ";
		//string lname;
		//cin >> lname;
		cout << "Enter the Person category:\np:person\tg:gunslinger\tP:pokerplayer\tb:baddude\tq:quit\n";
		char choice;
		cin >> choice;
		/*switch (choice)
		{
		case 'p':
		{p[i] = new Person(fname, lname);
		break;
		}
		case 'g':
		{
			cout << "Enter the drawtime: ";
			double dt;
			cin >> dt;
			cout << "Enter the number of marks on the gun: ";
			int mark;
			cin >> mark;
			p[i] = new Gunslinger(fname, lname, dt, mark);
			break;
		}
		case 'P':
		{
			p[i] = new PokerPlayer(fname, lname);
			break;
		}
		case 'b':
		{
			cout << "Enter the time for the bad guy to draw the gun: ";
			double gd;
			cin >> gd;
			cout << "Enter the drawtime: ";
			double dt;
			cin >> dt;
			cout << "Enter the number of marks on the gun: ";
			int mark;
			cin >> mark;
			p[i] = new BadDude(fname, lname, dt, mark, gd);
			break;
		}
		}*/
		switch (choice)
		{
		case 'p':
			p[i] = new Person();
			break;
		case 'g':
			p[i] = new Gunslinger();
			break;
		case 'P':
			p[i] = new PokerPlayer();
			break;
		case 'b':
			p[i] = new BadDude();
			break;
		default:
			break;
		}
		p[i]->Set();
	}
	cout << endl << "Data: " << endl;
	for (int i = 0; i < 4; ++i)
	{
		p[i]->Show();
		cout << endl;
		delete p[i];
	}
}
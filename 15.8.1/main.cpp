#include <iostream>
#include "Tv.h"

int main()
{
	using std::cout;
	using std::cin;
	Tv s42;
	cout << "Initial settings for 42\" TV:\n";
	s42.settings();
	s42.onoff();
	s42.chanup();
	cout << "\nAdjusted settings for 42\" TV:\n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.voldown(s42);
	cout << "\n Settings after using remote:\n";
	s42.settings();

	cout << "\n Now you get the remote.\n";

	while (1)
	{
		s42.settings();
		cout << "1: Vol up\t2: Vol down\t3: Chan up\t4: Chan down\n";
		cout<<"5: SwitchMode\t6 : SwitchInput\t7 : Set chan\t8: Power\n";
		int choice;
		cin >> choice;
		if (!cin)
		{
			cin.clear();
			while (!isspace(cin.get()))
				continue;
			continue;
		}
		switch (choice)
		{
		case 1:
			grey.volup(s42);
			break;
		case 2:
			grey.voldown(s42);
			break;
		case 3:
			grey.chanup(s42);
			break;
		case 4:
			grey.chandown(s42);
			break;
		case 5:
			grey.set_mode(s42);
			break;
		case 6:
			grey.set_input(s42);
			break;
		case 7:
			unsigned int channel;
			do
			{
				cout << "Enter the channel to set: ";
				cin >> channel;
			}while(!grey.set_chan(s42, channel));
			break;
		case 8:
			grey.onoff(s42);
			break;
		default:
			continue;
		}
		system("cls");
	}

}
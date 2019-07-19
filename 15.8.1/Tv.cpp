#include "Tv.h"
#include <iostream>

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		++volume;
		return true;
	}
	return false;
}

bool Tv::voldown()
{
	if (volume == 0)
		return false;
	--volume;
	return true;
}

void Tv::chanup()
{
	channel = (channel < maxchannel ? channel + 1 : 1);
}

void Tv::chandown()
{
	channel = (channel == 1 ? maxchannel : channel - 1);
}

void Tv::settings() const
{
	using namespace std;
	cout << "Tv is " << (state == ON ? "On" : "Off") << endl;
	if (state == ON)
	{
		cout << "Volume: " << volume << endl;
		cout << "Channel: " << channel << "\tMaximum Channel: " << maxchannel << endl;
		cout << "Mode: " << (mode == ANTENNA ? "antenna" : "cable") << endl;
		cout << "Input: " << (input == TV ? "TV" : "DVD") << endl;
	}
}

void Tv::switch_remote(Remote& r)
{
	if (state == OFF)
	{
		std::cout << "Tv is off.\n";
		return;
	}
	r.switch_state();
}

bool Remote::set_chan(Tv& t, unsigned int c)
{
	using namespace std;
	if (c > t.maxchannel || c <= 0)
	{
		cout << "Channel number out of range! Try again: \n";
		return false;
	}
	t.channel = c;
	return true;
}

void Remote::show() const
{
	std::cout << "The remote is under " << (state == INTERACTIVE?"interactive":"standard") << " mode.\n";
}
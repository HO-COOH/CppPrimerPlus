#include "Classic.h"
#include <iostream>
#include <string.h>
Classic::Classic(const char* m, const char* performers, const char* label, int se, double pt) :Cd(performers, label, se, pt)
{
	main = new char[strlen(m) + 1];
	strcpy(main, m);
}

Classic::Classic(const char* m, const Cd& d) : Cd(d)
{
	main = new char[strlen(m) + 1];
	strcpy(main, m);
}

Classic::Classic() : Cd()
{
	main = new char[1];
	main[0] = '\0';
}

Classic::~Classic()
{
	delete[] main;
}

Classic& Classic::operator=(const Classic& c)
{
	if (this == &c)
		return *this;
	delete[] main;
	main = new char[strlen(c.main) + 1];
	strcpy(main, c.main);
	Cd::operator=(c);
	return *this;
}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "Main Works: " << main << std::endl;
}
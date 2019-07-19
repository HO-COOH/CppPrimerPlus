#include "Classic.h"
#include <iostream>
#include <string.h>
Classic::Classic(const char* m, const char* performers, const char* label, int se, double pt) :Cd(performers, label, se, pt)
{
	strcpy_s(main, m);
}

Classic::Classic(const char* m, const Cd& d) : Cd(d)
{
	strcpy_s(main, m);
}

Classic::Classic() : Cd()
{}

void Classic::Report() const
{
	Cd::Report();
	std::cout << "Main Works: " << main << std::endl;
}
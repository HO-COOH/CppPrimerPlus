#include "Cd.h"
#include <string.h>
#include <iostream>
Cd::Cd(const char* s1, const char* s2, int n, double x) :selections(n), playtime(x)
{
	strcpy_s(performers, s1);
	strcpy_s(label, s2);
}

Cd::Cd(const Cd& d)
{
	strcpy_s(performers, d.performers);
	strcpy_s(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers[0] = '\0';
	label[0] = '\0';
	playtime = selections = 0;
}

Cd::~Cd()
{
}

void Cd::Report() const
{
	std::cout << "Performers: " << performers << "\tlabel: " << label << std::endl;
	std::cout << "Selections: " << selections << "\tPlaytime: " << playtime << std::endl;
}

Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return *this;
	strcpy_s(performers, d.performers);
	strcpy_s(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
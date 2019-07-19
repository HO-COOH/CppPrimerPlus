#include "Cow.h"
#include <string.h>
#include <iostream>
Cow::Cow()
{
	name[0]='\0';
	hobby = nullptr;
	weight = 0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
	strcpy_s(name, nm);
	hobby = new char[strlen(ho) + 1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow& c)
{
	strcpy_s(name, c.name);
	hobby = new char[strlen(c.hobby) + 1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
	if (this == &c)
		return *this;
	delete[] hobby;
	strcpy_s(name, c.name);
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	using namespace std;
	cout << "Name: " << name << endl;
	cout << "Hobby: " << hobby << endl;
	cout << "Weight= " << weight << endl;
}

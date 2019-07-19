#pragma once
//base class
class Cd
{
	char performers[50];
	char label[20];
	int selections;
	double playtime;	//playing time in minutes
public:
	Cd(const char* s1,const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	~Cd();
	virtual void Report() const;
	Cd& operator=(const Cd& d);
};


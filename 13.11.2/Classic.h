#pragma once

#include "Cd.h"

class Classic :public Cd
{
	char* main;
public:
	Classic(const char* m, const char* performers, const char* label, int se, double pt);
	Classic(const char* m, const Cd& d);
	Classic();
	~Classic();
	Classic& operator=(const Classic& c);
	void Report() const;
};


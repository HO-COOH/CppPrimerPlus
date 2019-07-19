#include "Cd.h"

class Classic :public Cd
{
	char main[50];
public:
	Classic(const char* m, const char* performers, const char* label, int se, double pt);
	Classic(const char* m, const Cd& d);
	Classic();
	void Report() const;
};


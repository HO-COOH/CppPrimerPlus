#include "DMA.h"
#include <string.h>
/*base*/
base::base(const char* la, int r):rating(r)
{
	label = new char[strlen(la) + 1];
	strcpy(label, la);
}

base::base()
{
	label = new char[1];
	label[0] = '\0';
	rating = 0;
}

base::base(const base& b)
{
	label = new char[strlen(b.label) + 1];
	strcpy(label, b.label);
	rating = b.rating;
}

base& base::operator=(const base& b)
{
	if (this == &b)
		return *this;
	delete[] label;
	label = new char[strlen(b.label) + 1];
	strcpy(label, b.label);
	rating = b.rating;
}

base::~base()
{
	delete[] label;
}

void base::View()
{
	std::cout << "Label: " << label << "\tRating: " << rating ;
}

/*baseDMA*/

baseDMA::baseDMA(const char* l, int r):base(l,r)
{
}

baseDMA::~baseDMA()
{
}

void baseDMA::View()
{
	base::View();
	std::cout << std::endl;
}

/*lacksDMA*/
lacksDMA::lacksDMA(const char* c, const char* l, int r) :base(l, r)
{
	strcpy(color, c);
}

lacksDMA::lacksDMA(const char* c, const base& rs):base(rs)
{
	strcpy(color, c);
}

void lacksDMA::View()
{
	base::View();
	std::cout << "\tColor: " << color << std::endl;
}

/*hasDMA*/
hasDMA::hasDMA(const char* s, const char* l, int r) :base(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const base& rs) :base(rs)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs):base(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

void hasDMA::View()
{
	base::View();
	std::cout << "\tStyle: " << style << std::endl;
}

hasDMA& hasDMA::operator=(const hasDMA& rs)
{
	if (this == &rs)
		return *this;
	delete[] style;
	base::operator=(rs);
	style = new char[strlen(rs.style) + 1];
	strcpy(style, rs.style);
}


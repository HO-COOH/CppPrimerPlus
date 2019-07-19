#pragma once
#include <iostream>

class base
{
	char* label;
	int rating;
public:
	base(const char* la, int r);
	base();
	base(const base& b);
	base& operator=(const base& b);
	virtual ~base();
	virtual void View() = 0;
	//virtual friend std::ostream& operator<<(std::ostream& os, const base& b);
};

class baseDMA :public base
{
public:
	baseDMA(const char* l = "null", int r = 0);
	//baseDMA(const baseDMA& rs);
	virtual ~baseDMA();
	//baseDMA& operator=(const baseDMA& rs);  //no need for explicit assignment operator function
	//friend std::ostream& operator<<(std::ostream& os, const baseDMA& b);
	void View();
};

class lacksDMA :public base
{
	enum { COL_LEN = 40 };
	char color[COL_LEN];
public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const base& rs);
	void View();
};

class hasDMA :public base
{
	char* style;
public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const base& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	void View();
	hasDMA& operator=(const hasDMA& rs);
};
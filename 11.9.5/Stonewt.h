#pragma once
#include <iostream>
class Stonewt
{
public:
	enum Mode { STONE, WHOLE_POUNDS, FRACTIONAL_POUNDS };
private:
	enum {Lbs_per_stn=14};//pounds per stone
	int stone;
	double pds_left;
	double pounds;	//entire weight in pounds
	Mode mode;
public:
	Stonewt(double lbs);			//total lbs
	Stonewt(int stn, double lbs);	//stone, lbs
	Stonewt();
	~Stonewt();
	void setMode(Mode m);
	Stonewt operator+(const Stonewt& s) const;
	Stonewt operator-(const Stonewt& s) const;
	Stonewt operator*(double n) const;
	friend std::ostream& operator<<(std::ostream& os, Stonewt& st);
	friend Stonewt operator*(double n, const Stonewt& s);
};


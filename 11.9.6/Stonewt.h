#pragma once
#include <iostream>
class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };//pounds per stone
	int stone;
	double pds_left;
	double pounds;	//entire weight in pounds	
public:
	Stonewt(double lbs);			//total lbs
	Stonewt(int stn, double lbs);	//stone, lbs
	Stonewt();
	~Stonewt();
	void show_lbs() const;
	void show_stn() const;
	bool operator>(const Stonewt& s);
	bool operator>=(const Stonewt& s);
	bool operator<(const Stonewt& s);
	bool operator<=(const Stonewt& s);
	bool operator==(const Stonewt& s);
	bool operator!=(const Stonewt& s);
};



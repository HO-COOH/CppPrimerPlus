#include "Stonewt.h"
Stonewt::Stonewt(double lbs) :stone(int(lbs / Lbs_per_stn)), pds_left((int)lbs% Lbs_per_stn), pounds(lbs), mode(WHOLE_POUNDS)
{
}

Stonewt::Stonewt(int stn, double lbs) : stone(stn), pds_left(lbs), pounds(stn* Lbs_per_stn + lbs), mode(FRACTIONAL_POUNDS)
{
}

Stonewt::Stonewt() : stone(0), pds_left(0), pounds(0), mode(STONE)
{
}

Stonewt::~Stonewt() {}

void Stonewt::setMode(Mode m)
{
	mode = m;
}

Stonewt Stonewt::operator+(const Stonewt& s) const
{
	return Stonewt(pounds + s.pounds);
}

Stonewt Stonewt::operator-(const Stonewt& s) const
{
	return Stonewt(pounds - s.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
	return Stonewt(pounds * n);
}



std::ostream& operator<<(std::ostream& os, Stonewt& st)
{
	switch (st.mode)
	{
	case Stonewt::STONE:
		os << (double)st.stone + st.pds_left / (double)Stonewt::Lbs_per_stn << " stone\n";
		break;
	case Stonewt::WHOLE_POUNDS:
		os << st.pounds << " pounds\n";
		break;
	case Stonewt::FRACTIONAL_POUNDS:
		os << st.stone << " stone, " << st.pds_left << " pounds\n";
	}
	return os;
}

Stonewt operator*(double n, const Stonewt& s)
{
	return s * n;
}
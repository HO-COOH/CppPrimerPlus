#include "Time.h"
Time::Time():hours(0),minutes(0)
{}
Time::Time(int h, int m):hours(h),minutes(m)
{}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}
void Time::AddHr(int h)
{
	hours += h;
}
void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time& t1, const Time& t2)
{
	return Time(t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60, (t1.minutes + t2.minutes) % 60);
}

Time operator-(const Time& t1, const Time& t2)
{
	return Time(t1.hours - t2.hours - (t1.minutes > t2.minutes ? 0 : 1), (t1.minutes > t2.minutes ? t1.minutes - t2.minutes : t1.minutes + 60 - t2.minutes));
}

Time operator*(const Time& t, double n)
{
	return Time((t.hours * 60 + t.minutes) * n / 60, (long)((t.hours * 60 + t.minutes) * n) % 60);
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}
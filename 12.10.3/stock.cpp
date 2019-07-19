#include "stock.h"
#include <string.h>

Stock::Stock()
{
	company = new char[1];
	company[0] = '\0';
	share_val = total_val = 0.0;
	shares = 0;
}

Stock::Stock(const char* co, long n, double pr)
{
	company = new char[strlen(co)+1];
	strcpy(company, co);
	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; " << company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	delete[] company;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
		std::cout << "Number of shares purchased can't be negative. Transcation is aborted.\n";
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0)
		cout << "Number of shares purchased can't be negative. Transcation is aborted.\n";
	else if (num > shares)
		cout << "You can't sell more than you have! Transcation is aborted.\n";
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

const Stock& Stock::topval(const Stock& s) const
{
	return (s.total_val > total_val ? s : *this);
}

std::ostream& operator<<(std::ostream& os, const Stock& s)
{
	using std::ios_base;
	auto orig = os.setf(ios_base::fixed, ios_base::floatfield);
	auto prec = os.precision(3);
	os << "Company: " << s.company << " Shares: " << s.shares << '\n';
	os << " Share Price: $" << s.share_val;
	os.precision(2);
	os << " Total Worth: $" << s.total_val << '\n';

	os.setf(orig, ios_base::floatfield);
	os.precision(prec);
	return os;
}
#include "emp.h"
using std::cout;
using std::cin;
using std::endl;
/*abstr_emp*/
abstr_emp::abstr_emp()
{
}

abstr_emp::abstr_emp(const string& fn, const string& ln, const string& j) :fname(fn), lname(ln), job(j)
{
}

void abstr_emp::ShowAll() const
{
	cout << "Name (f,l) : " << fname << " ," << lname << endl;
	cout << "Job: " << job << endl;
}

void abstr_emp::SetAll()
{
	cout << "Enter first name: ";
	cin >> fname;
	cout << "Enter last name: ";
	cin >> lname;
	cout << "What job?";
	cin >> job;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
	os << "Name (f,l) : " << e.fname << " ," << e.lname << endl;
	return os;
}

abstr_emp::~abstr_emp() {}

/*employee*/
employee::employee()
{
}

employee::employee(const string& fn, const string& ln, const string& j) :abstr_emp(fn, ln, j)
{
}

void employee::ShowAll() const
{
	cout << "Category: Employee\n";
	abstr_emp::ShowAll();
}

void employee::SetAll()
{
	abstr_emp::SetAll();
}

/*manager*/
manager::manager()
{
}

manager::manager(const string& fn, const string& ln, const string& j, int ico):abstr_emp(fn,ln,j),inchargeof(ico)
{
}

manager::manager(const abstr_emp& e, int ico) : abstr_emp(e), inchargeof(ico)
{
}

manager::manager(const manager& m):abstr_emp(m),inchargeof(m.inchargeof)
{
}

void manager::ShowAll() const
{
	cout << "Category: Manager\n";
	abstr_emp::ShowAll();
	cout << "In charge of " << inchargeof << " employees.\n";
}

void manager::SetAll()
{
	abstr_emp::SetAll();
	cout << "How many employees is he/she in charge of?";
	cin >> inchargeof;
}

/*fink*/
fink::fink()
{
}

fink::fink(const string& fn, const string& ln, const string& j, const string& rpo):abstr_emp(fn,ln,j),reportsto(rpo)
{
}

fink::fink(const abstr_emp& e, const string& rpo):abstr_emp(e),reportsto(rpo)
{
}

fink::fink(const fink& e) : abstr_emp(e), reportsto(e.reportsto)
{
}

void fink::ShowAll() const
{
	cout << "Category: Fink\n";
	abstr_emp::ShowAll();
	cout << "Reports to: " << reportsto << endl;
}

void fink::SetAll()
{
	abstr_emp::SetAll();
	cout << "Reports to whom?";
	cin >> reportsto;
}

/*highfink*/
highfink::highfink()
{
}

highfink::highfink(const string& fn, const string& ln, const string& j, const string& rpo, int ico):abstr_emp(fn,ln,j),fink(fn,ln,j,rpo),manager(fn,ln,j,ico)
{
}

highfink::highfink(const abstr_emp& e, const string& rpo, int ico):abstr_emp(e),fink(e,rpo),manager(e,ico)
{
}

highfink::highfink(const fink& f, int ico):fink(f),manager(f,ico),abstr_emp(f)
{
}

highfink::highfink(const manager& m, const string& rpo):manager(m),fink(m,rpo), abstr_emp(m)//? abstr_emp?
{
}

highfink::highfink(const highfink& h):manager(h),fink(h),abstr_emp(h)
{
}

void highfink::ShowAll() const
{
	cout << "Category: Highfink\n";
	abstr_emp::ShowAll();
	cout << "Reports to: " << fink::ReportsTo() << endl;
	cout << "In charge of " << manager::InChargeOf() << " employees.\n";
}

void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout << "How many employees is he/she in charge of?";
	cin >> InChargeOf();
	cout << "Reports to whom?";
	cin >> ReportsTo();
}
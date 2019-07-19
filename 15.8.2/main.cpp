#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
using namespace std;

class bad_hmean:public logic_error
{
private:
	double v1;
	double v2;
	string error="hmean invalid arguments: a=" + to_string(v1) + " b=" + to_string(v2) + " a=-b";;
public:
	bad_hmean(double a = 0, double b = 0) :v1(a), v2(b), logic_error("hmean invalid arguments") {   }
	const char* what() const
	{
		cout << error << endl;
		return "bullshit1";
	}
};

class bad_gmean:public logic_error
{
private:
	double v1;
	double v2;
	string error = "gmean invalid arguments: a=" + to_string(v1) + " b=" + to_string(v2) + " a or b<0";
public:
	bad_gmean(double a = 0, double b = 0) :v1(a), v2(b), logic_error("gmean invalid arguments") {}
	const char* what() const
	{
		cout << error << endl;
		return "bullshit2";
	}
};

auto hmean(double a, double b) ->double
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

auto gmean(double a, double b) ->double
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return sqrt(a * b);
}

int main()
{
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try 
		{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (logic_error& lg)
		{
			lg.what();
			cout << "Try again.\n";
			continue;
		}
	}
	cout << "Bye!\n";
}
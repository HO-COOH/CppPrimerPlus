#include <iostream>

using namespace std;

//long double sum_value()
//{
//	return (long double)0;
//}

template<typename T>
long double sum_value(T value)
{
	return (long double)value;
}

template<typename T, typename ...Args>
long double sum_value(T a, Args...args)
{
	long double sum = 0;
	sum = a + sum_value(args...);
	return sum;
}

int main()
{
	cout << sum_value(2, 3, 4, 5);
}
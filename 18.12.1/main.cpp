#include <iostream>
#include <initializer_list>
#include <algorithm>

using namespace std;

template<typename T>
auto average_list(initializer_list<T> nums)
{
	if (nums.size() == 0)
		return (T)0;
	T sum = 0;
	for_each(nums.begin(), nums.end(), [&sum](const T& x) {sum += x; });
	return sum /= nums.size();
}

int main()
{
	//list of double deduced from list contents
	auto q = average_list({ 15.4,10.7,9.0 });
	cout << q << endl;
	//list of int deduced from list contents
	cout << average_list({ 20,30,19,17,45,38 }) << endl;
	//forced list of double
	auto ad = average_list<double>({ 'A',70,65.33 });
	cout << ad << endl;
}

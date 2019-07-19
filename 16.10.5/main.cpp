#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
auto reduce(T ar[], int n)
{
	T* pt = unique(ar, ar + n);
	sort(ar, pt);
	return distance(ar, pt);
}

int main()
{
	cout << "How many numbers in total?";
	int n;
	cin >> n;
	long* arr = new long[n];
	for (int i = 0; i < n; ++i)
	{
		cout << "Enter the number: ";
		cin >> arr[i];
	}
	int count = reduce(arr, n);
	cout << "There are " << count << " numbers that are unique.\n";
	for (int i = 0; i < count; ++i)
	{
		cout << arr[i] << " ";
		if (i % 5 == 4)
			cout << endl;
	}
	delete[] arr;
}
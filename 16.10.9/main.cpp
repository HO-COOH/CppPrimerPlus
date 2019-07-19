#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

template<int n>
void test100k()
{
	srand(time(NULL));
	vector<int> vi0(n);
	//for_each(vi0.begin(), vi0.end(), [](int a) {return rand(); });
	for (auto& x : vi0)
		x = rand()+1;
	vector<int> vi(n);
	copy(vi0.begin(), vi0.end(), vi.begin());
	
	clock_t start1 = clock();
	sort(vi.begin(), vi.end());
	clock_t dur1 = clock() - start1;
	cout << "Sort vector time: " << (double)dur1 / CLOCKS_PER_SEC<<endl;

	list<int>li(n);
	copy(vi0.begin(), vi0.end(), li.begin());
	auto start2 = clock();
	li.sort();
	auto dur2 = clock() - start2;
	cout << "Sort list time: " << (double)dur2 / CLOCKS_PER_SEC<<endl;

	list<int>li2(n);
	copy(vi0.begin(), vi0.end(), li2.begin());
	vector<int>vi2(n);
	auto start3 = clock();
	copy(li2.begin(), li2.end(), vi2.begin());
	sort(vi2.begin(), vi2.end());
	copy(vi2.begin(), vi2.end(), li2.begin());
	auto dur3 = clock() - start3;
	cout << "List->Vector Sort(Vector) Vector->List time: " << (double)dur3 / CLOCKS_PER_SEC << endl;
}


int main()
{
	test100k<100000>();
	cin.get();
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

//auto Lotto(int dotCount, int num)
//{
//	int *p=new int[dotCount];
//	for (int i = 0; i < dotCount; ++i)
//		p[i] = (i + 1);
//	random_shuffle(p, p + dotCount);
//	vector<int>winner(p, p + num);
//	delete[] p;
//	return winner;
//}
auto Lotto(int dotCount, int num)
{
	unique_ptr<int[]>p (new int[dotCount]);
	for (int i = 0; i < dotCount; ++i)
		p[i] = (i + 1);
	random_shuffle(p.get(), &p[dotCount]);
	return vector<int>(p.get(), &p[num]);
}

int main()
{
	cout << "Enter the number of dots on the card: ";
	int dot;
	cin >> dot;
	cout << "Enter how many times to choose from: ";
	int num;
	cin >> num;
	auto winners = Lotto(dot, num);
	for (auto& x : winners)
		cout << x << endl;
}
#include "Sales.h"
#include <iostream>
using namespace SALES;
using namespace std;
Sales::Sales(const double ar[], int n)
{
	const int count = (4 > n ? n : 4);
	copy(ar, &ar[count], sales);
	max = sales[0];
	min = sales[0];
	double sum = 0.0;
	for (int i = 0; i < count; ++i)
	{
		max = (sales[i] > max ? sales[i] : max);
		min = (sales[i] < min ? sales[i] : min);
		sum += sales[i];
	}
	average = sum / (double)count;
}
void Sales::setSales()
{
	for (int i = 0; i < 4; ++i)
	{
		double sale;
		cout << "Enter the sale of the " << i << "quarter ->";
		cin >> sale;
		cout << endl;
		sales[i] = sale;
	}
	max = min = sales[0];
	double sum = 0;
	for (int i = 0; i < 4; ++i)
	{
		max = (sales[i] > max ? sales[i] : max);
		min = (sales[i] < min ? sales[i] : min);
		sum += sales[i];
	}
	average = sum / 4.0;
}

void Sales::showSales()
{
	for (int i = 0; i < QUARTERS; ++i)
	{
		cout << "The " << i << "quarter sale is: " << sales[i] << endl;
	}
	cout << "Average= " << average << " ,max= " << max << " ,min=" << min;
}

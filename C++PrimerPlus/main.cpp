#include "Sales.h"

using namespace SALES;
int main()
{
	double arr[4]{ 45.3,23.0,30,20 };
	Sales s1(arr, 4);
	Sales s2;
	s1.showSales();
	s2.setSales();
	s2.showSales();
}
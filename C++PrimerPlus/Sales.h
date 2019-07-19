#pragma once
namespace SALES
{
	const int QUARTERS = 4;
	class Sales
	{
		double sales[QUARTERS]{ 0 };
		double average=0;
		double max=0;
		double min=0;
		//copy the lesser of 4 or n items from the array ar
		//to the sales member of s and computes and stores the
		//average, maximum, and minimum values of the entered items;
		//remaining elements of sales, if any, set to 0
	public:
		Sales() {};
		Sales(const double ar[], int n);
		//gathers sales for 4 quarters interactively, stores them
		//in the sales member of s and computes and stores the 
		//average, maximum, and minimum values
		void setSales();
		//display all information in structure s -> class s
		void showSales();
	};
}
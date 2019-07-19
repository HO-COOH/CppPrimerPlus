#include "Stack.h"
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	Stack customers;
	do
	{
		customer item;
		cout << "Enter the fullname of the customer (q to stop) -> ";
		cin >> item.fullname;
		if (!strcmp(item.fullname, "q"))
			break;
		cout << "Enter the payment -> ";
		cin >> item.payment;
		customers.push(item);
	} while (!customers.isfull());
	int i = 1;
	double sum = 0;
	while (!customers.isempty())
	{
		customer item;
		customers.pop(item);
		cout << "The fullname of customer " << i << "is " << item.fullname<<" and the payment is "<<item.payment<<endl;
		sum += item.payment;
	}
	cout << "The total payment is -> " << sum << endl;
}
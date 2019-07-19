#include <iostream>
#include <cstdlib>	//rand() srand()
#include <ctime>	//time()
#include "Queue.h"
const int MIN_PER_HR = 60;
using namespace std;
bool newCustomer(double x)	//x:average interval time between a new customer
{
	return (rand() * x / RAND_MAX < 1);
}

int main()
{
	cout << "Enter the maximum size of the queue -> ";
	int qs;
	cin >> qs;
	
	
	cout << "Enter the number of simulation hours -> ";
	long cycleLimit;
	cin >> cycleLimit;
	cycleLimit *= MIN_PER_HR;
	char ch;
	do
	{	cout << "Enter the average number of customers per hour -> ";
		int perHour;
		cin >> perHour;
		Queue line(qs);
		auto interval = (double)MIN_PER_HR / perHour;
		long turnAways = 0;
		long customers = 0;
		long served = 0;
		long sumLine = 0;
		long waitTime = 0;
		long line_wait = 0;
		Item temp;
		for (int cycle = 0; cycle < cycleLimit; ++cycle)
		{
			if (newCustomer(interval))	//have newcomer
			{
				if (line.isfull())	//if the line is full -> customer turn away
					++turnAways;
				else				//if the line is not full -> customer wait in line
				{
					++customers;
					temp.set(cycle);
					line.enqueue(temp);
				}
			}
			if (waitTime <= 0 && !line.isempty())
			{
				line.dequeue(temp);
				waitTime = temp.ptime();
				line_wait += cycle - temp.when();
				++served;
			}
			if (waitTime > 0)
				--waitTime;
			sumLine += line.queuecount();
		}
		double avgWait = (double)line_wait / served;
		if (avgWait > 1)
			cout << "The Average Waiting Time is higher than required\n";
		cout << "Customers accepted: " << customers << "customers served: " << served << endl;
		cout << "Average Waiting time= " << avgWait << endl << "Try again? -> ";
		cin >> ch;
	} while (ch=='y');
}

//OUTPUT:
//Enter the maximum size of the queue -> 10
//Enter the number of simulation hours -> 100
//Enter the average number of customers per hour -> 15
//Customers accepted : 1484customers served : 1484
//Average Waiting time = 0.680593
//Try again ? ->y
//Enter the average number of customers per hour -> 16
//Customers accepted : 1605customers served : 1604
//Average Waiting time = 0.715711
//Try again ? ->y
//Enter the average number of customers per hour -> 17
//Customers accepted : 1680customers served : 1680
//Average Waiting time = 0.770833
//Try again ? ->y
//Enter the average number of customers per hour -> 18
//Customers accepted : 1790customers served : 1790
//Average Waiting time = 0.906704
//Try again ? ->y
//Enter the average number of customers per hour -> 19
//The Average Waiting Time is higher than required
//Customers accepted : 1863customers served : 1863
//Average Waiting time = 1.05582
//Try again ? ->
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
	{
		cout << "Enter the average number of customers per hour -> ";
		int perHour;
		cin >> perHour;
		Queue line[2]{ (qs),(qs) };
		auto interval = (double)MIN_PER_HR / perHour;
		long turnAways = 0;
		long customers = 0;
		long served = 0;
		long sumLine[2]{ 0,0 };
		long waitTime[2]{ 0,0 };
		long line_wait[2]{ 0,0 };
		Item temp;
		for (int cycle = 0; cycle < cycleLimit; ++cycle)
		{
			if (newCustomer(interval))	//have newcomer
			{
				if (line[0].isfull()&&line[1].isfull())	//if the line is full -> customer turn away
					++turnAways;
				else				//if either line is not full -> customer wait in line
				{
					++customers;
					temp.set(cycle);
					if (line[0].queuecount() >= line[1].queuecount())	//if line1 > line2, enqueue line2
						line[1].enqueue(temp);
					else
						line[0].enqueue(temp);
				}
			}
			for (int i = 0; i < 2; ++i)	//for each line, if line is not empty, and the last customer is finished, dequeue it
			{
				if (waitTime[i] <= 0 && !line[i].isempty())
				{
					line[i].dequeue(temp);
					waitTime[i] = temp.ptime();
					line_wait[i] += cycle - temp.when();
					++served;
				}
				if (waitTime[i] > 0)
				--waitTime[i];
				sumLine[i] += line[i].queuecount();
			}
		}
		double avgWait = (double)((double)line_wait[0]+ (double)line_wait[1]) / served;
		if (avgWait > 1)
			cout << "The Average Waiting Time is higher than required\n";
		cout << "Customers accepted: " << customers << "customers served: " << served << endl;
		cout << "Average Waiting time= " << avgWait << endl << "Try again? -> ";
		cin >> ch;
	} while (ch == 'y');
}

//OUTPUT:
//Enter the maximum size of the queue -> 10
//Enter the number of simulation hours -> 100
//Enter the average number of customers per hour -> 20
//Customers accepted : 1958customers served : 1958
//Average Waiting time = 0.358529
//Try again ? ->y
//Enter the average number of customers per hour -> 30
//Customers accepted : 2982customers served : 2982
//Average Waiting time = 0.506036
//Try again ? ->y
//Enter the average number of customers per hour -> 40
//Customers accepted : 3999customers served : 3998
//Average Waiting time = 0.622311
//Try again ? ->y
//Enter the average number of customers per hour -> 50
//Customers accepted : 4965customers served : 4964
//Average Waiting time = 0.935133
//Try again ? ->y
//Enter the average number of customers per hour -> 60
//The Average Waiting Time is higher than required
//Customers accepted : 5995customers served : 5993
//Average Waiting time = 8.25179
//Try again ? ->y
//Enter the average number of customers per hour -> 50
//Customers accepted : 4999customers served : 4998
//Average Waiting time = 0.914566
//Try again ? ->y
//Enter the average number of customers per hour -> 52
//The Average Waiting Time is higher than required
//Customers accepted : 5178customers served : 5177
//Average Waiting time = 1.00811
//Try again ? ->
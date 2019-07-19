#include "QueueTp.h"
#include "Worker.h"
#include <iostream>
#include <cstring>
const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	Queue<Worker*> workerQueue(SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		cout << "Enter the employee category:\nw:waiter\ts:singer\tt:singing waiter\tq:quit\n";
		char choice;
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter w, s, t, q: ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		Worker* temp=nullptr;
		switch (choice)
		{
		case 'w':
			temp = new Waiter;
			break;
		case 's':
			temp = new Singer;
			break;
		case 't':
			temp = new SingingWaiter;
			break;
		}
		cin.get();
		temp->Set();
		workerQueue.enqueue(temp);
	}
	Worker* temp;
	cout << endl << "Here is your staff:\n";
	while (workerQueue.dequeue(temp))
	{
		temp->Show();
		cout << endl;
		delete temp;
	}
	cout << "Bye.\n";
}
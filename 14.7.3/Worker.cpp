#include "Worker.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/*Worker*/
void Worker::Data() const
{
	cout << "Name: " << fullname << endl;
	cout << "Emplyee ID: " << id << endl;
}

void Worker::Get()
{
	std::getline(cin, fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

Worker::~Worker() {}

/*Waiter*/
void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}

void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Set()
{
	cout << "Enter waiter's name: ";
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Data();
	Data();
}

/*Singer*/
const char* Singer::pv[Singer::Vtypes] = { "other","alto","contralto","soprano","bass","baritone","tenor" };

void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Data();
	Data();
}

void Singer::Get()
{
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for (i = 0; i < Vtypes; ++i)
	{
		cout << i << ": " << pv[i] << "  ";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << '\n';
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

void Singer::Set()
{
	cout << "Enter singer's name: ";
	Worker::Get();
	Get();
}

/*SiningWaiter*/
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}

void SingingWaiter::Get()
{
	Singer::Get();
	Waiter::Get();
}

void SingingWaiter::Set()
{
	cout << "Enter singing waiter's name: ";
	Worker::Get();
	Get();
}

void SingingWaiter::Show() const
{
	cout << "Category: singing waiter\n";
	Worker::Data();
	Data();
}
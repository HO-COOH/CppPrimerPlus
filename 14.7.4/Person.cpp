#include "Person.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
/*Person*/
void Person::Show() const
{
	cout << "Category: Person\n";
	Data();
}

void Person::Data() const
{
	cout << "Name: " << fname << " ," << lname << endl;
}

void Person::Get()
{
	cout << "Enter first name: ";
	cin >> fname;
	cout << "Enter last name: ";
	cin >> lname;
}

void Person::Set()
{
	Get();
}

/*Gunslinger*/
double Gunslinger::Draw() const
{
	return drawTime;
}

void Gunslinger::Data() const
{
	cout << "The draw time: " << drawTime << " and there are " << mark << " on the gun.\n";
}

void Gunslinger::Get()
{
	cout << "Enter the draw time: ";
	cin >> drawTime;
	cout << "How many marks are there on the gun?";
	cin >> mark;
}

void Gunslinger::Show() const
{
	cout << "Category: Gunslinger\n";
	Person::Show();
	Data();
}

void Gunslinger::Set()
{
	Person::Get();
	Get();
}

/*PokerPlayer*/
int PokerPlayer::Draw() const
{
	srand(time(NULL));
	return (rand() % 52 + 1);
}

void PokerPlayer::Data() const
{
}

void PokerPlayer::Show() const
{
	cout << "Category: PokerPlayer\n";
	Person::Data();
}

void PokerPlayer::Get()
{
	
}

void PokerPlayer::Set()
{
	Person::Get();
}

/*BadDude*/
void BadDude::Data() const
{
	Gunslinger::Data();
	PokerPlayer::Data();
	cout << "The bad dude draws the gun in " << gdraw << " time."<< endl;
}

void BadDude::Get()
{
	cout << "Enter how long it takes for the bad dude to draw his gun: ";
	cin >> gdraw;
}

double BadDude::Gdraw() const
{
	return gdraw;
}

int BadDude::Cdraw()
{
	return PokerPlayer::Draw();
}

void BadDude::Show() const
{
	cout << "Category: BadDude\n";
	Person::Show();
	Data();
}

void BadDude::Set()
{
	Person::Get();
	Gunslinger::Get();
	PokerPlayer::Get();
	Get();
}
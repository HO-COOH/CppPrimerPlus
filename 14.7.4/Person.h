#pragma once
#include <string>
using std::string;

class Person
{
	string fname;
	string lname;
protected:
	void Data() const;
public:
	Person() {}
	Person(string f, string l) :fname(f), lname(l) {}
	virtual void Show() const;
	virtual ~Person() {}
	virtual void Get();
	virtual void Set();
};

class Gunslinger :virtual public Person
{
	double drawTime;
	int mark;
protected:
	void Data() const;
	void Get();
public:
	Gunslinger() :Person() {}
	Gunslinger(string first, string last, double t=0, int m=0) :Person(first,last),drawTime(t), mark(m) {}
	Gunslinger(const Person& p, double t=0, int m=0) :Person(p), drawTime(t),mark(0) {}
	double Draw() const;
	virtual void Show() const;
	void Set();
};

class PokerPlayer :virtual public Person
{
protected:
	void Data() const;
	void Get();
public:
	PokerPlayer() :Person() {}
	PokerPlayer(string f, string l) :Person(f, l) {}
	PokerPlayer(const Person& p) :Person(p) {}
	int Draw() const;	//return a random int number in 1-52
	virtual void Show() const;
	void Set();
};

class BadDude :public Gunslinger, public PokerPlayer
{
	double gdraw;
protected:
	void Data() const;
	void Get();
public:
	BadDude() :Gunslinger(), PokerPlayer(),Person() {}
	BadDude(string f, string l, double t = 0, int m = 0, double gd=0) :gdraw(gd),Gunslinger(f,l,t, m), PokerPlayer(), Person(f, l) {}
	double Gdraw() const;
	int Cdraw();
	void Show() const;
	void Set();
};


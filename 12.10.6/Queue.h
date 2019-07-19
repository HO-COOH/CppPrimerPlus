#pragma once

class Customer
{
	long arrive;		//arrival time
	int processtime;	//time for process the customer
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;
class Queue
{
	struct Node
	{
		Item item;
		Node* next;
	};
	enum { Q_SIZE = 10 };
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	Queue(const Queue& q) = delete;	//prevent public copying
	Queue& operator=(const Queue& q) = delete;
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};


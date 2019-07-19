#include "Queue.h"
#include <cstdlib>   //rand()

Queue::Queue(int qs):front(nullptr),rear(nullptr),items(0),qsize(qs)
{
}

Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = nullptr;
	if (items++)
		rear->next = newNode;
	else
		front = newNode;
	rear = newNode;
	//++items;
	//if (front == nullptr)
	//	front = newNode;
	//else
	//	rear->next = newNode;
	//rear = newNode;
	return true;
}

bool Queue::dequeue(Item& item)
{
	if (isempty())
		return false;
	item = front->item;
	if (--items)
	{	//more one item in the queue
		Node* temp = front;
		front = front->next;
		delete temp;
	}
	else
	{
		rear = nullptr;
		front = nullptr;
	}
	return true;
}

void Customer::set(long when)
{
	arrive = when;
	processtime = std::rand() % 3 + 1;	//the process time is from 1-3 minutes
}
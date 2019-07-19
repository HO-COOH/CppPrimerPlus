#pragma once
template<typename T>
class Queue
{
	struct Node
	{
		T item;
		Node* next;
	};
	Node* front;
	Node* rear;
	int items;
	const int qsize;
	Queue(const Queue& q) = delete;
	Queue& operator=(const Queue& q) = delete;
public:
	Queue(int qs);
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int QueueCount() const;
	bool enqueue(const T& item);
	bool dequeue(T& item);
};

template<typename T>
Queue<T>::Queue(int qs) :qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

template<typename T>
Queue<T>::~Queue()
{
	while (front != nullptr)
	{
		Node* temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename T>
bool Queue<T>::isempty() const
{
	return items == 0;
}

template<typename T>
bool Queue<T>::isfull() const
{
	return items == qsize;
}

template<typename T>
int Queue<T>::QueueCount() const
{
	return items;
}

template<typename T>
bool Queue<T>::dequeue(T& item)
{
	if (isempty())
		return false;
	item = front->item;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (--items)
		rear = nullptr;
	return true;
}

template<typename T>
bool Queue<T>::enqueue(const T& item)
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
	return true;
}
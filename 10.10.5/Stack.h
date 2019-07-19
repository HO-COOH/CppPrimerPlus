#pragma once
struct customer
{
	char fullname[35];
	double payment;
};
typedef customer Item;
class Stack
{
	enum {MAX=10};
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	//push() returns false if stack already is full, true otherwise
	bool push(const Item& item);	//add item to stack
	//pop() returns false if stack already is empty, true otherwise
	bool pop(Item& item);	//pop top item
};


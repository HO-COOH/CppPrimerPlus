#pragma once
typedef unsigned long Item;

class Stack
{
	enum {MAX=10};
	Item* pitems;	//holds stack items
	int size;
	int top;		//index for top stack item
public:
	Stack(int n = MAX);	//create stack with n elements
	Stack(const Stack& st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	//push() returns false if stack already is full, true otherwise
	bool push(const Item& item);	//add item to stack
	//pop() retruns false if stack already is empty, true otherwise
	bool pop(Item& item);	//pop top into item
	Stack& operator=(const Stack& st);
};


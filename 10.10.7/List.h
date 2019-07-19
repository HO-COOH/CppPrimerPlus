#pragma once
typedef  Item;
class List
{
	char* data;
	int size;
	int used;
public:
	List(int size = 0);
	~List();
	bool addItem(const Item & item);
	bool isEmpty();
	bool isFull();
	void visit(void (*pf)(Item&));
};


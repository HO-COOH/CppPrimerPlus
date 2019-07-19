#include "List.h"
#include <string.h>
List::List(int size) :size(size), used(0)
{
	data = new char[size];
}

List::~List()
{
	delete[] data;
}

bool List::isEmpty()
{
	return used == 0;
}

bool List::isFull()
{
	return used == size;
}

bool List::addItem(const Item& item)
{
	if (!isFull())
	{
		memcpy(data + used*sizeof(item), &item, sizeof(item));
		++used;
		return true;
	}
	return false;
}

void List::visit(void (*pf)(Item&))
{
	for (int i = 0; i < used; ++i)
	{
		pf((Item) * (data[i * sizeof(Item)]));
	}
}

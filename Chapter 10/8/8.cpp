#include "8.h"


bool List::isempty()
{
	return this->count == 0;
}

bool List::isfull()
{
	return this->count == SIZE;
}

void List::add(Item i)
{
	this->item[this->count] = i;
	this->count++;
}

void List::visit(void (*pf)(Item &))
{
	for(int i = 0; i < count; i++)
	{
		pf(this->item[i]);
	}
}

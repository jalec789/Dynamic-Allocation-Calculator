#include "hw09.h"

largeInts::largeInts()
{
	number *b;
	b = new number;

	b->single = '0';		//MAKE THIS NULL OR MAKE THIS ZERO
	b->next = NULL;
	b->prev = NULL;

	this->first = b;
	this->last = b;
	this->neg = false;
//	length = 1;
}


#include "hw09.h"


largeInts& largeInts::clearup() //reset entire number to zero function
{
	number *traverse;
	traverse = this->first;

	while(traverse->next != NULL)
	{
		traverse = traverse->next;
		delete traverse->prev;
	}
	delete traverse;

	traverse = new number;

	traverse->single = '0';		//MAKE THIS NULL OR MAKE THIS ZERO
	traverse->next = NULL;
	traverse->prev = NULL;

	this->first = traverse;
	this->last = traverse;
	this->neg = false;
//	this->length = 1;

	return *this;
}

#include "hw09.h"

//deletes everthing and resets it to the single integer only 0-9
largeInts& largeInts::operator =(int n)
{
	this->clearup();
	if(n >= 0 && n <= 9)
	{
		this->first->single = char(n + '0');
	}
	else
	{
		this->first->single = '0';
	}
	this->last->single = this->first->single;

	//REPLACE with this.clearup
//	number *traverse;
//	traverse = first;
//
//	while(traverse->next != NULL)
//	{
//		traverse = traverse->next;
//		delete traverse->prev;
//	}
//	delete traverse;
//
//	traverse = new number;
//	traverse->single = = char(n + '0');
//	traverse->next = NULL;
//	traverse->prev = NULL;
//
//	this->first = traverse;
//	this->last = traverse;
//	this->length = 1;
	return *this;
}



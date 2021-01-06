#include "hw09.h"


largeInts::~largeInts()
{
	number *traverse;
	traverse = first;

	while(traverse->next != NULL)
	{
		traverse = traverse->next;
		delete traverse->prev;
	}
	delete traverse;
}

#include "hw09.h"


largeInts::largeInts (const largeInts& nums)
{
	number *traverse, *a, *b;
//erase the original set of singles
	traverse = first;
	while(traverse->next != NULL)
	{
		traverse = traverse->next;
		delete traverse->prev;
	}
	delete traverse;

//Store on the original mem location the new data
	traverse = nums.first;
	a = new number;
	a->single = traverse->single;//I THINK THIS PASSES ONLY VALUES AND NOT ADRESSES, MAKE SURE TO TEST LATER
	a->next = NULL;
	a->prev = NULL;

	first = a;

	while(traverse != nums.last)	//TEST BY USING input 1221 and 5665
	{
		traverse = traverse->next;		//gets to last
		b = new number;
		b->single = traverse->single;
		b->prev = a;
		b->next = NULL;			//last->next = NULL;
		a->next = b;

		a = b;
	}
	last = a;
//	length = nums.length;
	neg = nums.neg;
//	return *this;
}

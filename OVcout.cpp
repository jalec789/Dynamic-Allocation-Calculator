#include "hw09.h"


ostream& operator << (ostream& OS, const largeInts& nums)
{
	number *traverse;
	if(nums.neg)	//if the number is negative this returns true
	{
		OS << '-';	//simply cout the neg sign
	}
	traverse = nums.first;
	do{
		OS << traverse->single;
		traverse = traverse->next;
	}while(traverse != NULL);
	return OS;
}


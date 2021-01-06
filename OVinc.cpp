#include "hw09.h"


largeInts& largeInts::operator ++(int u)
{
	if((this->first == this->last) && (this->first->single == '1') && (this->neg))
	{
		this->first->single--;
		this->neg = false;
	}
	else if(this->neg)
	{
		this->neg = false;
		this->operator --(0);
		this->neg = true;
	}
	else
	{
		number *traverse, *make;
		traverse = this->last;
		bool ten = true;

		while(ten)
		{
			if(traverse->single == '9')
			{
				if(traverse->prev == NULL)
				{
					traverse->single = '0';			//SAME

					make = new number;
					traverse->prev = make;

					make->single = '1';
					make->next = traverse;
					make->prev = NULL;
					this->first = make;
//					this->length++;

					ten = false;
				}
				else
				{
					traverse->single = '0';		//SAME
					traverse = traverse->prev;
					//				ten = true;
				}
			}
			else
			{
				traverse->single++;
				ten = false;
			}
		}
	}
	return *this;
}


#include "hw09.h"


largeInts& largeInts::operator --(int u)
{
	if((this->first == this->last) && (this->first->single == '0'))
	{
		this->neg = true;
		this->first->single++;
	}
	else if(this->neg)
	{
		this->neg = false;
		this->operator ++(0);
		this->neg = true;
	}
	else
	{
		number *traverse, *backup;
		traverse = this->last;
		bool zero = true;

		while(zero)
		{
			if(traverse->single == '0')
			{
				if(traverse->prev == NULL)//This case should only show up if zero is alone
				{
					this->neg = true;
					traverse->single++;
				}
				else
				{
					traverse->single = '9';
					traverse = traverse->prev;
					zero = true;
				}
			}
			else if(traverse->single == '1')
			{
				if((traverse->prev == NULL) && (traverse->next != NULL))
				{
					backup = traverse->next;
					traverse->single = '9';
					this->first = backup;
					//				traverse = NULL;


					delete traverse;
					backup->prev = NULL;
//					length--;
					zero = false;
				}
				else
				{
					traverse->single--;
					zero = false;
				}
			}
			else
			{
				traverse->single--;
				zero = false;
			}
		}
	}

	return *this;
}


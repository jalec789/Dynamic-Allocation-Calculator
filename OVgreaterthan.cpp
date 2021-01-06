#include "hw09.h"


bool largeInts::operator >(const largeInts& nums) const
{
	bool bigger = false;//if the numbers are equal smaller will not be touched and the return will be false

	if(this->neg && !nums.neg)
	{
		bigger = false;
	}
	else if(!this->neg && nums.neg)
	{
		bigger = true;
	}
	else
	{
		largeInts a,b;
		a = *this;
		b = nums;

		number *traverse1, *traverse2;
		traverse1 = a.last;//if this is smaller then return true
		traverse2 = b.last;


		while((traverse1 != NULL) && (traverse2 != NULL))
		{
			traverse1 = traverse1->prev;
			traverse2 = traverse2->prev;
		}

		if((traverse1 != NULL) && (traverse2 == NULL))			//check length
		{
			if(this->neg && nums.neg)
			{
				bigger = false;
			}
			else if(!this->neg && !nums.neg)
			{
				bigger = true;
			}
//			bigger = true;
		}
		else if((traverse1 == NULL) && (traverse2 != NULL))		//check length
		{
			if(this->neg && nums.neg)
			{
				bigger = true;
			}
			else if(!this->neg && !nums.neg)
			{
				bigger = false;
			}
//			bigger = false;
		}
		else if((traverse1 == NULL) && (traverse2 == NULL))		//lengths are equal so check values
		{
			traverse1 = a.first;
			traverse2 = b.first;

			while((traverse1 != NULL) && (traverse2 != NULL))
			{
				if(traverse1->single < traverse2->single)
				{
					if(this->neg && nums.neg)
					{
						bigger = true;
					}
					else if(!this->neg && !nums.neg)
					{
						bigger = false;
					}
//					bigger = false;
					break;
				}
				else if(traverse1->single > traverse2->single)
				{
					if(this->neg && nums.neg)
					{
						bigger = false;
					}
					else if(!this->neg && !nums.neg)
					{
						bigger = true;
					}
//					bigger = true;
					break;
				}
				traverse1 = traverse1->next;
				traverse2 = traverse2->next;
			}
		}
		else	//they are equal
		{
			bigger = false;
		}
		//PUT EVERYTHING IN HERE
	}

	return bigger;
}



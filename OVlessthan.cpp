#include "hw09.h"

bool largeInts::operator <(const largeInts& nums) const
{
	bool smaller = false;	//if the numbers are equal smaller will not be touched and the return will be false
	if(this->neg && !nums.neg)
	{
		smaller = true;
	}
	else if(!this->neg && nums.neg)
	{
		smaller = false;
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

		if((traverse1 != NULL) && (traverse2 == NULL))				//check length
		{
			if(this->neg && nums.neg)
			{
				smaller = true;
			}
			else if(!this->neg && !nums.neg)
			{
				smaller = false;
			}
//			smaller = false;//determine that the abs values, this is bigger
		}
		else if((traverse1 == NULL) && (traverse2 != NULL))			//check length
		{
			if(this->neg && nums.neg)
			{
				smaller = false;
			}
			else if(!this->neg && !nums.neg)
			{
				smaller = true;
			}
//			smaller = true;//determine that the abs values, this is smaller
		}
		else if((traverse1 == NULL) && (traverse2 == NULL))			//lengths are equal so check values
		{
			traverse1 = a.first;
			traverse2 = b.first;

			while((traverse1 != NULL) && (traverse2 != NULL))
			{
				if(traverse1->single < traverse2->single)
				{
					if(this->neg && nums.neg)
					{
						smaller = false;
					}
					else if(!this->neg && !nums.neg)
					{
						smaller = true;
					}
//					smaller = true;//determine that the abs values, this is smaller
					break;
				}
				else if(traverse1->single > traverse2->single)
				{
					if(this->neg && nums.neg)
					{
						smaller = true;
					}
					else if(!this->neg && !nums.neg)
					{
						smaller = false;
					}
//					smaller = false;//determine that the abs values, this is bigger

					break;
				}
				traverse1 = traverse1->next;
				traverse2 = traverse2->next;
			}
		}
		else//they are equal
		{
			smaller = false;
		}
	}

	return smaller;
}




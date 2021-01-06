#include "hw09.h"


largeInts largeInts::operator +(const largeInts& nums)const
{
	largeInts Sum, Add1, Add2;
	Add1 = *this;	// L value
	Add2 = nums;	// R value


	if(this->neg == nums.neg)		//SAME SIGNS
	{								//then find sum
		Sum = AddAbs(Add1, Add2);
		Sum.neg = this->neg;
	}
	else							//OPPOSITE SIGNS
	{								//then find difference
		Sum = SubAbs(Add1, Add2);

		Add1.neg = false;
		Add2.neg = false;
		if(Add1 < Add2)
		{
			Sum.neg = nums.neg;				//if second number is bigger the sum's sign is the same as the second one
		}
		else if(Add1 > Add2)		//if first number is bigger the sum's sign is the same as the first one
		{
			Sum.neg = this->neg;
		}
		else
		{
			Sum.neg = false;			//zero is positive
		}
	}
	return Sum;
}



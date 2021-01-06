#include "hw09.h"


largeInts largeInts::operator -(const largeInts& nums)const
{
	largeInts Difference, Sub1, Sub2;
	Sub1 = *this;
	Sub2 = nums;

	if(this->neg == nums.neg)
	{
		Difference = SubAbs(Sub1, Sub2);
	}
	else
	{
		Difference = AddAbs(Sub1, Sub2);
	}

	Sub1.neg = false;
	Sub2.neg = false;

	if(*this > nums)
	{
		Difference.neg = false;
	}
	else if (*this < nums)
	{
		Difference.neg = true;
	}
	else	//if zero && (this->neg == nums.neg) if == check neg
	{
		Difference.neg = false;
	}

	return Difference;
}




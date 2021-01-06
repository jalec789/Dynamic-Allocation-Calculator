#include "hw09.h"


largeInts largeInts::operator *(const largeInts& that)
{
	largeInts i, mult1, mult2, product;
	i = 1;
//	product = 0;
	mult1 = *this;
	mult2 = that;

	mult1.neg = false;
	mult2.neg = false;

	product = MultAbs(mult1, mult2);

	if(this->neg == that.neg)
	{
		product.neg = false;
	}
	else
	{
		product.neg = true;
	}

	return product;
}




//largeInts largeInts::operator *(const largeInts& that)
//{
//	largeInts i, mult1, mult2, product;
//	i = 1;
////	product = 0;
//	mult1 = *this;
//	mult2 = that;
//
//	mult1.neg = false;
//	mult2.neg = false;
//
//	//while(!(i == mult2))//initialize i to zero if you get this to work
//	while(!(i > mult2))
//	{
//		i++;
//		product = AddAbs(product, mult1);
//
////		cout << "rep is: "<< i << endl;
////		cout << "value is: "<< product << endl;
//
//	}
//
//	if(this->neg == that.neg)
//	{
//		product.neg = false;
//	}
//	else
//	{
//		product.neg = true;
//	}
//
//	return product;
//}



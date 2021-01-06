#include "hw09.h"

//This function find the sum of the two numbers ignoring the signs so like adding the absolute values

largeInts AddAbs(largeInts& num1, largeInts& num2)
{
	//make both values positive
	num1.neg = false;
	num2.neg = false;

	number *ad1, *ad2, *sumNum, *sumt, *carry, *cart;
	largeInts sum, rem;
	sumNum = sum.last;		//initializes all of number struct sumNum's members
	carry = rem.last;		//initialize the remaining carry over. will add the carry overs when basic add complete

	ad1 = num1.last;
	ad2 = num2.last;

	bool noCare = true;		//no carries at all controls recursion

	carry->single = '0';

	cart = new number;
	carry->prev = cart;
	cart->prev = NULL;
	cart->next = carry;
	carry = cart;

	sumNum->single = ad1->single + ad2->single - '0';
	sumNum->next = NULL;
	sumNum->prev = NULL;

	if(sumNum->single > '9')
	{
		noCare = false;
		cart->single = '1';
		sumNum->single = sumNum->single - 10;
	}
	else
	{
		cart->single = '0';
	}

	ad1 = ad1->prev;
	ad2 = ad2->prev;

	while((ad1 != NULL) || (ad2 != NULL))
	{
		sumt = new number;
		sumNum->prev = sumt;
		sumt->prev = NULL;
		sumt->next = sumNum;

		sumNum = sumt;

		cart = new number;

		if((ad1 != NULL) && (ad2 != NULL))
		{
			sumt->single = ad1->single + ad2->single - '0';
			ad1 = ad1->prev;
			ad2 = ad2->prev;
		}
		else if((ad1 != NULL) && (ad2 == NULL))
		{
			sumt->single = ad1->single;
			ad1 = ad1->prev;
		}
		else if((ad1 == NULL) && (ad2 != NULL))
		{
			sumt->single =ad2->single;
			ad2 = ad2->prev;
		}

		if(sumNum->single > '9')
		{
			noCare = false;
			cart->single = '1';
			sumNum->single = sumNum->single - 10;
		}
		else
		{
			cart->single = '0';
		}

		cart->prev = NULL;
		cart->next = carry;
		carry->prev = cart;
		carry = cart;

	}

	rem.first = carry;
	sum.first = sumNum;

	//		cout << rem<< endl;
	//		cout << sum<< endl;

	if(!noCare)
	{
		sum = AddAbs(sum, rem);
		//sum = sum + rem;
	}

	//:::WARNING:::: THIS CAUSES LEAK bc null is not being set to first.prev

	sumNum = sum.first;
	while((sumNum != sum.last) && (sumNum->single == '0'))
	{
		sumt = sumNum->next;
		sumt->prev = NULL;
		sum.first = sumt;
		delete sumNum;
		sumNum = sumt;
	}

	return sum;
}




//A BILLION PLUS A BILLION IS VERY TAXING ON CPU
//largeInts IncAdd(const largeInts& num1, const largeInts& num2)
//{
//	largeInts i, ad;
//	i = 0;
//	ad = num2;
//	while(!(i == num1))
//	{
//		ad++;
//		i++;
//	}
//	return ad;
//}

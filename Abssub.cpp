#include "hw09.h"

largeInts SubAbs(largeInts& num1, largeInts& num2)
{
	//make both values positive
	num1.neg = false;
	num2.neg = false;

	largeInts difference, carry;

	number *sb1, *sb2, *difNum, *dift, *cart, *over;

	bool noCare = true;		//no carries at all controls recursion

	if(num1 > num2)
	{
		sb1 = num1.last;
		sb2 = num2.last;
	}
	else if(num1 < num2)
	{
		sb2 = num1.last;
		sb1 = num2.last;
	}
	else//they are equal
	{
		difference = 0;
		return difference;
//		sb1 = num1.last;
//		sb2 = num2.last;
//
//		difference.last->single = '0';			//THIS WILL CAUSE LEAKS
	}

	difNum = difference.last;
	over = carry.last;

	over->single = '0';
	cart = over;
	cart->next = NULL; //already in constructor

	over = new number;
	over->prev = NULL;
	over->next = cart;
	cart->prev = over;

	difNum->single =  sb1->single + '0' - sb2->single;

	if(difNum->single < '0')
	{
		noCare = false;
		difNum->single = difNum->single + 10;
		over->single = '1';
	}
	else
	{
		over->single = '0';
	}

	sb1 = sb1->prev;
	sb2 = sb2->prev;

	while((sb1 != NULL) || (sb2 != NULL))
	{

		dift = difNum;
		difNum = new number;
		dift->prev = difNum;
		difNum->next = dift;
		difNum->prev = NULL;


		cart = over;
		over = new number;
		over->prev = NULL;
		over->next = cart;
		cart->prev = over;


		if((sb1 != NULL) && (sb2 != NULL))
		{
			difNum->single = sb1->single + '0' - sb2->single;
			sb1 = sb1->prev;
			sb2 = sb2->prev;
		}
		else if((sb1 != NULL) && (sb2 == NULL))
		{
			difNum->single = sb1->single;
			sb1 = sb1->prev;
		}
		else if((sb1 == NULL) && (sb2 != NULL))
		{
			difNum->single = sb2->single;
			sb2 = sb2->prev;
		}


		if(difNum->single < '0')
		{
			noCare = false;
			over->single = '1';
			difNum->single = difNum->single + 10;
		}
		else
		{
			over->single = '0';
		}

	}

	difference.first = difNum;
	carry.first = over;

	//clean zeros on carry
	//we need this on subtraction and not addition because recursion will misread
	//carry as a number larger than difference and difference needs to be larger
	while((over->single == '0') && (over != carry.last))
	{
		cart = over->next;
		cart->prev = NULL;
		carry.first = cart;
		delete over;
		over = cart;
	}


//	cout << difference << endl;
//	cout << carry << endl;

	if(!noCare)
	{
		difference = SubAbs(difference, carry);
	}

	//clean zeros on difference
	difNum = difference.first;
	while((difNum->single == '0') && (difNum != difference.last))
	{
		dift = difNum->next;
		dift->prev = NULL;
		difference.first = dift;
		delete difNum;
		difNum = dift;
	}

	return difference;
}


#include "hw09.h"

//WHY CANT we put this in separate funtion?

//Multiply single characters and return the largeInt ONLY USE FOR MULT FUNCT
largeInts multchar(const char n1, const char n2)
{
	largeInts i, ans, num1, num2;
	largeInts nine;
	nine = 9;
	number *placeholder;

	ans = 0;
	i = 0;

	num1.first->single = n1;
	num2.first->single = n2;

	while(i < num2)
	{
		i++;
		ans = AddAbs(ans, num1);
	}

	//add a zero to carry when used should be activated to make 00,01,02...09
	if(!(ans > nine))
	{
		placeholder = new number;
		placeholder->single = '0';

		ans.last->prev = placeholder;
		ans.first = placeholder;
		ans.first->next = ans.last;
		ans.first->prev = NULL;
	}
	return ans;
}





largeInts MultAbs(largeInts& num1, largeInts& num2)
{
	num1.neg = false;
	num2.neg = true;

	number *mult1, *mult2,
	*proNum, *prot,
	*car, *cart,
	*place, *holder;

	largeInts i, product, split, carry, product2, placeholder;
	largeInts one;
	one = 1;


	placeholder = 0;
	mult2 = num2.last;




	while(mult2 != NULL)
	{
		product.clearup();
		carry.clearup();

		mult1 = num1.last;

		proNum = product.last;
		proNum->next = NULL;
		proNum->prev = NULL;

		car = carry.last;
		car->single = '0';
		car->next = NULL;

		cart = new number;

		car->prev = cart;
		cart->prev = NULL;
		cart->next = car;

		car = cart;


		//format of split will be 00, 06, 54, never over 81
		split.clearup();
		split = multchar(mult1->single, mult2->single);

		proNum->single = split.last->single;
		cart->single = split.first->single;

//		cout << mult1->single << " * " << mult2->single << " = " << split << endl;

		mult1 = mult1->prev;

		while(mult1 != NULL)
		{

			prot = proNum;
			proNum = new number;

			prot->prev = proNum;
			proNum->next = prot;
			proNum->prev = NULL;


			cart = new number;

			car->prev = cart;
			cart->prev = NULL;
			cart->next = car;

			car = cart;

			split.clearup();
			split = multchar(mult1->single, mult2->single);

			proNum->single = split.last->single;
			cart->single = split.first->single;

//			cout << mult1->single << " * " << mult2->single << " = " << split << endl;

			mult1 = mult1->prev;

//			cout << endl << product << endl;

		}
		product.first = proNum;
		carry.first = cart;
//		cout << product << " + " << carry << endl;//TEST

		product = product + carry;

		//placeholder
		for(i = 0; i < placeholder; i++)
		{
			holder = product.last;

			place = new number;

			place->single = '0';
			place->prev = holder;
			place->next = NULL;

			holder->next = place;

			product.last = place;

		}

//		cout <<"FINAL ADD: "<< product2 << " + " << product << endl << endl;

		product2 = product2 + product;

		placeholder++;


		mult2 = mult2->prev;

	}
	//nest both while above here

	return product2;

}

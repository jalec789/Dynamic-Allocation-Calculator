#include "hw09.h"

istream& operator >> (istream& IS, largeInts& nums)
{
	//CLEAN UP FIRST
	nums.clearup();

	number *end, *loop;

//	loop = new number;		//already allocated memory in constructor for the first
	loop = nums.first;

	IS >> loop->single;	//take advantage of the cin input buffer vunerability for the while statement
//	IS.get(loop->single);

//	loop->next = NULL;	//already in constructor when you make loop = first
//	loop->prev = NULL;

	//THIS SECTION WAS ADDED TO ACCOUNT FOR NEGATIVES
	if(loop->single == '-')
	{
		nums.neg = true;
		IS >> loop->single;//do another initial input since the first was compromised as a '-'
	}
	//THE NEGATIVE SIGN WILL NOT SHOW UP ON THE LIST it will only store as a bool

	nums.first = loop;
	nums.last = loop;

	//**************************************************************************
	//  DO A CHECK IF THE FIRST DIGIT IS A NEGATIVE or letter and everything
	//  else can be digits if the user types anything else other than numbers
	//  after the first check then drop everything to 0. first number must be 1-9
	//  otherwise truncate unlike int zeros wont count as an initial number
	//  :ie: 0123 != 123
	//**************************************************************************
	if(loop->single >= '1' && loop->single <= '9')
	{

//		nums.length = 1;		//THIS NUMBER PLUS NULL TERMINATOR
		nums.first = loop;
		end = loop;

//		cout << "first is " << loop->single << endl;
//The base case of this loop will end when there is a letter or no char in the input buffer
//why no "OR"(!IS) case when there is no number in the buffer?
		while(end->single >= '0' && end->single <= '9')
		{
			end = new number;

			IS.get(end->single);
			//		IS >> end->single;

			end->next = NULL;
			end->prev = loop;
			loop->next = end;

//cout << "\nnumber is:" <<  end->single;

			if(end->single >= '0' && end->single <= '9')
			{
				loop = end;
//				nums.length++;
			}
//			cout << "next is " << loop->single << endl;
		}

//		if(!(end->single >= '0' && end->single <= '9'))
		if(end->single != '\n')			//CHECK FOR letters input
		{
			IS.ignore(1000,'\n');		//try cin.ignore(nums.length + 10000, '\n')
		}
//there is a blank end spot that needs to be deleted the close loop
		delete end;
		loop->next = NULL;
//		cout << "length is " << nums.length << endl;


		nums.last = loop;
	}
	else		//when numbers are not inputted
	{
		loop->single = '0';
		loop->next = NULL;
		loop->prev = NULL;

		nums.first = loop;
		nums.last = loop;
//		nums.length = 0;
		nums.neg = false;
	}
	return IS;
}


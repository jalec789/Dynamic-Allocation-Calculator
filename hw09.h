#include <iostream>
//#include <sstream>
//#include <string>		//DELETE WHAT YOU DONT USE

using namespace std;

#ifndef HW09_H_
#define HW09_H_


struct number
{
	char single;
	number *next;
	number *prev;
};


class largeInts
{

public:
	//These should be independent of any methods
	largeInts();						//constructor
	~largeInts();						//destructor
	largeInts (const largeInts& nums);	//copy constructor

	largeInts& clearup();				//reset to zero

	friend istream& operator >> (istream& IS, largeInts& nums);
	friend ostream& operator << (ostream& OS, const largeInts& nums);


//	bool operator ==(const largeInts& nums) const;
//	bool operator !=(const largeInts& nums) const;

	//was going to use these to add but it was very inefficient
	largeInts& operator ++(int);
	largeInts& operator --(int);
	largeInts& operator = (const largeInts& nums);
	largeInts& operator = (int);	//only set right now to assign a single integer



	//these abs add and subtract do not take neg and pos into accnt, do not assume absolute
	//value otherwise make an absolute val function and call it within these functions
	//EDIT: got rid of constant passing in order to change the bool neg
	//now pass in pos or neg and get the absolute sum or difference
	friend largeInts AddAbs(largeInts& num1, largeInts& num2);//add absolute values
	friend largeInts SubAbs(largeInts& num1, largeInts& num2);//simply finding difference putting larger on top
	friend largeInts MultAbs(largeInts& num1, largeInts& num2);

	friend largeInts multchar(const char n1, const char n2);

	largeInts operator * (const largeInts& nums);
	largeInts operator + (const largeInts& nums)const;// this will not be an absolute add
	largeInts operator - (const largeInts& nums)const;// these will take neg signs in account

	//Did not make this one efficient bc not enough time

//	largeInts IncAdd(const largeInts& num1, const largeInts& num2);

	bool operator <(const largeInts& nums) const;
	bool operator >(const largeInts& nums) const;




//	void clearup(largeInts& nums);


private:								//REMOVE AFTER TESTING
	number *first;
	number *last;
	bool neg;
	//unsigned long int length;	//WHEN DONE MAKE THIS A largeInt datatype if you can
};




//largeInts Multchar(char n1, char n2);

void prHdr();



#endif /* HW09_H_ */

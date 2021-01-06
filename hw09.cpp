#include "hw09.h"


int main()
{
//	largeInts n1, n2, ans;
//	cout << "first num: ";
//	cin >> n1;
//	cout << "second num: ";
//	cin >> n2;
//	ans = MultAbs(n1,n2);
//	cout <<endl << ans << endl;



	prHdr();

	string menu = "\n\n******************************************************************\n"
					  "*************************JASON'S CALCULATOR***********************\n"
					  "******************************************************************\n"
					  "[1]  ENTER NUMBERS\n"
					  "[2]  ADD NUMBERS\n"
					  "[3]  SUBTRACT NUMBERS\n"
//					  "[4]  INCREMENT NUMBERS\n"
//					  "[5]  DECREMENT NUMBERS\n"
//					  "[6]  INCREMENT ADD (with timer!!!)\n"
//					  "[7]  DECREMENT SUBTRACT (with timer!!!)\n"
					  "[4]  MULTIPLY NUMBERS (this may take a while with large numbers)\n"
					  "[5]  SHOW NUMBERS\n"
					  "[6]  EXIT\n\n"
					  "What would you like to do?\n";

	int choice;

	largeInts num1, num2, ans;

	do
	{
		//cout << menu;
		do
		{
			cout << menu;
			cin >> choice;
			//cin.ignore(1000, '\n');
			if(choice < 1 || choice > 6)
			{
				cout << "\n\nPlease enter a valid choice\n\n";
			}
		}while(choice < 1 || choice > 6);

		switch(choice)
		{

		case 1:
			cout << "Enter the first number:  ";
			cin >> num1;
			cout << "Enter the second number: ";
			cin >> num2;
			cout << "\n\nYOUR NUMBERS ARE:";
			cout << "\n\n---->" << num1 << "<----";
			cout << "\n---->" << num2 << "<----\n\n";
			break;

		case 2:
			cout << "\n" << num1 << " + " << num2 << "\n\n";
			ans = num1 + num2;
			cout << "====>" << ans << "<====\n\n";
			break;

		case 3:
			cout << "\n" << num1 << " - " << num2 << "\n\n";
			ans = num1 - num2;
			cout << "====>" << ans << "<====\n\n";
			break;

		case 4:
			cout << "\n" << num1 << " * " << num2 << "\n\n";
			ans = num1 * num2;
			cout << "====>" << ans << "<====\n\n";
			break;

		case 5:
			cout << "YOUR NUMBERS ARE:\n";
			cout << num1 << endl;
			cout << num2 << endl << endl;
			break;

		case 6:
			cout << "\n\n\nGood Bye :)";
			break;

		default:
			cout << "Enter a valid input\n\n";

		}

	}while(choice != 6);







//	largeInts *num1, *num2;
//	num1 = new largeInts;
//	num2 = new largeInts;


//	cout << "enter a number: ";// anything that is not a number will cancel the input from that point. backspace is okay
//	num1 = 7;
//	num1 = num1 + num1;
//	cin >> num1;
//	cin.ignore(1000, '\n');

//	cout << "enter a number: ";
//	num2 = 4;
//	cin >> num2;
//	cin.ignore(1000, '\n');

//ASSIGNMENT MAIN CHECK BOTH: int and largeInt
//	num2 = num1;
//	num1 = 3;

//INCREMENT MAIN CHECK
//	num1++;
//	num1--;





//comparison check
//	if(num1 < num2)
//	{
//		cout << num2 << " is larger";
//	}
//	if(num1 > num2)
//	{
//		cout << num1 << " is larger";
//	}


//	cin >> num1;
//	cout << "\n\n---->" << num1 << "<----";


//	ans = num1 - num2;
//	ans = SubAbs(num1, num2);
//	cout << "\n" << num1 << " - " << num2 << "\n";
//	cout << "====>" << ans << "<====\n\n";


//	ans = num2 + num1;
//	ans = AddAbs(num1, num2);
//	cout << "\n" << num2 << " + " << num1 << "\n";
//	cout << "====>" << ans << "<====\n\n";

//	ans = num1 * num2;
//	cout << "\n" << num1 << " * " << num2 << "\n";
//	cout << "====>" << ans << "<====\n\n";


//BOOL MAIN CHECK
//	if(num1 == num2)
//	{
//		cout << num1 << " and " << num2 << " are equal";
//	}
//	else
//	{
//		cout << num1 << " and " << num2 << " are not equal";
//	}



//REMOVE THIS
//	delete num1;
//	delete num2;

	//make public if you want to see
//	cout << num1.length << "-->" << num1.neg << "<--" << endl;
//	cout << num2.length << "-->" << num2.last->single << "<--" << endl;
//	cout << ans.length << "-->" << ans.last->single << "<--" << endl;


	return 0;
}

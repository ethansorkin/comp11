/**********
*ETHAN SORKIN
*COMP11
*Homework 1
*Problem 1
*
*Prompt user for 4 integers (cin num1, num2, num3, num4)
*Call swap function
*Swap function: if num1 > num2, swap values of num1 and num2
*Use variable "temp" as a placeholder for the swap function
*while loop around function to repeat it until numbers are ordered
*Display numbers in order
*****/


#include <iostream>
using namespace std;
void swap (int &num1, int &num2);    //& refers to the address
int main ()
{
	int num1, num2, num3, num4;
	cout << "Enter 4 integers" << endl;
	cin >> num1;
	cin >> num2;
	cin >> num3;
	cin >> num4;

	//swap all possible cominations of numbers
	swap (num1, num2);
	swap (num1, num3);
	swap (num1, num4);
	swap (num2, num3);
	swap (num2, num4);
	swap (num3, num4);
	cout << "Here are your numbers in sorted order:" << endl;
	cout << num1 << " " << num2 << " " << num3 << " " << num4 << endl;
	return 0;
}

void swap (int &num1, int &num2)
{
	if (num1 > num2)
	{
		int temp;		//placeholder while values are being swapped
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
}
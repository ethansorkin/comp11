/**********
*ETHAN SORKIN
*COMP11
*Homework 2
*Problem 1
*
*computer selects two random numbers bewteen 5-15
*prompt user for sum of numbers (use boolean expression)
**if correct, prompt correct, game over
**if incorrect prompt try again, redisplay question
***if correct, prompt game over
***if incorrect, prompt incorrect, answer is #
*variables: num1, num2, response
*********/

#include <iostream>
using namespace std;
int main ()
{
	int num1, num2, response;
	srand (time(NULL)); // this randomizes numbers so it is a different value every time you run it
	num1 = rand() % 11 + 5; //these lines generate random numbers from 5-15
	num2 = rand() % 11 + 5;
	cout << "What is ";
	cout << num1;
	cout << " + ";
	cout << num2;
	cout << "?" << endl;
	cin >> response;

	if (response == num1 + num2) //checking to make sure answer is correct
	{
		cout << "Congratulations, that is correct! Game over." << endl;
	}
	else if (response != num1 + num2) //if user gives incorrect answer
	{
		cout << "Sorry, that is incorrect. Try again. ";
		cout << "What is ";
		cout << num1;
		cout << " + ";
		cout << num2;
		cout << "?" << endl;
		cin >> response;
		if (response == num1 + num2) //checking to make sure answer is correct
		{
		cout << "Congratulations, that is correct! Game over." << endl;
		}
		else if(response != num1 + num2) //if user gives incorrect answer
		{
		cout << "Sorry, that is incorrect. The answer is ";
		cout << num1 + num2;
		cout << "." << endl;
		}
	}
return 0;

}
/**********
*ETHAN SORKIN
*COMP11
*Homework 1
*Problem 2
*
**********/

#include <iostream>
#include <cstdlib> 
using namespace std;
double average (int number []);
const int MAX = 5;
int main ()
{
	int i, number [MAX]; 
	double num_average;
	cout << "Enter 5 integers" << endl;
	for (i = 0; i < MAX; i++)
		cin >> number [i];
	num_average = average(number);
	cout << "Here is the average of your numbers: " << num_average << endl;
	return 0;
}

double average (int number [])
{
	double num_average;
	int i, sum = 0;
	for (i = 0; i < MAX; i++)
		sum = sum + number [i];
	num_average = sum / 5.0;      //Use literal here because I must divide by
	return num_average;			  //a double for num_average to be a double
}
/**********
*ETHAN SORKIN
*COMP11
*Homework 1
*Problem 2
*
*Prompt user to enter word1, cin word1
*prompt user to enter word2, cin word2
*prompt user to enter word3, cin word3
*series of if statements that numerically order string values
*compare value of string using <=, >=, &&
*use greater/less than or equal to in order to account for two of the same word
*
*Test input: book, road, hut
*Expected output: book, hut, road
*
*Test input: temple, quiet, alone
*Expected output: alone, quiet, temple
*
*Test input: man, college, milk
*Expected output: college, man, milk
**********/

#include <iostream>
using namespace std;
int main ()
{ 
	string word1, word2, word3;
	cout << "Enter a word." << endl;
	cin >> word1;
	cout << "Enter another word." << endl;
	cin >> word2;
	cout << "And one more!" << endl;
	cin >> word3;
	cout << "Here are you words in sorted order!" <<endl;

//Display first word
//If any word has less value that both the others, 
//it is the first word alphabetically

	if (word1 <= word2 && word1 <= word3)
	{ 
		cout << word1;
	}

	else if (word2 <= word1 && word2 <= word3)
	{
		cout << word2;
	}

	else if (word3 <= word1 && word3 <= word2)
	{
		cout << word3;
	}
	cout << ", ";

//Display second word
//if any word has greater value than one word, and less value than the other, 
//it is the second word alphabetically

	if (word1 <= word2 && word1 >= word3)
	{ 
		cout << word1;
	}

	else if (word1 <= word3 && word1 >= word2)
	{
		cout << word1;
	}

	else if (word2 <= word1 && word2 >= word3)
	{
		cout << word2;
	}

	else if (word2 <= word3 && word2 >= word1)
	{
		cout << word2;
	}

	else if (word3 <= word1 && word3 >= word2)
	{
		cout << word3;
	}

	else if (word3 <= word2 && word3 >= word1)
	{
		cout << word3;
	}
	cout << ", ";

//Display third word
//If any word has greater value that both the others, 
//it is the third word alphabetically

	if (word1 >= word2 && word1 >= word3)
	{ 
		cout << word1 << endl;
	}

	else if (word2 >= word1 && word2 >= word3)
	{
		cout << word2 << endl;
	}

	else if (word3 >= word1 && word3 >= word2)
	{
		cout << word3 << endl;
	}

return 0;
}
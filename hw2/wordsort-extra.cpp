/**********
*ETHAN SORKIN
*COMP11
*Homework 1
*Problem 2
*
*Ask user how many words
*Prompt user to enter word1, cin word1
*prompt user to enter word2, cin word2
*prompt user to enter word3, cin word3
*series of if statements that numerically order string values
*compare value of string using <, >, &&
*
*Test input: book, road, hut
*Expected output: book, hut, road
*
*Test input: temple, quiet, alone
*Expected output: alone, quiet, temple
*
*Test input: man, college, milk
*Expected output: college, man, milk
*
*QUESTIONS: should we assume that the use puts in different words?
**********/

#include <iostream>
using namespace std;
int main ()
{ 
	int num_words;
	string word1, word2, word3, word4, word5;

	cout << "How many words do you want to sort? Enter a value between 2 and 5" << endl;
	cin >> num_words;

	while (num_words < 2 || num_words > 5)
	{
		cout << "That is an invalid number of words. Enter a value between 2 and 5" << endl;
		cin >> num_words;
	}

	//TWO WORDS
	if (num_words == 2)
	{
	cout << "Enter a word." << endl;
	cin >> word1;
	cout << "Enter another word." << endl;
	cin >> word2;

	cout << "Here are you words in sorted order!" << endl;

		if (word1 <= word2)
		{
			cout << word1;
			cout << ", ";
			cout << word2 << endl;
		} 
		else if (word2 <= word1)
		{
			cout << word2;
			cout << ", ";
			cout << word1  << endl;
		}

	}

	//THREE WORDS
	else if (num_words == 3)
	{
	cout << "Enter a word." << endl;
	cin >> word1;
	cout << "Enter another word." << endl;
	cin >> word2;
	cout << "And one more!" << endl;
	cin >> word3;

	cout << "Here are you words in sorted order!" << endl;

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
	}

	//FOUR WORDS
	else if (num_words == 4)
	{
	cout << "Enter a word." << endl;
	cin >> word1;
	cout << "Enter another word." << endl;
	cin >> word2;
	cout << "And one more." << endl;
	cin >> word3;
	cout << "Last one!" << endl;
	cin >> word4;

	cout << "Here are you words in sorted order!" << endl;


	//Display first word

		if (word1 <= word2 && word1 <= word3 && word1 <= word4)
		{ 
			cout << word1;
		}

		else if (word2 <= word1 && word2 <= word3 && word2 <= word4)
		{
			cout << word2;
		}

		else if (word3 <= word1 && word3 <= word2 && word3 <= word4)
		{
			cout << word3;
		}

		else if (word4 <= word1 && word4 <= word2 && word4 <= word3)
		{
			cout << word4;
		}
		cout << ", ";

	//Display second word


		if (word1 >= word2 && word1 <= word3 && word1 <= word4)
		{ 
			cout << word1;
		}

		else if (word1 >= word3 && word1 <= word4 && word1 <= word2)
		{
			cout << word1;
		}

		else if (word1 >= word4 && word1 <= word3 && word1 <= word2)
		{
			cout << word1;
		}

		else if (word2 >= word1 && word2 <= word3 && word2 <= word4)
		{
			cout << word2;
		}

		else if (word2 >= word3 && word2 <= word1 && word2 <= word4)
		{
			cout << word2;
		}

		else if (word2 >= word4 && word2 <= word1 && word2 <= word3)
		{
			cout << word2;
		}

		else if (word3 >= word1 && word3 <= word2 && word3 <= word4)
		{
			cout << word3;
		}

		else if (word3 >= word2 && word3 <= word1 && word3 <= word4)
		{
			cout << word3;
		}

		else if (word3 >= word4 && word3 <= word1 && word3 <= word2)
		{
			cout << word3;
		}

		else if (word4 >= word1 && word4 <= word2 && word4 <= word3)
		{
			cout << word4;
		}

		else if (word4 >= word2 && word4 <= word1 && word4 <= word3)
		{
			cout << word4;
		}

		else if (word4 >= word3 && word4 <= word2 && word4 <= word1)
		{
			cout << word4;
		}
		cout << ", ";

	//Display third word

		if (word1 >= word2 && word1 >= word3 && word1 <= word4)
		{ 
			cout << word1;
		}

		else if (word1 >= word2 && word1 >= word4 && word1 <= word2)
		{
			cout << word1;
		}

		else if (word1 >= word3 && word1 >= word4 && word1 <= word2)
		{
			cout << word1;
		}

		else if (word2 >= word1 && word2 >= word3 && word2 <= word4)
		{
			cout << word2;
		}

		else if (word2 >= word3 && word2 >= word4 && word2 <= word1)
		{
			cout << word2;
		}

		else if (word2 >= word4 && word2 >= word1 && word2 <= word3)
		{
			cout << word2;
		}

		else if (word3 >= word1 && word3 >= word2 && word3 <= word4)
		{
			cout << word3;
		}

		else if (word3 >= word2 && word3 >= word4 && word3 <= word1)
		{
			cout << word3;
		}

		else if (word3 >= word4 && word3 >= word1 && word3 <= word2)
		{
			cout << word3;
		}

		else if (word4 >= word1 && word4 >= word2 && word4 <= word3)
		{
			cout << word4;
		}

		else if (word4 >= word2 && word4 >= word3 && word4 <= word1)
		{
			cout << word4;
		}

		else if (word4 >= word3 && word4 >= word1 && word4 <= word2)
		{
			cout << word4;
		}

		cout << ", ";

	//Display fourth word
		
		if (word1 >= word2 && word1 >= word3 && word1 >= word4)
		{ 
			cout << word1 << endl;
		}

		else if (word2 >= word1 && word2 >= word3 && word2 >= word4)
		{
			cout << word2 << endl;
		}

		else if (word3 >= word1 && word3 >= word2 && word3 >= word4)
		{
			cout << word3 << endl;
		}

		else if (word4 >= word1 && word4 >= word2 && word4 >= word3)
		{
			cout << word4 << endl;
		}
	}


	//FIVE WORDS
	else if (num_words == 5)
	{
	cout << "Enter a word." << endl;
	cin >> word1;
	cout << "Enter another word." << endl;
	cin >> word2;
	cout << "One more word please." << endl;
	cin >> word3;
	cout << "And one more." << endl;
	cin >> word4;
	cout << "Last one!" << endl;
	cin >> word5;
	
	cout << "Here are your words in sorted order." << endl;

	//Display first word

		if (word1 <= word2 && word1 <= word3 && word1 <= word4 && word1 <= word5)
		{ 
			cout << word1;
		}

		else if (word2 <= word1 && word2 <= word3 && word2 <= word4 && word2 <= word5)
		{
			cout << word2;
		}

		else if (word3 <= word1 && word3 <= word2 && word3 <= word4 && word3 <= word5)
		{
			cout << word3;
		}

		else if (word4 <= word1 && word4 <= word2 && word4 <= word3 && word4 <= word5)
		{
			cout << word4;
		}

		else if (word5 <= word1 && word5 <= word2 && word5 <= word3 && word5 <= word4)
		{
			cout << word5;
		}
		cout << ", ";

	//Display second word


		if (word1 >= word2 && word1 <= word3 && word1 <= word4 && word1 <= word5)
		{ 
			cout << word1;
		}

		else if (word1 >= word3 && word1 <= word4 && word1 <= word2 && word1 <= word5)
		{
			cout << word1;
		}

		else if (word1 >= word4 && word1 <= word3 && word1 <= word2 && word1 <= word5)
		{
			cout << word1;
		}

		else if (word1 >= word5 && word1 <= word3 && word1 <= word2 && word1 <= word4)
		{
			cout << word1;
		}

		else if (word2 >= word1 && word2 <= word3 && word2 <= word4 && word2 <= word5)
		{
			cout << word2;
		}

		else if (word2 >= word3 && word2 <= word1 && word2 <= word4 && word2 <= word5)
		{
			cout << word2;
		}

		else if (word2 >= word4 && word2 <= word1 && word2 <= word3 && word2 <= word5)
		{
			cout << word2;
		}

		else if (word2 >= word5 && word2 <= word1 && word2 <= word3 && word2 <= word4)
		{
			cout << word2;
		}

		else if (word3 >= word1 && word3 <= word2 && word3 <= word4 && word3 <= word5)
		{
			cout << word3;
		}

		else if (word3 >= word2 && word3 <= word1 && word3 <= word4 && word3 <= word5)
		{
			cout << word3;
		}

		else if (word3 >= word4 && word3 <= word1 && word3 <= word2 && word3 <= word5)
		{
			cout << word3;
		}

		else if (word3 >= word5 && word3 <= word1 && word3 <= word2 && word3 <= word4)
		{
			cout << word3;
		}	

		else if (word4 >= word1 && word4 <= word2 && word4 <= word5 && word4 <= word3)
		{
			cout << word4;
		}

		else if (word4 >= word2 && word4 <= word1 && word4 <= word3 && word4 <= word5)
		{
			cout << word4;
		}

		else if (word4 >= word3 && word4 <= word1 && word4 <= word2 && word4 <= word5)
		{
			cout << word4;
		}

		else if (word4 >= word5 && word4 <= word1 && word4 <= word2 && word4 <= word3)
		{
			cout << word4;
		}	

		else if (word5 >= word1 && word5 <= word2 && word5 <= word4 && word5 <= word3)
		{
			cout << word5;
		}

		else if (word5 >= word2 && word5 <= word1 && word5 <= word3 && word5 <= word4)
		{
			cout << word5;
		}

		else if (word5 >= word3 && word5 <= word1 && word5 <= word2 && word5 <= word4)
		{
			cout << word5;
		}

		else if (word5 >= word4 && word5 <= word1 && word5 <= word2 && word5 <= word3)
		{
			cout << word5;
		}	
		cout << ", ";


		//Display third word

		if (word1 >= word2 && word1 >= word3 && word1 <= word4 && word1 <= word5)
		{ 
			cout << word1;
		}

		else if (word1 >= word2 && word1 >= word4 && word1 <= word3 && word1 <= word5)
		{
			cout << word1;
		}

		else if (word1 >= word2 && word1 >= word5 && word1 <= word4 && word1 <= word3)
		{
			cout << word1;
		}

		else if (word1 >= word3 && word1 >= word4 && word1 <= word2 && word1 <= word5)
		{
			cout << word1;
		}

		else if (word1 >= word3 && word1 >= word5 && word1 <= word4 && word1 <= word2)
		{
			cout << word1;
		}

		else if (word1 >= word4 && word1 >= word5 && word1 <= word2 && word1 <= word3)
		{
			cout << word1;
		}

		else if (word2 >= word1 && word2 >= word3 && word2 <= word4 && word2 <= word5)
		{ 
			cout << word2;
		}

		else if (word2 >= word1 && word2 >= word4 && word2 <= word3 && word2 <= word5)
		{
			cout << word2;
		}

		else if (word2 >= word1 && word2 >= word5 && word2 <= word4 && word2 <= word3)
		{
			cout << word2;
		}

		else if (word2 >= word3 && word2 >= word4 && word2 <= word1 && word2 <= word5)
		{
			cout << word2;
		}

		else if (word2 >= word3 && word2 >= word5 && word2 <= word4 && word2 <= word1)
		{
			cout << word2;
		}

		else if (word2 >= word4 && word2 >= word5 && word2 <= word1 && word2 <= word3)
		{
			cout << word2;
		}

		else if (word3 >= word1 && word3 >= word2 && word3 <= word4 && word1 <= word5)
		{ 
			cout << word3;
		}

		else if (word3 >= word1 && word3 >= word4 && word3 <= word2 && word3 <= word5)
		{
			cout << word3;
		}

		else if (word3 >= word1 && word3 >= word5 && word3 <= word4 && word3 <= word3)
		{
			cout << word3;
		}

		else if (word3 >= word2 && word3 >= word4 && word3 <= word1 && word3 <= word5)
		{
			cout << word3;
		}

		else if (word3 >= word2 && word3 >= word5 && word3 <= word4 && word3 <= word1)
		{
			cout << word3;
		}

		else if (word3 >= word4 && word3 >= word5 && word3 <= word2 && word3 <= word1)
		{
			cout << word3;
		}
		
		else if (word4 >= word1 && word4 >= word2 && word4 <= word3 && word4 <= word5)
		{ 
			cout << word4;
		}

		else if (word4 >= word1 && word4 >= word3 && word4 <= word2 && word4 <= word5)
		{
			cout << word4;
		}

		else if (word4 >= word1 && word4 >= word5 && word4 <= word2 && word4 <= word3)
		{
			cout << word4;
		}

		else if (word4 >= word2 && word4 >= word3 && word4 <= word1 && word4 <= word5)
		{
			cout << word4;
		}

		else if (word4 >= word2 && word4 >= word5 && word4 <= word3 && word4 <= word1)
		{
			cout << word4;
		}

		else if (word4 >= word3 && word4 >= word5 && word4 <= word2 && word4 <= word1)
		{
			cout << word4;
		}

		else if (word5 >= word1 && word5 >= word2 && word5 <= word3 && word5 <= word4)
		{ 
			cout << word5;
		}

		else if (word5 >= word1 && word5 >= word3 && word5 <= word2 && word5 <= word4)
		{
			cout << word5;
		}

		else if (word5 >= word1 && word5 >= word4 && word5 <= word2 && word5 <= word3)
		{
			cout << word5;
		}

		else if (word5 >= word2 && word5 >= word3 && word5 <= word1 && word5 <= word4)
		{
			cout << word5;
		}

		else if (word5 >= word2 && word5 >= word4 && word5 <= word3 && word5 <= word1)
		{
			cout << word5;
		}

		else if (word5 >= word3 && word5 >= word4 && word5 <= word2 && word5 <= word1)
		{
			cout << word5;
		}
		cout << ", ";

		//Display fourth word


		if (word1 <= word2 && word1 >= word3 && word1 >= word4 && word1 >= word5)
		{ 
			cout << word1;
		}

		else if (word1 <= word3 && word1 >= word4 && word1 >= word2 && word1 >= word5)
		{
			cout << word1;
		}

		else if (word1 <= word4 && word1 >= word3 && word1 >= word2 && word1 >= word5)
		{
			cout << word1;
		}

		else if (word1 <= word5 && word1 >= word3 && word1 >= word2 && word1 >= word4)
		{
			cout << word1;
		}

		else if (word2 <= word1 && word2 >= word3 && word2 >= word4 && word2 >= word5)
		{
			cout << word2;
		}

		else if (word2 <= word3 && word2 >= word1 && word2 >= word4 && word2 >= word5)
		{
			cout << word2;
		}

		else if (word2 <= word4 && word2 >= word1 && word2 >= word3 && word2 >= word5)
		{
			cout << word2;
		}

		else if (word2 <= word5 && word2 <= word1 && word2 >= word3 && word2 >= word4)
		{
			cout << word2;
		}

		else if (word3 <= word1 && word3 >= word2 && word3 >= word4 && word3 >= word5)
		{
			cout << word3;
		}

		else if (word3 <= word2 && word3 >= word1 && word3 >= word4 && word3 >= word5)
		{
			cout << word3;
		}

		else if (word3 <= word4 && word3 >= word1 && word3 >= word2 && word3 >= word5)
		{
			cout << word3;
		}

		else if (word3 <= word5 && word3 >= word1 && word3 >= word2 && word3 >= word4)
		{
			cout << word3;
		}	

		else if (word4 <= word1 && word4 >= word2 && word4 >= word5 && word4 >= word3)
		{
			cout << word4;
		}

		else if (word4 <= word2 && word4 >= word1 && word4 >= word3 && word4 >= word5)
		{
			cout << word4;
		}

		else if (word4 <= word3 && word4 >= word1 && word4 >= word2 && word4 >= word5)
		{
			cout << word4;
		}

		else if (word4 <= word5 && word4 >= word1 && word4 >= word2 && word4 >= word3)
		{
			cout << word4;
		}	

		else if (word5 <= word1 && word5 >= word2 && word5 >= word4 && word5 >= word3)
		{
			cout << word5;
		}

		else if (word5 <= word2 && word5 >= word1 && word5 >= word3 && word5 >= word4)
		{
			cout << word5;
		}

		else if (word5 <= word3 && word5 >= word1 && word5 >= word2 && word5 >= word4)
		{
			cout << word5;
		}

		else if (word5 <= word4 && word5 >= word1 && word5 >= word2 && word5 >= word3)
		{
			cout << word5;
		}	
		cout << ", ";

		//Display fifth word

		if (word1 >= word2 && word1 >= word3 && word1 >= word4 && word1 >= word5)
		{ 
			cout << word1 << endl;
		}

		else if (word2 >= word1 && word2 >= word3 && word2 >= word4 && word2 >= word5)
		{
			cout << word2 << endl;
		}

		else if (word3 >= word1 && word3 >= word2 && word3 >= word4 && word2 >= word5)
		{
			cout << word3 << endl;
		}

		else if (word4 >= word1 && word4 >= word2 && word4 >= word3 && word2 >= word5)
		{
			cout << word4 << endl;
		}

		else if (word5 >= word1 && word5 >= word2 && word5 >= word3 && word5 >= word4)
		{
			cout << word5 << endl;
		}
	}

return 0;
}
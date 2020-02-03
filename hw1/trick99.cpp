/*********
* COMP1
* Homework 1
* Problem 3
* Ethan Sorkin
* 
* prompt player one for a number between 10-49 (predicted answer)
* prompt player two for a number between 50-99
* variables: player one, player two 
*****/

#include <iostream>
using namespace std;
int main ()
{
 int player1, player2;
 cout << "Player 1: Enter a predicted answer between 10 and 49" << endl;
 cin >> player1;
 cout << "Player 2: Enter a number between 50 and 99" << endl;
 cin >> player2; 
 player1 = player2 - (((99 - player1) + player2) - 99);
 cout << "Actual result: ";
 cout << player1 <<  endl;
 cout << "And voila! Player 1's predicted answer was correct!" << endl;
 return 0;
   }

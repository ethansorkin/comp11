/* COMP11
 * Spring 2017
 * Lab 2 Starter Code
 * Craps game (buggy)
 *
 *Bugs found:
 *case 7 had no break
 *several coditionals within while loops did not dclare the game to be over (game_over = true)
 *change while-do conditional from || to &&
 *Added brackets to conditional when c == 'n'
 *no conditional statement for c == 'y'
 *change from roll = point to roll == point
 *no input for case 2 and case 3 (changed it to display message that you lose)
 **/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function prototype to roll two dice
int roll_dice();

int main() 
{
	int wallet = 1000;
	bool game_over = false;

	 // Seed the random number generator
	srand((unsigned int)time(NULL));

	while (!game_over) {
		cout << "Enter amount to bet. You have $" << wallet << endl;
		int bet;
		cin >> bet;

		if (bet <= 0)
			cout << "Bet must be positive." << endl;
		else if (bet > wallet)
			cout << "You don't have that much money." << endl;
		else {
			int roll = roll_dice();
			cout << "You rolled " << roll << endl;

			//Initial roll
			switch (roll) {
			case 7:
				cout << "You win!" << endl;
				wallet += bet;
				game_over = true;
				  break;
		        case 2:
				  cout << "You lose." << endl;
				wallet -= bet;
				game_over = true;
				break;

			case 3:
				  cout << "You lose." << endl;
				wallet -= bet;
				game_over = true;
				break;
			case 12:
				cout << "You lose." << endl;
				wallet -= bet;
				game_over = true;
				break;
			default:
				// Continue rolling until we roll the point
				// or 7
				int point = roll;
				cout << "The point is " << point << endl;
			do {
					roll = roll_dice();
					cout << "You rolled " << roll << endl;
					if (roll == 7) {
						cout << "You lose." << endl;
						wallet -= bet;
						game_over = true;
					}
					else if (roll == point) {
						cout << "That matches the point!" <<
							" You win!" << endl;
						wallet += bet;
						game_over = true;
					}
				} while ((roll != 7) && (roll != point));
			}
		}
		if (wallet == 0) {
			cout << "You are penniless. Thanks for playing." << endl;
			game_over = true;
		}
		else {
			cout << "Play again? (y/n)" << endl;
			char c;
			cin >> c;
			if (c=='n')
			  {
				game_over = true;
			  }
			else
			  {
			    game_over = false;
			  }
		}
		cout << "You ended the game with $" << wallet << endl;
	}


	return 0;
}

// Simulate rolling two dice.  We need a separate call
// to rand() for each die roll to get the same distribution
// as rolling two actual dice.
int roll_dice() {
	return (rand() % 6 + rand() % 6 + 2);
}

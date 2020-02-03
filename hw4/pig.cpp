/* Ethan Sorkin
 * COMP11
 * Spring 2017
 * HW4 (PIG game)
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Function prototype: check_for_win
int check_for_win(int, int);
// Function prototype: end_round
int end_round(int, int &, int &, int);
//Function prototype: roll
int roll();

// Number of points needed to win
const int THRESHOLD = 20;

int main () 
{
	// Seed the random variable
	srand(time(NULL));

	// Total number of points for each player and round_points.
	int pone_points = 0, ptwo_points = 0, round_points = 0;

	// Whose turn it is. Player One always starts.
	int turn = 1;

	//Whether the player chooses to roll or hold (0 or 1)
	int move, roll_result;

	// Is the game over yet
	bool game_over = false;

	// While loop for the game. A game comprises several rounds.
	while( !game_over )
	{
		bool round_over = false;

		// Announce whose turn it is
		cout << "Player " << turn << " is up!\n";
		while (!round_over)
		{
			do
			{
				cout << "Enter 0 to roll or 1 to hold" << endl;
				cin >> move;
			} while (!(move == 0 || move == 1)); //make sure user enters 1 or 0

			
			if (move == 0)
			{
				roll_result = roll();
		    	if (roll_result == 1)
		    	{
		    		cout << "You rolled a 1." << endl;
		    		cout << "Round over, no points! :(" << endl << endl;
		    		round_points = 0;
		    		turn = end_round(turn, pone_points, ptwo_points, 
		    		round_points);
		    		round_over = true;
		    		cout<< "Player 1 has " << pone_points << " points" << endl;
	  				cout << "Player 2 has " << ptwo_points << " points" << 
	  				endl << endl;
		    	}
		    	else
		    	{
					round_points = round_points + roll_result;
					cout << "You rolled a " << roll_result << endl;
					cout << "Current round points: " << round_points; 
					cout << endl <<endl;
		    	}
		  	}

		  	else if (move == 1)
		  	{
		  		turn = end_round(turn, pone_points, ptwo_points, round_points);
		  		round_over = true;
		  		cout << "End of round." << endl;
		  		cout << "Player 1 has " << pone_points << " points" << endl;
		  		cout << "Player 2 has " << ptwo_points << " points" << 
		  		endl << endl;
		  		round_points = 0;
		  	}
		} // round over while loop (end of round)
		
		//check for winner after every round
		int winner = check_for_win(pone_points, ptwo_points);
		if (winner == 1 || winner == 2)
		{
			cout<< "Congratulations player " << winner << ". You won!" << endl;
			cout << "Game over. Thanks for playing." << endl;
			game_over = true;
		}
	} // end game while loop (game over)

	// Game is over. End the program.
	return 0;
}

/****************************************
 * NO NEED TO MODIFY CODE BELOW THIS POINT    *
 ****************************************/

// FUNCTION DEFINITION
// Function check_for_win
// Arguments:
//	Player 1 and 2's points (ints)
// Returns:
//	0 is game is not over
// 	1 if player one won
// 	2 if player two won
// Does:
// 	Compares each score to the threshold
int check_for_win(int pone_points, int ptwo_points)
{
	// Check the players' current points against the threshold
	if( pone_points >= THRESHOLD ) 
	{			
		return 1;
	}
	else if( ptwo_points >= THRESHOLD )
	{
		return 2;
	}	
	
	// If we didn't meet either condition,
	// then nobody won
	return 0;
}

// FUNCTION DEFINITION
// Function end_round
// Arguments:
// 	1. whose turn it is (int)
//	2. player one's points (int, by ref)
// 	3. player two's points (int by ref)
// 	4. round points (int)
// Returns:
//	# of updated turn
// Does:
//	Updates p1 and p2 points
//	Switches whose turn it is
int end_round(int turn, int &pone_points, int &ptwo_points, int round_points)
{
	if(turn == 1)
	{
		pone_points += round_points;
		return 2;
	}
	else{
		ptwo_points += round_points;
		return 1;
	}

}

//Roll function
int roll()
{
	int roll = rand() % 6 + 1;
	return roll;
}

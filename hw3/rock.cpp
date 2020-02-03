/***********
*ETHAN SORKIN
*Comp 11
*Homework 3
*Problem 1
*
*Question: how do you shorten very long lineS?
*use do/while loop to ask for moves, cin user1/2move
*Use boolean statements to weight r vs p vs s
*display what happened and who won
*enter that player one wins round n, 
*n increases by one evey time and so does the round #
*repeat 2 more times
*variables: user1move, user2move, r, s, p
**************/

#include <iostream>
using namespace std;

int main ()

{
	char user1move, user2move;
	int n, user1points = 0, user2points = 0;

	//n represents round number (which is why i did <= 3 rather than < 3)
	for (n = 1; n <= 3; n++)
	{

		//prompt user and checks for invalid input with != expressions
		do
		{
			cout << "Player one: r, s, or p? (enter lowercase)" << endl;
			cin >> user1move;
		} while (user1move != 'r' && user1move != 's' && user1move != 'p');

		do
		{
			cout << "Player two: r, s, or p? (enter lowercase)" << endl;
			cin >> user2move;
		} while (user2move != 'r' && user2move != 's' && user2move != 'p');

		//player 1 wins, gains 1 point
		if (user1move == 'r' && user2move == 's')
		{
			cout << "Rock breaks scissors. Player one wins round ";
			cout << n <<"!" << endl;
			user1points++;
		}

		else if (user1move == 's' && user2move == 'p')
		{
			cout << "Scissors cut paper. Player one wins round ";
			cout << n <<"!" << endl;
			user1points++;
		}

		else if (user1move == 'p' && user2move == 'r')
		{
			cout << "Paper covers rock. Player one wins round ";
			cout << n <<"!" << endl;
			user1points++;
		}

		//player2 wins, gains one point
		else if (user2move == 'r' && user1move == 's')
		{
			cout << "Rock breaks scissors. Player two wins round ";
			cout << n <<"!" << endl;
			user2points++;
		}

		else if (user2move == 's' && user1move == 'p')
		{
			cout << "Scissors cut paper. Player two wins round ";
			cout << n <<"!" << endl;
			user2points++;
		}

		else if (user2move == 'p' && user1move == 'r')
		{
			cout << "Paper covers rock. Player two wins round ";
			cout << n <<"!" << endl;
			user2points++;
		}

		//Tie, no points
		else if (user2move == 'r' && user1move == 'r')
		{
			cout << "Rock for everyone. Round " << n << " is a tie!" << endl;
		}

		else if (user2move == 's' && user1move == 's')
		{
			cout << "Scissors for everyone. Round " << n << " is a tie!" 
			<< endl;
		}

		else if (user2move == 'p' && user1move == 'p')
		{
			cout << "Paper for everyone. Round " << n << " is a tie!" << endl;
		}
	}

	//Player 1: winner
	if (user1points > user2points)
	{
		cout << "Player one wins with ";
		cout << user1points;
		cout << " points!" << endl;
	}

	//Player 2: winner
	else if (user2points > user1points)
	{
		cout << "Player two wins with ";
		cout << user2points;
		cout << " points!" << endl;
	}

	//Tie: No winner
	else if (user2points == user1points)
	{
		cout << "The game is a tie. No winner." << endl;
	}

	return 0;
}
#include "board.h"
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

//Board constructor
Board::Board()
{
	empty_count = 0;
	board_size = 0;
	new_tile_value = 0;
	user_board = NULL;
	turn_score = 0;
}

Board::~Board()
{
	for(int i = 0; i < board_size; i++)
		delete[] user_board[i];		//delete each sub-array
	delete[] user_board;		//delete array of pointers
}

//Getters. Return values
int Board::get_empty_count()
{
	return empty_count;
}

int Board::get_board_size()
{
	return board_size;
}

int Board::get_new_tile_value()
{
	return new_tile_value;
}

int Board::get_turn_score()
{
	return turn_score;
}

//Setters
//ARE THE PURPOSE OF THESE TO CHANGE THE ATTRIBUTES?
void Board::set_empty_count()
{
	for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
            if (user_board[i][j] == EMPTY_TILE)
            {
                empty_count++;
               	//counts number of empty tiles
            }
        }
    }
}
void Board::set_board_size()
{
	cout << "Welcome to 2048. What dimensions would you like to play with?" 
	<< endl;
	do
	{
		cout << "Please enter an integer between 2 - 10." << endl;
		cin >> board_size;
		if (board_size < 2 || board_size > 10)
			cout << "Invalid input." << endl;
	} while (board_size < 2 || board_size > 10);
}

//EXTRA CREDIT: give user option between 3 levels when chosing board size
void Board::set_board_size_extra()
{
	int difficulty_level = 0;
	cout << "Welcome to 2048. What difficulty level would you like to play ";
	cout << "with?" << endl;
	do
	{
		cout << "Please enter 1, 2, or 3. ";
		cout << "(1 = Easy, 2 = Intermediate, 3 = Difficult)" << endl;
		cin >> difficulty_level;
		if (difficulty_level < 1 || difficulty_level > 3)
			cout << "Invalid input." << endl;
	} while (difficulty_level < 1 || difficulty_level > 3);
	if (difficulty_level == 1)
		board_size = 5;
	else if (difficulty_level == 2)
		board_size = 4;
	else if (difficulty_level == 3)
		board_size = 3;
}


int Board::set_new_tile_value()
{
	int chance = rand() % 10;
	if (chance == 0)
		return 4;
	else
		return 2;
}

void Board::set_turn_score()
{
	turn_score = 0;
}


//creates first version of board
void Board::allocate_board()
{
 
	user_board = new int*[board_size];
	for(int i = 0; i < board_size; i++)
		user_board[i] = new int[board_size];

	for (int i = 0; i < board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
			user_board[i][j] = EMPTY_TILE;
	}
	user_board[0][0] = 2;
	user_board[board_size - 1][board_size - 1] = 2;

}



//Prints the board at its current state
//NEED TO ADJUST SPACE BASED ON NUMBER SIZE
void Board::print_board(int user_score)
{
	cout << "Current score: " << user_score << endl;

	//SEG FAULT

    for (int i = 0; i < board_size; i++)
    {
        for (int j = 0; j < board_size; j++)
        {
        	
        	if (user_board[i][j] == EMPTY_TILE)
        		cout << "X    ";		//4 spaces after X
        	
        	else
        	{	
        		if (user_board[i][j] > 0 && user_board[i][j] < 10)
        			cout << user_board[i][j]<< "    "; //4 spaces after 1 digit
        		else if (user_board[i][j] > 9 && user_board[i][j] < 100)
        			cout << user_board[i][j] << "   "; //3 spaces after 2 digit
        		else if (user_board[i][j] > 99 && user_board[i][j] < 1000)
        			cout << user_board[i][j] << "  "; //2 spaces after 3 digit
        		else if (user_board[i][j] > 999 && user_board[i][j] < 10000)
        			cout << user_board[i][j] << " "; //1 spaces after 4 digit
        		else if (user_board[i][j] > 9999 && user_board[i][j] < 100000)
        			cout << user_board[i][j]; //0 spaces after 5 digit int
        	}
        }
        cout << endl << endl;
    }
}

//Alters the gameboard by shifting the tiles upward
//return: void, input: none
bool Board::move_up()
{
	
	bool board_change = false;
	for(int i = 0; i < (board_size - 1); i++)
	{

		for(int j = 0; j < board_size; j++)
		{
			bool combine = false; //makes sure that 224 doesnt become XX8
			//Third for loop iterates through multiple times so that 
			//tiles get all the way to the top
			for (int k = 0; k < (i+1); k++)
			{
				if (user_board[i-k][j] == EMPTY_TILE)
				{
					user_board[i-k][j] = user_board[i+1-k][j];
					user_board[i+1-k][j] = EMPTY_TILE;
					if (user_board[i-k][j] != EMPTY_TILE)
						board_change = true;	
				}
				else if(user_board[i-k][j] == user_board[i+1-k][j] && !combine)
				{
					user_board[i-k][j] += user_board[i+1-k][j];
					user_board[i+1-k][j] = EMPTY_TILE;
					turn_score += user_board[i-k][j];
					combine = true;
					board_change = true;
				}
			}
		}
	}
	return board_change;
}

//Alters the gameboard by shifting the tiles leftward
//return: void, input: none
bool Board::move_left()
{
	bool board_change = false;
	for(int j = 0; j < (board_size-1); j++)
	{
		for(int i = 0; i < board_size; i++)
		{
			bool combine = false;		//true after combination has been made
			for (int k = 0; k < (j+1); k++)
			{
				if (user_board[i][j-k] == EMPTY_TILE)
				{
					user_board[i][j-k] = user_board[i][j+1-k];
					user_board[i][j+1-k] = EMPTY_TILE;
					if (user_board[i][j-k] != EMPTY_TILE)
						board_change = true;
				}
				else if(user_board[i][j-k] == user_board[i][j+1-k] && !combine)
				{
					user_board[i][j-k] += user_board[i][j+1-k];
					user_board[i][j+1-k] = EMPTY_TILE;
					turn_score += user_board[i][j-k];
					combine = true;	//prevents board from adding too many times
					board_change = true;

				}
			}
		}
	}
	return board_change;
}

//Alters the gameboard by shifting the tiles downward
//return: void, input: none
bool Board::move_down()
{
	bool board_change = false;
	for(int i = (board_size-1); i > 0; i--)
	{
		for(int j = 0; j < board_size; j++)
		{
			bool combine = false;
			for (int k = 0; k < (board_size-i); k++)
			{
				if (user_board[i+k][j] == EMPTY_TILE)
				{
					user_board[i+k][j] = user_board[i-1+k][j];
					user_board[i-1+k][j] = EMPTY_TILE;
					if (user_board[i+k][j] != EMPTY_TILE)
						board_change = true;
				}
				else if(user_board[i+k][j] == user_board[i-1+k][j] && !combine)
				{
					user_board[i+k][j] += user_board[i-1+k][j];
					user_board[i-1+k][j] = EMPTY_TILE;
					turn_score += user_board[i+k][j];
					combine = true;
					board_change = true;
				}
			}
		}
	}
	return board_change;
}

//Alters the gameboard by shifting the tiles rightward
//return: void, input: none
bool Board::move_right()
{
	bool board_change = false;
	for(int j = (board_size-1); j > 0; j--)
	{
		for(int i = 0; i < board_size; i++)
		{
			bool combine = false;
			for (int k = 0; k < (board_size-j); k++)
			{
				if (user_board[i][j+k] == EMPTY_TILE)
				{
					user_board[i][j+k] = user_board[i][j-1+k];
					user_board[i][j-1+k] = EMPTY_TILE;
					if (user_board[i][j+k] != EMPTY_TILE)
						board_change = true;
				}
				else if(user_board[i][j+k] == user_board[i][j-1+k] && !combine)
				{
					user_board[i][j+k] += user_board[i][j-1+k];
					user_board[i][j-1+k] = EMPTY_TILE;
					turn_score += user_board[i][j+k];
					combine = true;
					board_change = true;
				}
			}
		}
	}
	return board_change;
}
//Calls 2 functions: one to set new tile value, one for new location
//This alters user_board
//return: void, input: none
void Board::new_tile()
{
	new_tile_value = set_new_tile_value();
	new_tile_location();
}



//finds random border element and sets it equal to new_tile_value
//alters user_board
//return: void, input: none
void Board::new_tile_location ()
{
	for (int i = 0; i < board_size; i++)
	{
		if(user_board[0][i] == EMPTY_TILE)
		{
			user_board[0][i] = new_tile_value;
			break;
		}
		else if (user_board[board_size-1][i] == EMPTY_TILE)
		{
			user_board[board_size-1][i] = new_tile_value;
			break;
		}
		else if (user_board[i][0] == EMPTY_TILE)
		{
			user_board[i][0] = new_tile_value;
			break;
		}
		else if (user_board[i][board_size-1] == EMPTY_TILE)
		{
			user_board[i][board_size-1] = new_tile_value;
			break;
		}

	}
}

//Checks to see if player has lost the game after every turn
//Iterates through user_board
//return: bool, input: none
bool Board::check_for_lose()
{
	empty_count = 0;
	set_empty_count();
	if (empty_count != 0)
		return false;
	else
	{
		bool game_over = check_touching_tiles();
		return game_over;
	}
}

//checks to see if there are adjacent tiles
bool Board::check_touching_tiles()
{
	for (int i = 0; i < (board_size); i++)
	{
		for (int j = 0; j < (board_size); j++)
		{
			//CONDITIONALS FOR TOUCHING TILES
			if(j < (board_size-1) && (user_board[i][j] == user_board[i][j+1]))
			{
				return false; 
			}
			else if ((j > 0) && (user_board[i][j] == user_board[i][j-1]))
			{
				return false;
			}
			else if ((i < (board_size-1)) && 
			(user_board[i][j] == user_board[i+1][j]))
			{
				return false;
			}
			else if ((i > 0) && (user_board[i][j] == user_board[i-1][j]))
			{
				return false;
			}
		}
	}

	return true;
}
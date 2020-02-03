/******
* Ethan Sorkin 
* COMP11
* HW 6
* 
* Signed off by Suruchi Devanahalli, 4/11
*****/

#include <iostream>
#include <string>
using namespace std;

#ifndef BOARD_H_
#define BOARD_H_

const int EMPTY_TILE = -1;

class Board
{
	private:
		//Holds the number of empty tiles, marked with an X
		int empty_count;

		//dimensions of the board
		int board_size;

		//2D dynamic array that holds board values
		int **user_board;

		//value of new tile that is created after turn
		int new_tile_value;

		//Holds value for user's points earned for a given turn
		int turn_score;


	public:
		//Constructor: initializes integers to 0, and array user_board to NULL
		Board();

		//Destructor: deletes dynamically allocated array
		~Board();

		//Getters: gets values of attributes

		//return: empty_count value, no parameters
		int get_empty_count();

		//return: board_size value, no parameters
		int get_board_size();

		//return: new_tile_value value, no parameters
		int get_new_tile_value();

		//return: turn_score, no input
		int get_turn_score();

		

		//Setters

		//counts number of empty tiles by iterating through the board
		//return: void, input: none
		void set_empty_count();

		//determines board dimensions based on user input
		//return: void, input: new board size
		void set_board_size();

		void set_board_size_extra();

		//Assigns new_tile_value to either 4 (10% chance) or 2 (90% chance)
		//return : int, input: none
		int set_new_tile_value();

		//Changes every turn based on user's move
		//return: void, input: none 
		void set_turn_score();


		//creates first version of board using board_size
		//return: void, input: none
		void allocate_board();

		//Prints the board at its current state
		//return: void, input: none
		void print_board(int);

		//Alters the gameboard by shifting the tiles upward
		//return: void, input: none
		bool move_up();

		//Alters the gameboard by shifting the tiles leftward
		//return: void, input: none
		bool move_left();

		//Alters the gameboard by shifting the tiles downward
		//return: void, input: none
		bool move_down();

		//Alters the gameboard by shifting the tiles rightward
		//return: void, input: none
		bool move_right();

		//Calls 2 functions: one to set new tile value, one for new location
		//This alters user_board
		//return: void, input: none
		void new_tile();

		//finds random border element and sets it equal to new_tile_value
		//alters user_board
		//return: void, input: none
		void new_tile_location ();

		//Checks to see if player has lost the game after every turn
		//Iterates through user_board
		//return: bool, input: none
		bool check_for_lose();

		bool check_touching_tiles();

};

#endif
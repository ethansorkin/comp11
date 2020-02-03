/******
* Ethan Sorkin
* COMP11
* HW 6
* 
* Signed off by Suruchi Devanahalli, 4/11
*****/

#include <iostream>
#include <string>
#include "board.h"
using namespace std;

#ifndef GAME_H_
#define GAME_H_

const string HIGHSCORE = "highscore.txt";

class Game
{
	private:
		//Data type Board that holds values for attributes of the 2048 board
		Board gameboard;

		//Holds user's total score at any given time in the game
		int user_score;

		//true for when the game is over
		bool game_over;

		//Dynamic array that holds high score values
		int *high_score_ray;

		//Dynamic array that holds user names
		string *user_name_ray;

		//number of scores one file
		int num_scores;

		
	public:
		//Constructor
		//No return type, no input
		Game();

		//Destructor
		//No return type, no input
		~Game();

		//Getters: gets values of attributes
		//return: user_score value, no input
		int get_user_score();

		//return: game_over value, no input
		bool get_game_over();

		//return: number of high scores, no input
		int get_num_scores();


		//Setters

		//Updates user's score after every move
		//return: void, input: turn_score
		void set_user_score(int);


		//Changes game_over variable based on user's input
		//return: void, input: game_over value
		void set_game_over();

		void set_num_scores();




		//function that begins gameplay and calls other functions
		//that are needed throughout the game
		//return: void, input: none
		void run_game();

		void run_game_extra();

		void allocate_high_score();

		//Alters dynamic array gameboard to change based on user input
		//return: void, input: user's move
		void run_move();

		//Reads into high score file and prints top 5 scores
		//return: void, input: none
		void show_highscore();

		//funciton that runs after the player has lost the game
		//return: void, input: none
		void game_loss();

		//Reads out score to the high score file and puts it in correct order
		//return: void, input: none
		void check_for_highscore(string);


};

#endif
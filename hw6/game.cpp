#include "game.h"
#include "board.h"
#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <fstream>

//Constructor
Game::Game()
{
	user_score = 0;
	high_score_ray = NULL;
	game_over = false; //doesn't need setter because only changes in functions
	user_name_ray = NULL;
	num_scores = 0;
	
}

//Destructor
Game::~Game()
{
	delete[] high_score_ray;
	delete[] user_name_ray;
}

//Getters
int Game::get_user_score()
{
	return user_score;
}


bool Game::get_game_over()
{
	return game_over;
}

int Game::get_num_scores()
{
	return num_scores;
}



//Setters
void Game::set_user_score(int turn_score)
{
	user_score += turn_score;
}

void Game::set_num_scores()
{
	ifstream infile;
	infile.open(HIGHSCORE.c_str());
	int score;
	string name;

	while (!infile.eof())
	{

		infile >> name >> score;
		if (name == "-1")
			break;
		num_scores++;
	}
	infile.close();
}


//function that begins gameplay and calls other functions
//that are needed throughout the game
void Game::run_game()
{
	allocate_high_score();

	gameboard.set_board_size();

	gameboard.allocate_board();

	cout << "Starting Game! High score: " << high_score_ray[0] << endl;

	while (game_over != true)
	{
		gameboard.print_board(user_score);
		gameboard.set_turn_score();
		run_move();
		if (game_over == true)
			break;
		int turn_score = gameboard.get_turn_score();
		set_user_score(turn_score);
		game_over = gameboard.check_for_lose();
	}

}

//function that begins gameplay and calls other functions
//that are needed throughout the game
void Game::run_game_extra()
{
	allocate_high_score();

	gameboard.set_board_size_extra();

	gameboard.allocate_board();

	cout << "Starting Game! High score: " << high_score_ray[0] << endl;

	while (game_over != true)
	{
		gameboard.print_board(user_score);
		gameboard.set_turn_score();
		run_move();
		if (game_over == true)
			break;
		int turn_score = gameboard.get_turn_score();
		set_user_score(turn_score);
		game_over = gameboard.check_for_lose();
	}

}

//Fills arrays with highscores and names
void Game::allocate_high_score()
{
	set_num_scores();
	//cout << num_scores << endl;
	
	high_score_ray = new int[num_scores+1];
	user_name_ray = new string[num_scores+1];

	ifstream infile; //DO I NEED TO DECLARE THIS AGAIN
	infile.open(HIGHSCORE.c_str());
	int score;
	string name;
	while (!infile.eof())
	{
		for (int i = 0; i < num_scores; i++)
		{
			infile >> name >> score;
			if (name == "-1")
				break;
			user_name_ray[i] = name;
			high_score_ray[i] = score;
		}
	}
	
	infile.close();
}

//Alters dynamic array gameboard to change based on user input
void Game::run_move()
{
	char user_move;
	do
	{
		cout << "Enter your move. (w = up, a = left, s = down, d = right, ";
		cout << "h = see top-5 high scores, q = quit)" << endl;
		cin >> user_move;
	} while (user_move != 'w' && user_move != 'a' && user_move != 's' &&
		user_move != 'd' && user_move != 'h' && user_move != 'q'); //validation
	if(user_move == 'w')
	{
		if (gameboard.move_up()) //These conditionals only creates new tile
			gameboard.new_tile(); //if the board is changed
	}
	else if (user_move == 'a')
	{
		if (gameboard.move_left())
			gameboard.new_tile();
	}
	else if (user_move == 's')
	{
		if (gameboard.move_down())
			gameboard.new_tile();
	}
	else if (user_move == 'd')
	{
		if (gameboard.move_right())
			gameboard.new_tile();
	}
	else if (user_move == 'h')
		show_highscore();
	else if (user_move == 'q')
		game_over = true;
}


void Game::show_highscore ()
{
	for (int i = 0; i < 5; i++)
	{
		cout << user_name_ray[i] << " " << high_score_ray[i] << endl;
	}
}

//funciton that runs after the player has lost the game
void Game::game_loss()
{
	string user_name;
	gameboard.print_board(user_score);
	cout << "Game over! Your final score was: " << user_score << endl;
	cout << "Please enter your name" << endl;
	cin >> user_name;
	check_for_highscore(user_name);
	show_highscore();
}


//Reads out score to the high score file and puts it in correct order
void Game::check_for_highscore(string user_name)
{
	bool score_insert = false;
	for (int i = 0; i < (num_scores + 1); i++)
	{
		if (user_score >= high_score_ray[i])
		{
			for (int j = num_scores; j > i; j--) //shifts elements to right
			{
				high_score_ray[j] = high_score_ray[j-1];
				user_name_ray[j] = user_name_ray[j-1];
			}
			high_score_ray[i] = user_score;
			user_name_ray[i] = user_name;
			score_insert = true;
		}
		if (score_insert)
			break;
	}
	ofstream outfile;
	outfile.open(HIGHSCORE.c_str());
	for (int i = 0; i < (num_scores + 1); i++)
		outfile << user_name_ray[i] << " " << high_score_ray[i] << endl;
	outfile << "-1" << endl;
	outfile.close();
}





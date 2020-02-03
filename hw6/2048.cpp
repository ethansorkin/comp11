/*
* Ethan Sorkin
* Comp11
* HW 7
* 2048 Program
*/

#include <iostream>
#include "game.h"
#include "board.h"
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
	Game gameplay;
	gameplay.run_game();
	gameplay.game_loss();
	return 0;
}
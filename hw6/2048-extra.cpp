/*
* Ethan Sorkin
* Comp11
* HW 7
* 2048-extra Program
*
* EXTRA CREDIT: For the extra credit I have given the user the option between
* three difficulty levels
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
	gameplay.run_game_extra();
	gameplay.game_loss();
	return 0;
}
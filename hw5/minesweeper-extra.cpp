/* Ethan Sorkin
 * COMP11
 * HW5 
 *Minesweeper
 *
 *EXTRA CREDIT: I chose the extra credit option to give the user the option to
 give up and see where the mines are.
 */

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

const int DIMEN = 9;
const int MAX_MINES = 50;
const char MINE = 'x';
const char UNSEEN = '-';

// function prototypes
void print_board(char [][DIMEN]);
void populate_plain_board(char [][DIMEN]);
void populate_mineboard (char [][DIMEN], int);
bool check_for_mine (int, int, char [][DIMEN], char [][DIMEN], bool);
char cast_int (int);
bool check_for_win (char board[][DIMEN], bool game_over);

int main()
{
    srand(time(NULL));

    int row, column, num_mines = 0;
    char user_board[DIMEN][DIMEN];
    char mineboard[DIMEN][DIMEN];
    bool game_over = false;
    populate_plain_board(user_board);
    populate_mineboard(mineboard, num_mines); //populate 9x9 board with mines


    cout << "Let's play minesweeper!\n";

    while (!game_over)
    {
        print_board(user_board);

        do
        {
            cout << "Enter the row and column number of the square to uncover"
            << endl;
            cout << "(row first, column second)." << endl;
            cout << "Or enter -1 to give up and see where the mines are" 
            << endl;
            cin >> row;
            if (row == -1)
            {
                game_over = true;  //this ends the game while loop
                break;
            }
            cin >> column;

        } while (!(row <= 8 && row >= 0 && column >= 0 && column <= 8)); 
        //input validation

        if (row == -1)
        {
            game_over = true;
            print_board(mineboard);
            cout << "You gave up. Thanks for playing." << endl;
            break;
        }

            game_over = check_for_mine (row, column, user_board, mineboard, 
            game_over);
            game_over = check_for_win (mineboard, game_over);
    }

    return 0;
}


// Function: populate_plain_board
// Input: 2d array of chars
// Returns: nothing
// Does: puts the UNSEEN char in all squares
void populate_plain_board(char board[][DIMEN])
{
    for (int i = 0; i < DIMEN; i++)
        for (int j = 0; j < DIMEN; j++)
            board[i][j] = UNSEEN;
}

// Function print_board
// Input: 2d array of chars
// Returns: nothing
// Does: Prints the given 2d array 
//       as well as headers for indices
void print_board(char board[][DIMEN])
{
    cout << "  ";
    for (int i = 0; i < DIMEN; i++)
        cout << i << " ";
    cout << endl;

    for (int i = 0; i < DIMEN; i++)
    {
        cout << i << " ";
        for (int j = 0; j < DIMEN; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void populate_mineboard (char board[][DIMEN], int num_mines)
{
    int random_mine;
    for (int i = 0; i < DIMEN; i++)
    {
        for (int j = 0; j < DIMEN; j++)
        {
            random_mine = rand() % 4;  //25% chance for mine

            if (random_mine == 1 && num_mines < MAX_MINES) 
            {
                    board [i][j] = MINE; //If mine is dropped, change '-' to
                    num_mines++;         //'x' in both boards
            }
            else
                board[i][j] = UNSEEN;
        }
    }
}

bool check_for_mine (int row, int column, char board[][DIMEN], 
    char mineboard [][DIMEN], bool game_over)
{
    int touching_mines = 0;
    char surrounding_mines = '0';

    if (mineboard [row][column] == MINE)
    {
        game_over = true;
        print_board(mineboard);
        cout << "You hit a mine! You lose. Thanks for playing." << endl; 
    }
        
    else
    {
        if (mineboard [row - 1][column - 1] == MINE && row > 0 && column > 0)
            touching_mines++;
        if (mineboard [row][column - 1] == MINE && column > 0)
            touching_mines++;
        if (mineboard [row + 1][column - 1] == MINE && row < 8 && column > 0)
            touching_mines++;
        if (mineboard [row - 1][column] == MINE && row > 0)
            touching_mines++;
        if (mineboard [row + 1][column] == MINE && row < 8)
            touching_mines++;
        if (mineboard [row - 1][column + 1] == MINE && row > 0 && column < 8)
            touching_mines++;
        if (mineboard [row][column + 1] == MINE && column < 8)
            touching_mines++;
        if (mineboard [row + 1][column + 1] == MINE && row < 8 && column < 8)
            touching_mines++;
        //acounts for edge cases (makes sure 0 < row/column < 8)

        //cast int touching_mines as char in this function
        surrounding_mines = cast_int (touching_mines);
        board [row][column] = surrounding_mines; 
        mineboard [row][column] = surrounding_mines;
        //change value of that space in mineboard and userboard
    }
    return game_over;
}

char cast_int (int touching_mines)
{
    switch (touching_mines)
    {
        case 1:
        {
            return '1';
            break;
        }
         case 2:
        {
            return '2';
            break;
        }
         case 3:
        {
            return '3';
            break;
        }
         case 4:
        {
            return '4';
            break;
        }
         case 5:
        {
            return '5';
            break;
        }
         case 6:
        {
            return '6';
            break;
        }
         case 7:
        {
            return '7';
            break;
        }
         case 8:
        {
            return '8';
            break;
        }
        default:
        {
            return '0';
            break;
        }
    }
}

bool check_for_win (char mineboard[][DIMEN], bool game_over)
{
    int dash_count = 0;
    for (int i = 0; i < DIMEN; i++)
    {
        for (int j = 0; j < DIMEN; j++)
        {
            if (mineboard[i][j] == UNSEEN)
            {
                dash_count++;
                 //This ends game when all squres are occupied
                //squares are either occupied with 'x' or number for win
            }
        }
    }

    if (dash_count == 0)
    {
        game_over = true;
        cout << "You have uncovered all the safe squares. You win! "; 
        cout << "Thanks for playing." << endl;
    }
    return game_over;
}


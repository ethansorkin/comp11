/***********
*ETHAN SORKIN
*Comp 11
*Homework 3
*Problem 2
*
*variables: flip, num_beans, beans_taken, n, cointoss
*we dont have to say what side of the coin came up, so just .5 chance of h/t
*use do/while statements to check for good input for cointoss and taking beans
*use a for loop to play game 3 times
*else if statements will change if the user can only take 2 or 1 bean
*Welcome user and ask them to pick a coin side
*do srand() for toss and if statements to say who won/ who goes first
*
***********/

#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int main ()
{
	int flip, num_beans, beans_taken, user_beans, n;
	char cointoss;
	do
	{
		cout << "Welcome to Nim. I’ll flip a coin. Enter h or t." << endl;
		cin >> cointoss;
	} while (cointoss != 'h' && cointoss != 't');


	
	for (n = 1; n <= 3; n++)
	{
		//coin flip
		srand (time(NULL));
		flip =  rand() % 2;
		num_beans = rand() % 25 + 5;

		if (flip == 0)
		{
			cout << "Game " << n << ": You start. ";

			do
			{
				if (num_beans > 0)
				{
						cout << "There are " << num_beans << " beans. ";

						//do while loop makes sure user only enters
						do
						{
							if (num_beans == 2)
							{
								cout << "How many do you take? Enter 1 or 2" 
								<< endl;
								cin >> user_beans;
							}
							else if (num_beans == 1)
							{
								cout << "You must take 1 bean." << endl;
								cin >> user_beans;
							}
							else
							{
								cout<<"How many do you take? Enter 1, 2, or 3." 
								<< endl;
								cin >> user_beans;
							}
						} while ((user_beans != 1 && user_beans != 2
							&& user_beans != 3)|| user_beans > num_beans);
						num_beans = num_beans - user_beans;
				}

				else if (num_beans == 0)
				{
					cout << "Congratulations, you win!" << endl;
					num_beans = num_beans - 1; //makes numbeans negative
				}
				

				if (num_beans > 0)
				{
				

						//making sure comp doesn't take more beans than in pile
						if (num_beans == 2)
						{
							beans_taken = rand() % 2 + 1;
						}
						else if (num_beans == 1)
						{
							beans_taken = 1;
						}
						else 
						{
						beans_taken = rand() % 3 + 1;
						}

						//prompting computer for beans
						cout << "There are " << num_beans 
							 << " beans. Ill take ";
						cout << beans_taken << "." << endl;
						num_beans = num_beans - beans_taken;
				}	

				else if (num_beans == 0)
				{
					cout << "Hooray, I win!" << endl;
					num_beans = num_beans - 1; //makes #beans neg (stops loop)
				}
				
			} while (num_beans >= 0);

			//This changes value of flip so other player starts next round
			flip = flip + 1;
		}

		else if (flip == 1)
		{
			cout << "Game " << n << ": I start. ";

			do
			{
				if (num_beans > 0)
				{
					
						//making sure comp doesn't take more beans than in pile
						if (num_beans == 2)
						{
							beans_taken = rand() % 2 + 1;
						}
						else if (num_beans == 1)
						{
							beans_taken = 1;
						}
						else 
						{
						beans_taken = rand() % 3 + 1;
						}

					cout << "There are " << num_beans << " beans. ";
					cout << "I'll take " << beans_taken << "." << endl;
					num_beans = num_beans - beans_taken;
				}
					
				else if (num_beans == 0)
				{
					cout << "Hooray, I win!" << endl;
					num_beans = num_beans - 1; //makes numbeans negative
				}
				
			
				if (num_beans > 0)
				{
						cout << "There are " << num_beans << " beans. ";
			
						do
						{
							if (num_beans == 2)
							{
								cout << "How many do you take? Enter 1 or 2" 
								<< endl;
								cin >> user_beans;
							}
							else if (num_beans == 1)
							{
								cout << "You must take 1 bean." << endl;
								cin >> user_beans;
							}
							else
							{
							cout << "How many do you take? Enter 1, 2, or 3." 
							<< endl;
							cin >> user_beans;
							}
						} while ((user_beans != 1 && user_beans != 2 
							&& user_beans != 3)|| user_beans > num_beans);
						num_beans = num_beans - user_beans;
				}

				else if (num_beans == 0)
				{
					cout << "Congratulations, you win!" << endl;
					num_beans = num_beans - 1;
				}

			
			} while (num_beans >= 0);

			flip = flip - 1;
		}
	}

	cout << "Game over. Thanks for playing!" << endl;
	
	return 0;
}
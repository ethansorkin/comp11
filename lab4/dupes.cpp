/* COMP11
 * Ethan Sorkin, Long Tran
 * Spring 2017
 * Lab 4 - Starter Code 
 *
 *EXTRA CREDIT #1 ANSWER: We do not need to change anything because this
 *function will already always generate duplicates.  If r is a random
 *integer between (0-MAX*2/3), and MAX=20, then the range of possible
 *elements in the array is (0-13). Since there are 20(MAX) elements in the
 *array, there is bound to be at least 6 duplicates every time.

*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// constant for array capacity
const int MAX = 20;

// function prototypes 
void populate(int []);
void print_array(int [], int);
int dedupe (int []);

int main()
{
	// Random-number seed
    srand(time(NULL));

	// Declare an array of ints
	// and populate it.
    int ray_dupes[MAX];
    populate(ray_dupes);

	// Print the array so we know the starting point
    print_array(ray_dupes, MAX);

    int size = dedupe(ray_dupes);
    print_array(ray_dupes, size);

    return 0;
}


// Function populate
// Input: array of ints
// Returns: nothing
// Does: populates the array with
// 		 random numbers
void populate(int ray[])
{
    int r;
    for(int i = 0; i < MAX; i++)
    {
        r = rand() % MAX * 2 / 3;
        ray[i] = r;
    }
}

// Function print_array
// Input: array of ints, size of array
// Returns: nothing
// Does: prints array elements
void print_array(int ray[], int size)
{
    for(int i = 0; i < size; i++)
        cout << ray[i] << " ";
    cout << endl;
}


int dedupe (int ray_dupes[])
{
  int size = MAX;       //size of array
  for (int i = 0; i < size; i++)
  {
    for (int j =(i+1); j < size; j++)
      {
	 if (ray_dupes[i] == ray_dupes[j])
	 {
	   do                 //do-while loop accounts for adjacent dupes
	   {
	   for (int k = j; k < size; k++)
	     ray_dupes[k] = ray_dupes[k+1];
	   size--;                  //decreases size of array for every dupe
	   }while(ray_dupes[i] == ray_dupes[j]);
	 }
      }
  }

  return (size); 
}	   

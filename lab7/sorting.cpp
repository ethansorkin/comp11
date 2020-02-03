/* COMP11, Spring 2017
 * Ethan Sorkin and Long Tran
 * 4/18/17
 * Lab 7 
 * Sorting 
 *
 * sort_one: Insertion sort
 * We believe that this is insertion because when we tested it with differently
 * sorted inputs, it did the best when the numbers started in backwards order.
 *
 * sort_two: Bubblesort
 * We believe that this is a bubblesort function because it was considerably
 * more efficient when the input began in sorted order, rather than backwards.
 *
 * sort_three: Mergesort
 * We believe this function is mergesort because it is consistently the most
 * efficient among the four functions. Also it was consistent between trials.
 *
 * sort_four: Selection sort
 * We believe this function is selection sort because it is faster than
 * sort_two (which we believe to be bubblesort), and is very consistent between
 * trials.
 */

#include <iostream>
#include <cstdlib>
using namespace std;

// Sorting function prototypes
int sort_one(int [], int);
int sort_two(int [], int);
int sort_three(int [], int, int);
int sort_four(int [], int);
int helper(int [], int, int, int);

//EXTRA CREDIT: search function
bool search(int [], int, int);

// Prototypes for funcs to populate the arrays
void populate_rand(int a[], int);
void populate_order(int a[], int);
void populate_backward(int a[], int);

// Prototype: Helper function to print an array of ints
void print_array(int [], int);

// Largest possible array size, largest possible number
const int MAX_SIZE = 5000;
const int MIN_SIZE = 1;
const int RAND_RANGE = 200;

int main()
{
        // Initial set up to fill in the array with random #s
        srand(time(NULL));

        // Declare and initialize the arrays (one for each sort function)
        int ray_one[MAX_SIZE];
        int ray_two[MAX_SIZE];
        int ray_three[MAX_SIZE];
        int ray_four[MAX_SIZE];
        int fill_size, ray_order;

        //holds value for number of steps each algorithm requires
        int num_steps;

        int starting_point = 0;

        // End-user decides how many elements actually go in the array
        // (but the max. size is a const)
        do
        {
                cout << "How many numbers should we test with? Between "
                        << MIN_SIZE << " and " << MAX_SIZE << ", please.\n";
                cin >> fill_size;
        } while (fill_size < MIN_SIZE || fill_size > MAX_SIZE);

        // You can fill in the array with random numbers
        // or completely ordered, or completely unordered
        do {
                cout << "How ordered should we begin the array?\n";
                cout << "1 - Totally random\n";
                cout << "2 - Totally in order\n";
                cout << "3 - Totally backwards\n";
                cin >> ray_order;
        } while (ray_order != 1 && ray_order != 2 && ray_order != 3);

        // Call the correct function to populate the three arrays
        // based on the order the user wants
        if (ray_order == 1)
        {
                populate_rand(ray_one, fill_size);
                populate_rand(ray_two, fill_size);
                populate_rand(ray_three, fill_size);
                populate_rand(ray_four, fill_size);
        }
        else if (ray_order == 2)
        {
                populate_order(ray_one, fill_size);
                populate_order(ray_two, fill_size);
                populate_order(ray_three, fill_size);
                populate_order(ray_four, fill_size);
        }
        else
        {
                populate_backward(ray_one, fill_size);
                populate_backward(ray_two, fill_size);
                populate_backward(ray_three, fill_size);
                populate_backward(ray_four, fill_size);
        }

        // YOUR CODE HERE!
        // CALL EACH SORTING ALGORITHM TO RUN YOUR EXPERIMENTS
        // AND PRINT THE NUMBER OF STEPS EACH ONE RETURNS

        num_steps = sort_one (ray_one, fill_size);
        cout << endl << num_steps << endl;
        num_steps = sort_two (ray_two, fill_size);
        cout << num_steps << endl;
        num_steps = sort_three (ray_three, starting_point, fill_size);
        cout << num_steps << endl;
        num_steps = sort_four (ray_four, fill_size);
        cout << num_steps << endl;

        int search_num;
        cout << "What number would you like to search for?" << endl;
        cin >> search_num;
        bool found = search(ray_one, search_num, fill_size);

        cout << found<< endl;

        return 0;

}

//EXTRA CREDIT: search function
bool search(int ray[], int search_num, int size)
{
    for(int i=0; i < size; i++)
    {
        if (ray[i] == search_num)
            return true;
    }
    return false;
}

/***************************************/
/***************************************/
/***************************************/
/* NO NEED TO EDIT ANYTHING BELOW HERE! */
/***************************************/
/***************************************/
/***************************************/


// Sort One
// Input: 1d array of ints, size
// Returns: # of steps required for the algorithm
int sort_one(int a[], int size)
{
        // curr_value holds the value of the current
        // element we're "considering"
        int curr_value;

        // Track the number of steps the algorithm needs
        int steps = 0;

        // Iterate through the entire array
        for (int i = 0; i < size; i++)
        {

                curr_value = a[i];

                // Iterate through the sorted subsection
                // to see where curr_value goes
                for (int j = 0; j < i; j++)
                {
                        steps++;
                        if (curr_value < a[j])
                        {
                                for (int k = i; k > j; k--)
                          		{
                                        a[k] = a[k-1];
                                }
                                a[j] = curr_value;
                                break;
                        }
                }
        }
        return steps;
}

// Sort Two
// Input: 1d array of ints, size
// Returns: # of steps required to do the sort
int sort_two(int a[], int size)
{
        // Track the number of steps the algorithm needs
        int steps = 0;
        // Iterate through from end to beginning
        for (int i = size - 1; i > 0; i--)
        {
                steps++;
                for (int j = 0; j < i; j++)
                {
                        // Swap if current element is > element to its right
                        steps++;
                        if (a[j] > a[j+1])
                        {
                                steps++;
                                int temp = a[j+1];
                                a[j+1] = a[j];
                                a[j] = temp;
                        }
                }
        }
        return steps;
}

// Sort Three
// Input: Array of ints, starting point, size
// Returns: Number of steps
int sort_three(int a[], int low, int high)
{
        int steps = 0;
        int mid;
        // Use as stopping condition, when starting point overtakes ending point
        if (low < high)
        {
                // udpate steps
                steps++;
                // find the middle of the array
                mid = (low+high)/2;

                // recursive call to sort the front/back halves of the array
                sort_three(a,low,mid);
                sort_three(a,mid+1,high);
                steps += helper(a,low,high,mid);
        }
        return steps;

}

// Sort four
// Input: Array of ints, size
// Returns: # of steps
int sort_four(int a[], int size)
{
        int steps = 0;
        for (int start = 0; start < size; start++)
        {
                steps++;
                int smallest = start;

				for (int curr = start + 1; curr < size; curr++)
                {
                        steps++;
                        if (a[curr] < a[smallest])
                                smallest = curr;
                }

                std::swap(a[start], a[smallest]);
        }
        return steps;
}

// Helper function for sort 3
int helper(int a[], int low, int high, int mid)
{
        int steps = 0;
        int i, j, k, c[MAX_SIZE];
        i = low;
        k = low;
        j = mid + 1;
        while (i <= mid && j <= high)
        {
                steps++;
                if (a[i] < a[j])
                {
                        c[k] = a[i];
                        k++;
                        i++;
                }
                else
                {
                        c[k] = a[j];
                        k++;
                        j++;
                }
        }
        while (i <= mid)
        {
                steps++;
                c[k] = a[i];
                k++;
                i++;
        }
        while (j <= high)
        {
                steps++;
                c[k] = a[j];
                k++;
                j++;
        }
        for (i = low; i < k; i++)
        {
                steps++;
                a[i] = c[i];
        }

        return steps;
}

// Populate array -- random
void populate_rand(int a[], int size)
{
        for(int i = 0; i < size; i++)
        {
                a[i] = rand() % RAND_RANGE;
        }
}

//  Populate array -- ordered
void populate_order(int a[], int size)
{
        for(int i = 0; i < size; i++)
        {
                a[i] = i;
        }
}

// Populate array -- backwards
void populate_backward(int a[], int size)
{
        for(int i = 0; i < size; i++)
        {
                a[i] = size - i;
        }
}

// Print array helper function
void print_array(int a[], int size)
{
        for(int i = 0; i < size; i++)
        {
                cout << a[i] << " ";
        }
        cout << endl;
}

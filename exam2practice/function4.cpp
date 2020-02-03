#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int DIMEN = 3;

int count_occurences (int[][DIMEN], int);
int main()
{
	int num1, num_occurences;
	int num_ray[DIMEN][DIMEN];
	cout << "Enter " << 9 << " array elements" << endl;
	for (int n = 0; n < 3; n++)
	{
		for (int i = 0; i < 3; i++)
		{
				cin >> num_ray[n][i];
		}
	}

	cout << "Enter an int to check for" << endl;
	cin >> num1;
	num_occurences = count_occurences(num_ray, num1);
	cout << "Number of occurences: " << num_occurences << endl;

	return 0;
}

int count_occurences (int num_ray[][DIMEN], int num1)
{
	int count = 0;
	for (int n = 0; n < 3; n++)
	{
		for (int i = 0; i < 3; i++)
		{
				if (num_ray[n][i] == num1)
					count++;
		}
	}

	return count;
}
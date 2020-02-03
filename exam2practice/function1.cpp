#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int count_lines ();

int main ()
{
	int num_lines = count_lines();
	cout << num_lines/2 <<endl;
}

int count_lines()
{
	int count = 0;
	ifstream infile;
	infile.open("babynames.txt");
	while (!infile.eof())
	{
		string baby_name;
		infile >> baby_name ;
		if (baby_name == "-1")
			break;
		count++;
	}
	return count;
}
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

string print_name(ifstream &, int);
int main ()
{
	ifstream infile;
	int count = 0;
	char filename [50];
	cout << "Enter the name of the file you want to access." << endl;
	cin >> filename;
	infile.open(filename);		//opening file

	if (!infile.is_open())	//validation
	{
		cerr << "Error opening file" << endl;
		return 1;
	}

	while (!infile.eof())
	{
		string baby_name;
		int num_babies;
		infile >> baby_name >> num_babies;
		if (baby_name == "-1")
			break;
		count++;
	} 

	infile.close();

	infile.open(filename);
	int line_num;
	cout << "Enter line number" << endl;
	cin >> line_num;
	string name;
	name = print_name(infile, line_num);
	cout << name << endl;
	infile.close();

	infile.open(filename);

	string *name_ray = new string [count];
	int *number_ray = new int [count];
	for (int i = 0; i < count; i++)
	{
		string baby_name;
		int num_babies;
		infile >> baby_name >> num_babies;
		if (baby_name == "-1")
			break;
		name_ray[i] = baby_name;
		number_ray[i] = num_babies;
	}





	string user_baby_name;
	cout << "Enter a baby name" << endl;
	cin >> user_baby_name;

	int found_name = 0;
	for (int n = 0; n < count; n++)
	{
		if (name_ray[n] == user_baby_name)
		{
			cout << "That name's popularity level is " << (n + 1) << endl;
			cout << "Number of babies with that name: " << number_ray [n] << endl;
			found_name++;
		}
	}

	if (found_name == 0)
		cout << "That name is not present in the list of names" << endl;

	delete [] name_ray;
	delete [] number_ray;
	infile.close(); 
	
	return 0;
}

string print_name (ifstream &infile, int line_num)
{
	string babyname;
	for (int i = 0; i < ((line_num*2)-1); i++)
	{
		
		infile >> babyname;
	}
	return babyname;
}



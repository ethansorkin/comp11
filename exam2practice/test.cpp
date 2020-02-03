#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX = 10;
int insert (int [], int, int);
int main()
{
	int size = MAX, new_num = 4, new_size;
	int num_ray[size];
	for (int j = 0; j < 8; j++)
	{
		num_ray[j] = j+1;
	}

	for (int h = 0; h < 8; h++)
		cout << num_ray[h] << endl;

	new_size = insert(num_ray, size, new_num);

	cout<< "New array: ";

	for (int q = 0; q < 9; q++)
		cout << num_ray[q] << endl;

}

int insert (int num_ray[], int size, int new_num)
{
	for(int n=0; n<size; n++)
	{
		if (new_num >= num_ray[n] && new_num <= num_ray[n+1])
		{
			for (int i= size; i>0; i--)
			{
				num_ray[i+1] = num_ray[i];
			}
			num_ray[n+1] = new_num;
			size++;
			return size;
		}
	}
	return size;
	/*if (new_num < num_ray[0])
	{
		for (int k = 0; k<size; k++)
		{
			num_ray[k+1] = num_ray[k];
		}
		num_ray[0] = new_num;
	}
	else if (new_num > num_ray[size])
	{
		num_ray[size+1] = new_num;
	}*/
	//size++;
	//return size;
}








/*int main()
{
	double *dptr = new double;
	cout << dptr << endl;
	cout << "Enter double" << endl;
	cin >> *dptr;
	cout <<"Here: "<< *dptr<<endl;
	cout << &dptr << endl;
	delete dptr;
}


int main ()
{
	ifstream infile;
	infile.open("babynames.txt");
	char name[MAX], num1[MAX];
	for (int i = 0; i < 10)
	{
		infile >> name[i] >> num1[i];

	}

}

void sort (char[],)*/
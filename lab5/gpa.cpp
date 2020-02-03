/* COMP11
 * Spring 2017
 * Lab 5 Starter Code
 * Converting grades to GPAs */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 50;

double convert_grade (string);
int main()
{
	// Variables for the filestream
	// and num classes the student has taken
	ifstream infile;
	int num_classes = 0;
	double gpas[MAX];
	//char filename[MAX];
	string filename;

	cout << "Enter file name you want to open" << endl;
	cin >> filename;
	infile.open(filename.c_str());		//opening file

	if (!infile.is_open())	//validation
	{
		cerr << "Error opening file" << endl;
		return 1;
	}

	while (!infile.eof())
	{
		string course_name, grade;
		infile >> course_name >> grade;
		if (course_name == "-1")
			break;
		gpas[num_classes] = convert_grade (grade);
		num_classes++;
	}

	cout << num_classes << endl;
	infile.close();

	

	// Now the array is populated with doubles.
	// Calculate the average GPA of the student.
	double avg_gpa, total = 0.0;
	for (int i = 0; i < num_classes; i++)
	{
		total += gpas[i];
	}
	avg_gpa = total / num_classes;
	cout << "The student's GPA is " 
		 << avg_gpa << endl;

	return 0;
}

	double convert_grade (string grade)
	{

		if (grade == "A") 
			return 4.0;
		if (grade == "A-") 
			return 3.67;
		if (grade == "B+") 
			return 3.33;
		if (grade == "B") 
			return 3.0;
		else
			return 2.67;	
	}

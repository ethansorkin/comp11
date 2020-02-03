/**********
*Ethan Sorkin
*Comp11
*Homework 2
*Problem 3
*
*variables: num_wheels, num_frames, num_links, num_bikes, leftover
*Ask how many wheels they have, cin num_wheels
**include if statement for invalid data
*display how many bikes thats enought for (num_wheels / 2)
**Ask how many frames they have, cin num_frames
**include if statement for invalid data
*display how many bikes thats enought for (num_frames)
*Ask how many links they have, cin num_links
**include if statement for invalid data
*display how many bikes thats enought for (num_links / 50)
*display "i can make you X bikes"
*num_bikes: smallest num_bikes/frames/links
********/

#include <iostream>
using namespace std;

const int WHEELS_NEEDED = 2, FRAMES_NEEDED = 1, LINKS_NEEDED = 50, MIN_VALUE = 0, MAX_VALUE = 5000;

int main ()
{
	int num_wheels, num_frames, num_links, num_bikes_w_frames = 0, num_bikes_w_wheels = 0; 
	int num_bikes_w_links = 0, total_bikes = 0, wheels_leftover, links_leftover, frames_leftover;
	
	//Wheels
	cout << "How many wheels do you have?" << endl;
	cin >> num_wheels;
	
	if (num_wheels < MIN_VALUE || num_wheels > MAX_VALUE)
	{
		num_wheels = WHEELS_NEEDED;
		num_bikes_w_wheels = num_wheels / WHEELS_NEEDED;
		cout << "Input is invalid. I'm going to assume you have " << num_wheels << " wheels." << endl;
		cout << "That's enough for 1 bike." << endl;
	}
	else
	{
	cout << "That's enough for ";
	num_bikes_w_wheels = num_wheels / WHEELS_NEEDED; //calculatuing how many bikes that can make
	cout << num_bikes_w_wheels; 
	cout << " bikes." << endl;
	}

	//Frames
	cout << "How many frames do you have?" << endl;
	cin >> num_frames;

	if (num_frames < MIN_VALUE || num_frames > MAX_VALUE)
	{
		num_frames = FRAMES_NEEDED;
		num_bikes_w_frames = num_frames / FRAMES_NEEDED;
		cout << "Input is invalid. I'm going to assume you have " << num_frames << " frame." << endl;
		cout << "That's enough for 1 bike." << endl;
	}
	else
	{
	cout << "That's enough for ";
	num_bikes_w_frames = num_frames / FRAMES_NEEDED; //caculating how many bikes that can make
	cout << num_bikes_w_frames; 
	cout << " bikes." << endl;
	}

	//Links
	cout << "How many links do you have?" << endl;
	cin >> num_links;

	if (num_links < MIN_VALUE || num_links > MAX_VALUE)
	{
		num_links = LINKS_NEEDED;
		num_bikes_w_links = num_links / LINKS_NEEDED;
		cout << "Input is invalid. I'm going to assume you have " << num_links << " links." << endl;
		cout << "That's enough for 1 bike." << endl;
	}
	else
	{
	cout << "That's enough for ";
	num_bikes_w_links = num_links / LINKS_NEEDED; //caculating how many bikes that can make
	cout << num_bikes_w_links; 
	cout << " bikes." << endl;
	}

	//Determining total number of bikes you can make
	//the smallest num_bikes value is going to be equal total_,bikes, so i will determine
	//that value using comparisons

	cout << "I can make you ";

	if (num_bikes_w_links <= num_bikes_w_frames && num_bikes_w_links <= num_bikes_w_wheels)
	{
		total_bikes = num_bikes_w_links;
	}
	else if (num_bikes_w_frames <= num_bikes_w_wheels && num_bikes_w_frames <= num_bikes_w_links)
	{
		total_bikes = num_bikes_w_frames;
	}
	else if (num_bikes_w_wheels <= num_bikes_w_frames && num_bikes_w_wheels <= num_bikes_w_links)
	{
		total_bikes = num_bikes_w_wheels;
	}

	cout << total_bikes;
	cout << " bikes, come back tomorrow with cash." << endl;
	cout << "I'm keeping the leftovers in my shop:" << endl;

	//Calculating leftover parts
	wheels_leftover = num_wheels - (total_bikes * WHEELS_NEEDED);
	frames_leftover = num_frames - (total_bikes * FRAMES_NEEDED);
	links_leftover = num_links - (total_bikes * LINKS_NEEDED);

	//must account for bad data input (if numer entered is less than zero or greater than 5000)
	cout << wheels_leftover;
	cout << " wheels, ";
	cout << frames_leftover;
	cout << " frames, ";
	cout << links_leftover;
	cout << " links." << endl;

return 0;
}
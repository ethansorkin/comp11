/******
* Ethan Sorkin and Long Tran
* COMP11
* Lab 6
* April 4
*****/


#include <iostream>
#include "planet.h"
#include <string>

using namespace std;

int main()
{
	int num_planets;
	cout << "How many planets do you think there are?" << endl;
	cin >> num_planets;
	while (num_planets < 1)
	{
		cout << "Please enter a positive value." << endl;
		cin >> num_planets;
	}
	Planet *system = new Planet [num_planets];
	for (int i = 0; i < num_planets; i++)
	{
		string planet_name, planet_color;
		int num_moons;
		double distance_sun, planet_diameter;

		cout << "What is the name of planet " << i + 1 << "?" << endl;
		cin >> planet_name;

		cout << "How manny moons does it have?" << endl;
		cin >> num_moons;
		while (num_moons < 0)
		{
			cout << "Please enter a positive value." << endl;
			cin >> num_moons;
		}

		cout << "How far from the sun, in millions of miles is it?" << endl;
		cin >> distance_sun;
		while (distance_sun <= 0)
		{
			cout << "Please enter a positive value." << endl;
			cin >> distance_sun;
		}

		cout << "What is the diameter of the planet in miles?" << endl;
		cin >> planet_diameter;
		while (planet_diameter <= 0)
		{
			cout << "Please enter a positive value." << endl;
			cin >> planet_diameter;
		}

		cout << "What is the color of the planet?" << endl;
		cin >> planet_color;


		system[i].set_name(planet_name);
		system[i].set_num_moons(num_moons);
		system[i].set_distance(distance_sun);
		system[i].set_diameter(planet_diameter);
		system[i].set_color(planet_color);
	}

	cout << "Thank you for your input!" << endl;
	cout << "Here are all the planets:" << endl;

	for (int i = 0; i < num_planets; i++)
	{
		system[i].print_data();
	}

	return 0;

}
#include <iostream>
#include <string>
using namespace std;

#ifndef PLANET_H_
#define PLANET_H_

class Planet
{
  private:
	// Attributes of a planet, always private
    string name, color;
    int num_moons;
    double distance, diameter;
  public:
	// Constructor
	Planet();

	// Setters and getters
	string get_name();
    int get_num_moons();
    double get_distance();
    double get_diameter();
    string get_color();

    void set_name(string);
    void set_num_moons(int);
    void set_distance(double);
    void set_diameter(double);
    void set_color(string);

	// Print a nicely-formatted version of the planet's data
    void print_data();
};

#endif

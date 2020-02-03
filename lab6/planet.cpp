#include "planet.h"

// Default constructor
Planet::Planet()
{
    name = "";
    num_moons = 0;
    distance = 0;
    diameter = 0;
    color = "";
}

// Getters. Return values.
string Planet::get_name()
{
    return name;
}

int Planet::get_num_moons()
{
    return num_moons;
}

double Planet::get_distance()
{
    return distance;
}

double Planet::get_diameter()
{
    return diameter;
}

string Planet::get_color()
{
    return color;
}

// Setters. Check for reasonable values.
// If unreasonable, stick with defaults.
void Planet::set_name(string n)
{
    if (n != "")
        name = n;
}

void Planet::set_num_moons(int n)
{
    if (n >= 0)
        num_moons = n;
}

void Planet::set_distance(double d)
{
    if (d >= 0)
        distance = d;
}

void Planet::set_diameter(double d)
{
    if (d >= 0)
        diameter = d;
}

void Planet::set_color(string c)
{
    if (c != "")
        color = c;
}

// Print all the planet's info
void Planet::print_data()
{
    cout << "Name: " << name << endl;
    cout << "Number of moons: " << num_moons << endl;
    cout << "Distance from the sun: " 
         << distance << " million miles\n";
    cout << "Diameter: " << diameter << " miles" << endl;
    cout << "Color: " << color << endl;
}

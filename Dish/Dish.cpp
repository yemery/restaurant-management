#include "Dish.h"

Dish::Dish() : Item(){};
Dish::Dish(string n, string d, double p) : Item(n, d, p) {}
Dish::Dish(Dish &d) : Item(d) {}

void Dish::display()
{
    cout << "Dish ID: " << id << endl;
    cout << "Dish Name: " << name << endl;
    cout << "Dish Description: " << description << endl;
    cout << "Dish Price: " << price << endl;
}
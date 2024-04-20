#include "Dish.h"

// Constructeurs de la classe Dish (par default , paramétré et par copie)
Dish::Dish() : Item(){};
Dish::Dish(string n, string d, double p) : Item(n, d, p) {}
Dish::Dish(Dish &d) : Item(d) {}

// une methode pour afficher les infromations du plat
void Dish::display()
{
    cout << "Dish ID: " << id << endl;
    cout << "Dish Name: " << name << endl;
    cout << "Dish Description: " << description << endl;
    cout << "Dish Price: " << price << endl;
}
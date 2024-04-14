#include "Drink.h"

Drink::Drink() : Item() {}
Drink::Drink(string n, string d, double p) : Item(n, d, p) {}
Drink::Drink(Drink &d) : Item(d) {}
void Drink::display()
{
    cout << "Drink ID: " << id << endl;
    cout << "Drink name: " << name << endl;
    cout << "Drink Description: " << description << endl;
    cout << "Drink Price: " << price << endl;
}
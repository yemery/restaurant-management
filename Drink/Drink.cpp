#include "Drink.h"

// Constructeurs de la classe Drink (par default , paramétré et par copie)
Drink::Drink() : Item() {}
Drink::Drink(string n, string d, double p) : Item(n, d, p) {}
Drink::Drink(Drink &d) : Item(d) {}

// une methode pour afficher les infromations du boisson
void Drink::display()
{
    cout << "Drink ID: " << id << endl;
    cout << "Drink name: " << name << endl;
    cout << "Drink Description: " << description << endl;
    cout << "Drink Price: " << price << endl;
}
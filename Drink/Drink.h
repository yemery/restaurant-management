#pragma once
#include "../Item/Item.h"

// Classe Drink héritée de la classe Item car une boisson est un item
class Drink : public Item
{
public:
    Drink();
    Drink(string, string, double);
    Drink(Drink &);
    void display();
};
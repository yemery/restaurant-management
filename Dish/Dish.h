#pragma once
#include "../Item/Item.h"
 
// Classe Dish héritée de la classe Item car un plat est un item
class Dish : public Item
{
public:
    Dish();
    Dish(string, string, double);
    Dish(Dish &);
    void display();
};
#pragma once
#include "../Item/Item.h"

class Drink : public Item
{
public:
    Drink();
    Drink(string, string, double);
    Drink(Drink &);
    void display();
};
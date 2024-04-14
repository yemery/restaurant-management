#pragma once
#include "../Item/Item.h"

class Dish : public Item
{
public:
    Dish();
    Dish(string, string, double);
    Dish(Dish &);
    void display();
};
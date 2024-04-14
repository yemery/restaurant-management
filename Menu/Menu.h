#pragma once
#include <iostream>
#include <vector>
#include "../Item/Item.h"
#include "../Dish/Dish.h"   
#include "../Drink/Drink.h"

class Menu
{
    friend class Order;

private:
    // vector<Dish *> dishes;
    // vector<Drink *> drinks;
    vector<Item *> items;

public:
    // void addDish();
    // void addDrink();
    void addToMenu();
    void display();
};
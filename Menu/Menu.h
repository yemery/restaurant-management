#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Item/Item.cpp"
#include "../Dish/Dish.cpp"
#include "../Drink/Drink.cpp"
#include "../Inventory/Inventory.h"

// Classe Menu qui contient un vecteur dynamique de pointeurs de type Item pour stocker les items du menu
class Menu
{
private:
    vector<Item *> menuItems;

public:
    void addItems(Inventory &);
    vector<Item *> getMenuItems();
    void display();
};

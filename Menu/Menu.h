#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Item/Item.cpp"
#include "../Dish/Dish.cpp"   
#include "../Drink/Drink.cpp"

class Menu
{
        // friend void addItemsOrder(Menu&);

private:
    vector<Item*> menuItems;
public:
    void addItems();
    vector<Item*> getMenuItems();
    
    void display();
    
    // ~Menu();
};



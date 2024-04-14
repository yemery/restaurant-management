#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../Item/Item.cpp"
#include "../Dish/Dish.cpp"   
#include "../Drink/Drink.cpp"

class Menu
{
private:
    vector<Item*> menuItems;
public:
    void addItems();

    
    void display();
    
    // ~Menu();
};



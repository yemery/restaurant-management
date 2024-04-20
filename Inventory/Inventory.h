#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include "../Item/Item.h"
#include "../Ingrediant/Ingrediant.cpp"
#include "../Menu/Menu.h"
#include "../Item/Item.cpp"
#include "../utils.cpp"
using namespace std;

class Inventory
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);

private:
    // vector<Item*> items;
    vector<Ingrediant *> itemsIngrediant;

public:
    // Inventory();
    void display();
    void addItems(Menu&);
    void updateItems();
    void displayItems();
    // ~Inventory();
};

#pragma once
#include <iostream>
#include <vector>
#include "../Item/Item.h"
#include "../Ingrediant/Ingrediant.h"
#include "../Item/Item.cpp"
// #include "../utils.cpp"
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
    void addItems();
    void updateItems();
    // ~Inventory();
};

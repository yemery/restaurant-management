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
// classe Inventory pour gérer les items  et leurs quantités
class Inventory
{
    // fonction amie pour trouver un item dans l'inventaire par son id pour accéder aux attributs privés de la classe
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    
private:
    vector<Ingrediant *> itemsIngrediant;

public:
    void display();
    void updateItems();
    void displayItems();
    void setItemsIngerediant(Ingrediant*);
    vector<Ingrediant *> getItemsIngrediant();
};


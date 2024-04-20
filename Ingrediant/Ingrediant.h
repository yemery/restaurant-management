#pragma once
#include <iostream>
#include <vector>
#include "../Item/Item.h"
using namespace std;

// Classe Ingrediant qui contient la quantité et l'item qui peut être un plat ou une boisson
class Ingrediant
{
private:
    int quantity;
    Item *item;

public:
    Ingrediant(int quantity, Item *item);
    Ingrediant(Ingrediant &);
    int getQuantity();
    void setQuantity(int);
    void display();
    int getItemId();
};

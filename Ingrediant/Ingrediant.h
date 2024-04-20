#pragma once
#include <iostream>
#include <vector>
#include "../Item/Item.h"
using namespace std;

class Ingrediant
{
private:
    int quantity;
    Item *item;

public:
    Ingrediant();
    Ingrediant(int quantity, Item *item);
    Ingrediant(Ingrediant &);
    int getQuantity();
    void setQuantity(int);
    void display();
    int getItemId();
    // ~Ingrediant();
};

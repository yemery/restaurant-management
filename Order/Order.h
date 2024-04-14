#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "../Item/Item.h"
#include "../Menu/Menu.h"


class Order
{
private:
    // vector<Dish *> dishes_list;
    // vector<Drink *> drinks_list;
    vector<Item *> itemsList;

public:
    // void addDish(Menu &);
    // void addDrink(Menu &);
    void addItem(Menu &);
    void caculateSum();
};

vector<Order *> order;
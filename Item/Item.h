#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../utils.cpp"
// #include "../Order/Order.h"

// we implemented this abstract class not to have a conflict in the ids of dishes and drinks while having a search
class Item
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    // friend class Order;

protected:
    int id;
    string name, description;
    double price;

public:
    static int idd;
    double getPrice();
    Item();
    Item(string, string, double);
    Item(Item &);
    virtual void display() = 0;
    // ~Item();
};
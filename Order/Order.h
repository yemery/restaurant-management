#pragma once
#include <iostream>
#include <vector>
#include "../Item/Item.cpp"
#include "../Menu/Menu.h"
#include "../Client/Client.cpp"
using namespace std;

class Order
{
    // friend void addItemsOrder(Menu&);
    friend void SumPerOrder();
private:
    vector<Item *> orderItems;
    Client* client;
public:
    // ~Order();
    void display();
    void caculateSum();
    Client& getClient();
    vector<Item *> getOrderItems();
    void setClient(Client* c);
    void setOrderItems(Item&);
};

vector<Order *> orders;


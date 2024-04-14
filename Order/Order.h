#pragma once
#include <iostream>
#include <vector>
#include "../Item/Item.cpp"
#include "../Menu/Menu.h"
#include "../Client/Client.cpp"
#include "../utils.cpp"

using namespace std;

class Order
{
    // friend void addItemsOrder(Menu&);
    template <class V, class I>
    friend optional<V> find(vector<V>, I);

    friend void SumPerOrder();
private:
    vector<Item *> orderItems;
    Client* client;
    int id;
public:
    static int idd;
    Order();
    void display();
    void caculateSum();
    Client* getClient();
    vector<Item *> getOrderItems();
    void setClient(Client* c);
    void setOrderItems(Item&);
    
};

vector<Order *> orders;


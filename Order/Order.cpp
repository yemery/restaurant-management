#include "Order.h"
// void Order::addDish(Menu &m)
void Order::addItem(Menu &m)
{
    cout << "-----------Add a dish to the command: ------------------" << endl;

    cout << "Enter the ID of the dish you want to add: ";
    int id;
    cin >> id;
    cout << id << endl;
    // check if the dish exists
    // for (int i = 0; i < dishes.size(); i++)
    // {
    //     if(dishes[i]->idd == id);
    // }

    auto findItem = find(m.items, id);
    if (findItem.has_value())
    {
        itemsList.push_back(findItem.value());
    }
}
void Order::caculateSum()
{

    // check later wether the itemsList is empty or not
    double total = 0;
    for (auto &i : itemsList)
    {
        // cout << i->price << endl;
        // fixed using getter  cus friend didint work
        total += i->getPrice();
    }
    cout << "The total price of the order is: " << total << endl;
}
#include "Order.h"

int Order::idd = 0;
Order::Order() : id(Order::idd++){};

void addItemsOrder(Menu &m)
{
    cout << "-----------Add items to the order: ------------------" << endl;
    int id, idClient;

    bool exist = false;
    Order *o = new Order(); // Step 2: Dynamically allocate memory
    // add multiple additions

    do
    {
        cout << "Enter ID of the client: ";
        cin >> idClient;
        for (Client *i : clients)
        {
            if (i->getId() == idClient)
            {
                o->setClient(i);
                cout << "Client added to the order" << endl;
                break;
            }
            else
            {
                cout << "Client not found" << endl;
                // delete o; // Step 3: Deallocate memory
                // return;
            }
        }

        cout << "Enter the id of the item you want to add:";
        cin >> id;

        for (Item *i : m.getMenuItems())
        {
            if (i->getId() == id)
            {
                o->setOrderItems(*i);
                cout << "Item added to the order" << endl;
                orders.push_back(o);
                break;
            }
        }

        cout << "Do you want to add more items? yes (0) no (1): ";
        cin >> exist;
    } while (exist == false);

    // delete o; // Step 3: Deallocate memory
}

void Order::display()
{
    cout << "Order ID: " << id << endl;
    for (Item *i : orderItems)
    {
        i->display();
    }
    cout << "Client Information:" << endl;
    client->display();
}

void displayOrders()
{
    cout << "-----------Display the order: ------------------" << endl;
    for (Order *i : orders)
    {
        cout << "Order: " << endl;
        i->display();
    }
}

void Order::caculateSum()
{
    double sum = 0;
    for (auto &i : orderItems)
    {
        sum += i->getPrice();
    }
    cout << "The total sum of the order is: " << sum << endl;
}

void SumPerOrder()
{
    cout << "-----------Calculate the sum of the orders: ------------------" << endl;
    for (auto &i : orders)
    {
        cout << "Order: " << endl;
        i->display();
        i->caculateSum();
    }
}

Client &Order::getClient()
{
    return *client;
}

vector<Item *> Order::getOrderItems()
{
    return orderItems;
}

void Order::setClient(Client *c)
{
    client = c;
}
void Order::setOrderItems(Item &i)
{
    orderItems.push_back(&i);
}

void calculateSumById()
{
    int id;

    cout << "Enter the id of the order you want to calculate the sum: ";
    cin >> id;
    auto foundOrder = find(orders, id);
    if (foundOrder.has_value())
    {
        foundOrder.value()->caculateSum();
    }
}
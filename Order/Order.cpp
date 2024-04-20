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
    cout << "Enter ID of the client: ";
    cin >> idClient;
    bool check = false;
    for (Client *i : clients)
    {
        if (i->getId() == idClient)
        {
            o->setClient(i);
            cout << "Client added to the order" << endl;
            check = true;
            break;
        }
      
    }
    if (!check)
    {
        cout << "Client not found" << endl;
        return;
    }

    do
    {

        cout << "Enter the id of the item you want to add:";
        cin >> id;

        for (Item *i : m.getMenuItems())
        {
            if (i->getId() == id)
            {
                // 1- check inventory of the item 2- add the item to the order
                
                o->setOrderItems(*i);
                cout << "Item added to the order" << endl;
                orders.push_back(o);
                break;
            }
        }

        cout << "Do you want to add more items? yes (0) no (1): ";
        cin >> exist;
    } while (exist == false);

   
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
    for (auto &i : orders)
    {
        i->display();
        i->caculateSum();
    }
}

Client *Order::getClient()
{
    return client;
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

void clientOrdersById()
{
    int id;

    cout << "Enter the client id to display the Orders:";
    cin >> id;
    auto foundClient = find(clients, id);
    if (foundClient.has_value())
    {
        for (Order *i : orders)
        {
            if (i->getClient()->getId() == id)
            {
                i->display();
            }
        }
    }
}
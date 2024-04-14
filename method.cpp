#include "header.h"






// void Menu::addDish(Dish& d){
//     dishes.push_back(d);
// }

// we tot abouri2 and radi ngolo lih 3lach andiro a 1 methode f menu li tajouti dish o drink
void Menu::addToMenu()
{
    cout << "-----------Add an item to the menu: ------------------" << endl;
    char choice;
    do
    {
        cout << "Enter the type of item you want to add: 1 for Dish, 2 for Drink: ";
        cin >> choice;

    } while (choice != '1' && choice != '2');
    cout << choice << endl;

    string name, description;
    double price;
    cout << "Enter the name of the item: ";
    cin >> name;
    cout << "Enter the description of the item: ";
    cin >> description;
    cout << "Enter the price of the item: ";
    //  add regex for cin attr
    cin >> price;

    cout << name << " " << description << " " << price << endl;

    // choice == '1' ? dishes.push_back(new Dish(name, description, price)) : drinks.push_back(new Drink(name, description, price));
    choice == '1' ? items.push_back(new Dish(name, description, price)) : items.push_back(new Drink(name, description, price));
    cout << "Item added successfully!" << endl;
}

void Menu::display()
{
    // checking lkhwa d array before displaying it
    // cout << "Dishes: " << endl;
    // for (int i = 0; i < dishes.size(); i++)
    // {
    //     dishes[i]->display();
    // }
    // cout << "Drinks: " << endl;
    // for (int i = 0; i < drinks.size(); i++)
    // {
    //     drinks[i]->display();
    // }

    for (auto &i : items)
    {
        i->display();
    }
    // for (auto &i : items)
    // {

    //     // get typo of an obj by using typeid
    //     // if (typeid(*i) == typeid(Dish))
    //     // {
    //     //     cout << "Dish" << endl;
    //     // }
    //     // else
    //     // {
    //     //     cout << "Drink" << endl;
    //     // }
    //     i->display();
    // }
}
int Reservation::idd = 0;
Reservation::Reservation() : date(""), hour(""), nbPeople(0), status(0), id(Reservation::idd++), client(){};
Reservation::Reservation(Client &c, string d, string h, int nb, int s) : date(d), hour(h), nbPeople(nb), status(s), id(Reservation::idd++), client(c) {}
Reservation::Reservation(Reservation &r) : date(r.date), hour(r.hour), nbPeople(r.nbPeople), status(r.status), client(r.client) {}
//  1 for waiting 2 canceled 3 confirmed
void Reservation::confirm()
{
    status = 3;
}
void Reservation::cancel()
{
    status = 2;
}
void Reservation::display()
{
    cout << "Reservation ID: " << id << endl;
    cout << "Reservation Date: " << date << endl;
    cout << "Reservation Hour: " << hour << endl;
    cout << "Number of people: " << nbPeople << endl;
    cout << "Reservation Status: " << status << endl;
}
int Client::idd = 0;
Client::Client() : firstName(""), lastName(""), phoneNumber(""), id(Client::idd++) {}
Client::Client(Client &c) : firstName(c.firstName), lastName(c.lastName), phoneNumber(c.phoneNumber), id(Client::idd++) {}
Client::Client(string f, string l, string p) : firstName(f), lastName(l), phoneNumber(p) {}



void Reservation::reserve()
{
    cout << "Reserve a table: " << endl;
    cout << "Give ID of client: ";
    int id;
    cin >> id;

    auto client = find(clients, id);
    if (!client.has_value())
    {
        cout << "Invalid client id" << endl;
    }
    else
    {
        string date, hour;
        int nbPeople, status;
        cout << "Enter the date of the reservation: ";
        cin >> date;
        cout << "Enter the hour of the reservation: ";
        cin >> hour;
        cout << "Enter the number of people: ";
        cin >> nbPeople;
        cout << "Enter the status of the reservation: ";
        cin >> status;
        reservations.push_back(new Reservation(*client.value(), date, hour, nbPeople, status));
        cout << "Reservation added successfully!" << endl;
    }
}

void Client::display()
{
    cout << "Client ID: " << id << endl;
    cout << "Client First Name: " << firstName << endl;
    cout << "Client Last Name: " << lastName << endl;
    cout << "Client Phone Number: " << phoneNumber << endl;

    for (int i = 0; i < reservations.size(); i++)
    {
        reservations[i]->display();
    }
}

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
        total += i->price;
    }
    cout << "The total price of the order is: " << total << endl;
}
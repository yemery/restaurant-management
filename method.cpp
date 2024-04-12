#include "header.h"

Dish::Dish() : name(""), description(""), price(0){};
Dish::Dish(string n, string d, double p) : name(n), description(d), price(p) {}
Dish::Dish(Dish &d) : name(d.name), description(d.description), price(d.price) {}

void Dish::display()
{
    cout << "Dish Name: " << name << endl;
    cout << "Dish Description: " << description << endl;
    cout << "Dish Price: " << price << endl;
}

Drink::Drink(string n, string d, double p) : name(n), description(d), price(p) {}
Drink::Drink() : name(""), description(""), price(0.0) {}
Drink::Drink(Drink &d) : name(d.name), description(d.description), price(d.price) {}
void Drink::display()
{
    cout << "Drink name: " << name << endl;
    cout << "Drink Description: " << description << endl;
    cout << "Drink Price: " << price << endl;
}

// void Menu::addDish(Dish& d){
//     dishes.push_back(d);
// }

// we tot abouri2 and radi ngolo lih 3lach andiro a 1 methode f menu li tajouti dish o drink
void Menu::addToMenu()
{
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

    choice == '1' ? dishes.push_back(new Dish(name, description, price)) : drinks.push_back(new Drink(name, description, price));
    cout << "Item added successfully!" << endl;
}

void Menu::display()
{
    // checking lkhwa d array before displaying it
    cout << "Dishes: " << endl;
    for (int i = 0; i < dishes.size(); i++)
    {
        dishes[i]->display();
    }
    cout << "Drinks: " << endl;
    for (int i = 0; i < drinks.size(); i++)
    {
        drinks[i]->display();
    }
}

Reservation::Reservation() : date(""), hour(""), nbPeople(0), status(0){};
Reservation::Reservation(string d, string h, int nb, int s) : date(d), hour(h), nbPeople(nb), status(s) {}
Reservation::Reservation(Reservation &r) : date(r.date), hour(r.hour), nbPeople(r.nbPeople), status(r.status) {}
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
    cout << "Reservation Date: " << date << endl;
    cout << "Reservation Hour: " << hour << endl;
    cout << "Number of people: " << nbPeople << endl;
    cout << "Reservation Status: " << status << endl;
}

Client::Client() : firstName(""), lastName(""), phoneNumber("") {}
Client::Client(Client &c) : firstName(c.firstName), lastName(c.lastName), phoneNumber(c.phoneNumber) {}
Client::Client(string f, string l, string p) : firstName(f), lastName(l), phoneNumber(p) {}
void Client::reserve()
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
    reservations.push_back(new Reservation(date, hour, nbPeople, status));
    cout << "Reservation added successfully!" << endl;
}

void Client::display()
{
    cout << "Client First Name: " << firstName << endl;
    cout << "Client Last Name: " << lastName << endl;
    cout << "Client Phone Number: " << phoneNumber << endl;

    for (int i = 0; i < reservations.size(); i++)
    {
        reservations[i]->display();
    }
}
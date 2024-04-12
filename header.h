#include <iostream>
#include <vector>
using namespace std;

// we implemented this abstract class not to have a conflict in the ids of dishes and drinks while having a search
class Item
{
protected:
    int id;
    string name, description;
    double price;

public:
    static int idd;
    Item();
    Item(string, string, double);
    Item(Item &);
    virtual void display() = 0;
    // ~Item();
};

class Dish : public Item
{
public:
    Dish();
    Dish(string, string, double);
    Dish(Dish &);
    void display();
};

class Drink : public Item
{
public:
    Drink();
    Drink(string, string, double);
    Drink(Drink &);
    void display();
};

// we will add display items method by id for the menu

class Reservation
{
private:
    int id;
    string date, hour;
    int nbPeople, status = 1;

public:
    static int idd;
    Reservation();
    Reservation(string, string, int, int);
    Reservation(Reservation &);

    void confirm();
    void cancel();
    void display();

    // ~Reservation();
};

// anzido l client vector dialo bach n3rfou list d clients

class Client
{
private:
    int id;
    string firstName, lastName, phoneNumber;
    vector<Reservation *> reservations;

public:
    static int idd;
    Client();
    Client(Client &);
    Client(string, string, string);
    // ~Client();

    void reserve();
    void cancelReserve();
    void display();
};
class Menu
{
    friend class Order;

private:
    // vector<Dish *> dishes;
    // vector<Drink *> drinks;
    vector<Item *> items;
    

public:
    // void addDish();
    // void addDrink();
    void addToMenu();
    void display();
};

class Order
{
private:
    vector<Dish *> dishes_list;
    vector<Drink *> drinks_list;

public:
    void addDish(Menu &);
    void addDrink(Menu &);
    void caculateSum();
};
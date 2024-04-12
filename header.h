#include <iostream>
#include <vector>
using namespace std;

// thinkin about adding abstract class Item


class Dish
{
private:
    int id;
    string name, description;
    double price;

public:
    static int idd;
    Dish();
    Dish(string, string, double);
    Dish(Dish &);
    void display();
};

class Drink
{
private:
    int id;
    string name, description;
    double price;

public:
    static int idd;
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
    vector<Dish *> dishes;
    vector<Drink *> drinks;

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
    void addDrink(Menu&);
    void caculateSum();
};
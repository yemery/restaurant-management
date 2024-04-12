#include <iostream>
#include <vector>
using namespace std;

// thinkin about adding abstract class Item
class Dish
{
private:
    string name, description;
    double price;
public:
    Dish();
    Dish(string, string, double);
    Dish(Dish &);
    void display(); 
};

class Drink
{
private:
    string name, description;
    double price;
public:
    Drink();
    Drink(string, string, double);
    Drink(Drink &);
    void display();

};

class Menu
{
private:
    vector<Dish*> dishes;
    vector<Drink*> drinks;
public:
    // void addDish();
    // void addDrink();
    void addToMenu();
    void display();
};


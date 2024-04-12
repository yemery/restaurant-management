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
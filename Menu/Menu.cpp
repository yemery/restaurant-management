#include "Menu.h"

void Menu::addItems()
{
    cout << "-----------Add items to the menu: ------------------" << endl;
    char choice;
    do
    {
        cout << "Enter the type of item you want to add: 1 for Dish, 2 for Drink: ";
        cin >> choice;

    } while (choice != '1' && choice != '2');
    // cout << choice << endl;

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

    choice == '1' ? menuItems.push_back(new Dish(name, description, price)) : menuItems.push_back(new Drink(name, description, price));
}

void Menu::display()
{
    for (auto &i : menuItems)
    {
        i->display();
    }
}
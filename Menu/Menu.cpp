#include "Menu.h"
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
#include "Menu.h"

// méthode pour ajouter des items au menu
void Menu::addItems(Inventory &i)
{
    cout << "-----------Add items to the menu: ------------------" << endl;
    char choice;
    do
    {
        cout << "Enter the type of item you want to add: 1 for Dish, 2 for Drink: ";
        cin >> choice;

    } while (choice != '1' && choice != '2');

    string name, description;
    double price;
    cout << "Enter the name of the item: ";
    cin >> name;
    cout << "Enter the description of the item: ";
    cin >> description;
    cout << "Enter the price of the item: ";
    cin >> price;

    // on ajoute l'item au menu selon le choix de l'utilisateur, si c'est un plat ou une boisson
    choice == '1' ? menuItems.push_back(new Dish(name, description, price)) : menuItems.push_back(new Drink(name, description, price));

    // on ajoute l'item à l'inventaire, on demande à l'utilisateur de saisir la quantité de l'item
    int quantity;
    // on vérifie si la quantité est supérieure à 0 pour ajouter l'item à l'inventaire sinon on demande à l'utilisateur de saisir une quantité valide
    do
    {
        cout << "Enter the quantity of item of the add it in inventory: ";
        cin >> quantity;
    } while (quantity < 0);

    // on ajoute l'item à l'inventaire
    i.setItemsIngerediant(new Ingrediant(quantity, menuItems.back()));
}

// méthode pour afficher les items du menu
void Menu::display()
{
    for (auto &i : menuItems)
    {
        i->display();
    }
}

// getter pour retourner les items du menu
vector<Item *> Menu::getMenuItems()
{
    return menuItems;
}
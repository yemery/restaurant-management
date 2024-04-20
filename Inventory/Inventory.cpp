#include "Inventory.h"

void Inventory::display()
{
    cout << "Inventory: " << endl;
    if (itemsIngrediant.size() == 0)
    {
        cout << "No itemsIngrediant in the inventory" << endl;
    }
    else
    {

        for (Ingrediant *i : itemsIngrediant)
        {
            i->display();
        }
    }
}
void Inventory::addItems(Menu &menu)
{
    int id, quantity;
    bool exist = false;
    cout << "Enter the id of the item: ";
    cin >> id;
    auto findItemInMenu = find(menu.getMenuItems(), id);
    if (findItemInMenu.has_value())
    {
        for (Ingrediant *i : itemsIngrediant)
        {
            if (i->getItemId() == id)
            {
                exist = true;
                break;
            }
        }
        if (exist)
        {
            cout << "Item already exists in the inventory!" << endl;
            cout << "Use updateItems method to update the quantity of the item in the inventory!" << endl;
        }
        else
        {
            cout << "Enter the quantity of the item: ";
            cin >> quantity;

            itemsIngrediant.push_back(new Ingrediant(quantity, findItemInMenu.value()));
        }
    }
    else
    {
        cout << "Item not found in the menu!" << endl;
        cout << "Add the item to the menu first!" << endl;
    }
}

void Inventory::updateItems()
{
    int id, quantity;
    cout << "Enter the id of the item: ";
    cin >> id;

    // if (findItemInInventory.has_value())
    // {
    //     cout << "Enter the quantity of the item: ";
    //     cin >> quantity;
    //     findItemInInventory.value()->setQuantity(quantity);
    // }
    // else
    // {
    //     cout << "Item not found in the inventory!" << endl;
    //     cout << "Add the item to the inventory first!" << endl;
    // }
    bool exist = false;

    for (Ingrediant *i : itemsIngrediant)
    {
        if (i->getItemId() == id)
        {
            cout << "Enter the quantity of the item: (use + to add and - to subtract): ";
            cin >> quantity;

            if (i->getQuantity() < abs(quantity))
            {
                cout << "Quantity cannot be negative!" << endl;
            }
            else
            {
                i->setQuantity(quantity);
            }

            exist = true;
            break;
        }
    }
    if (!exist)
    {
        cout << "Item not found in the inventory!" << endl;
        cout << "Add the item to the inventory first!" << endl;
    }
}

void Inventory::displayItems()
{
    if (itemsIngrediant.size() == 0)
    {
        cout << "No ingrediant in the inventory" << endl;
    }
    else
    {
        cout << "Inventory: " << endl;
        for (Ingrediant *i : itemsIngrediant)
        {
            i->display();
        }
    }
}
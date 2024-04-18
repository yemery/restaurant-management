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
void Inventory::addItems(){
    int id, quantity;
    cout << "Enter the id of the item: ";
    cin >> id;
    cout << "Enter the quantity of the item: ";
    cin >> quantity;
    // auto findItemIngrediant=find(itemsIngrediant,id);
    // pass menu in param 
    // auto findItemInItems=find(items,id);
    // 
    // Ingrediant *ingrediant = new Ingrediant(quantity, item);
    // itemsIngrediant.push_back(ingrediant);
}
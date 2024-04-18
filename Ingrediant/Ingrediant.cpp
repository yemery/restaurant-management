#include "Ingrediant.h"

// Ingrediant::Ingrediant() : quantity(0), item(nullptr) {}
Ingrediant::Ingrediant(int quantity, Item *item) : quantity(quantity), item(item) {}
Ingrediant::Ingrediant(Ingrediant &i) : quantity(i.quantity), item(i.item) {}

void Ingrediant::setQuantity(int q)
{
    quantity = q;
}
int Ingrediant::getQuantity()
{
    return quantity;
}

void Ingrediant::display()
{
    item->display();
    cout << " Quantity: " << quantity << endl;
}
#include "Ingrediant.h"

// Constructeurs de la classe Ingrediant (paramétré et par copie)
Ingrediant::Ingrediant(int quantity, Item *item) : quantity(quantity), item(item) {}
Ingrediant::Ingrediant(Ingrediant &i) : quantity(i.quantity), item(i.item) {}

// setter pour modifier la quantité d'un item
void Ingrediant::setQuantity(int q)
{
    quantity += q;
}

// getter pour obtenir la quantité d'un item
int Ingrediant::getQuantity()
{
    return quantity;
}

// une methode pour afficher les infromations de l'ingrediant
void Ingrediant::display()
{
    item->display();
    cout << "Quantity: " << quantity << endl;
}

// une getter pour accéder à l'ID de l'item qui est privé qui utilise la méthode getter de la classe Item
int Ingrediant::getItemId()
{
    return item->getId();
}
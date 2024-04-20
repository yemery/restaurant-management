#include "Inventory.h"

// méthode pour afficher les items de l'inventaire

void Inventory::display()
{
    cout << "Inventory: " << endl;
    // si le vecteur inventaire est vide on affiche un message
    if (itemsIngrediant.size() == 0)
    {
        cout << "No itemsIngrediant in the inventory" << endl;
    }
    else
    {

        for (Ingrediant *i : itemsIngrediant)
        {
            // on affiche les items de l'inventaire en utilisant la méthode display de la classe Itemé
            i->display();
        }
    }
}

// méthode pour mettre à jour les items de l'inventaire (ajouter ou soustraire la quantité d'un item)
void Inventory::updateItems()
{
    int id, quantity;
    // on demande à l'utilisateur d'entrer l'id de l'item
    cout << "Enter the id of the item: ";
    cin >> id;
    //
    bool exist = false;
    // on parcourt le vecteur itemsIngrediant pour chercher l'item par son id
    for (Ingrediant *i : itemsIngrediant)
    {
        if (i->getItemId() == id)
        {
            // si l'item est trouvé on demande à l'utilisateur d'entrer la quantité
            cout << "Enter the quantity of the item: (use + to add and - to subtract): ";
            cin >> quantity;
            // si la quantité est négative on utilise la valeur absolue de la quantité pour la comparer avec la quantité de l'item dans l'inventaire, la quantité ne peut pas être négative
            if (i->getQuantity() < abs(quantity))
            {
                // si la quantité est supérieure à la quantité de l'item dans l'inventaire on affiche un message d'erreur
                cout << "Quantity cannot be negative!" << endl;
            }
            else
            {
                // si la quantité est valide on met à jour la quantité de l'item
                i->setQuantity(quantity);
            }
            // on met exist à true pour indiquer que l'item est trouvé
            exist = true;
            break;
        }
    }
    // si l'item n'est pas trouvé on affiche un message d'erreur
    if (!exist)
    {
        cout << "Item not found in the inventory!" << endl;
        cout << "Add the item to the inventory first!" << endl;
    }
}

// méthode pour afficher les items de l'inventaire du vecteur itemsIngrediant
void Inventory::displayItems()
{
    // si le vecteur itemsIngrediant est vide on affiche un message
    if (itemsIngrediant.size() == 0)
    {
        cout << "No ingrediant in the inventory" << endl;
    }
    else
    {
        cout << "Inventory: " << endl;
        for (Ingrediant *i : itemsIngrediant)
        {
            // on affiche les items de l'inventaire, en utilisant la méthode display de la classe Item
            i->display();
        }
    }
}

// méthode pour ajouter un item à l'inventaire  en utilisant la méthode push_back du vecteur itemsIngrediant
void Inventory::setItemsIngerediant(Ingrediant *i)
{
    itemsIngrediant.push_back(i);
}

// getter pour retourner le vecteur itemsIngrediant de la classe Inventory
vector<Ingrediant *> Inventory::getItemsIngrediant()
{
    return itemsIngrediant;
}
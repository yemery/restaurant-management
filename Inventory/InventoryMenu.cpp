#include "Inventory.cpp"

void InventoryMenu(Inventory &i)
{
    // menu de gestion de l'inventaire (afficher les items, mettre à jour les items)

    int choice;
    bool exit = false;

    do
    {
        system("CLS");

        cout << "1. Display Inventory" << endl;
        cout << "2. Update Inventory" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        // on demande à l'utilisateur de choisir une option
        cin >> choice;

        switch (choice)
        {

        case 1:
            i.displayItems();
            break;
        case 2:
            i.updateItems();
            break;
        case 3:
            exit = true;
            break;
        default:
            return;
        }
        cout << "Do you want to continue in Inventory Menu ? yes (0) no (1): ";
        cin >> exit;
    } while (exit == false);
}
#include "Inventory.cpp"

void InventoryMenu(Inventory &i)
{
    int choice;
    bool exit = false;

    do
    {
        system("CLS");

        cout << "1. Display Inventory" << endl;
        cout << "2. Update Inventory" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
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
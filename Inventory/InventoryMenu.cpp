#include "Inventory.cpp"

void InventoryMenu(Menu &m,Inventory &i)
{
    int choice;
    bool exit = false;
    
    do
    {
        system("CLS");

        cout << "1. Add to Inventory" << endl;
        cout << "2. Display Inventory" << endl;
        cout << "3. Update Inventory" << endl;
       
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            i.addItems(m);
            break;
        case 2:
            i.displayItems();
            break;
        case 3:
            i.updateItems();
            break;
        // case 4:
        //     calculateSumById();
        //     break;
        // case 5:
        //     clientInventorysById();
        //     break;
        case 6:
            exit = true;
            break;
        default:
            return;
        }
        cout << "Do you want to continue? yes (0) no (1): ";
        cin >> exit;
    } while (exit == false);
}
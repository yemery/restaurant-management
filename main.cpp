#include "Client/ClientMenu.cpp"
#include "Reservation/ReservationMenu.cpp"
#include "Menu/MenuMenu.cpp"
#include "Order/OrderMenu.cpp"
#include "Inventory/InventoryMenu.cpp"
int main()
{
    int choice;
    bool exit = false;
    Menu m;
    Inventory i;
    do
    {
        system("CLS");

        cout << "1. Client Menu" << endl;
        cout << "2. Menu Menu" << endl;
        cout << "3. Reservation Menu" << endl;
        cout << "4. Order Menu" << endl;
        cout << "5. Inventory Menu" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ClientMenu();
            break;
        case 2:
            MenuMenu(m, i);
            break;
        case 3:
            ReservationMenu();
            break;
        case 4:
            OrderMenu(m);
            break;

        case 5:
            InventoryMenu(i);
            break;
        case 6:
            exit = true;
            break;
        default:
            return 0;
        }
    } while (exit == false);

    return 0;
}
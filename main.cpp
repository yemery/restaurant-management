#include "Client/ClientMenu.cpp"
#include "Reservation/ReservationMenu.cpp"
#include "Menu/MenuMenu.cpp"
#include "Order/OrderMenu.cpp"
#include "Inventory/InventoryMenu.cpp"

int main()
{
//  un menu principal pour gérer les différentes fonctionnalités du restaurant, 
//     chaque fonctionnalité est gérée par un menu spécifique
//      (client, menu, réservation, commande, inventaire)
    int choice;
    bool exit = false;

    //  les objets des classes Menu et Inventory pour gérer les menus et l'inventaire , 
    // on les a déclaré ici pour qu'ils soient accessibles dans tous les menus pour les gérer et
    //  les modifier sans avoir à les initialiser à chaque fois
    Menu m;
    Inventory i;
    do
    {
        // on efface l'écran en utilisant la commande system("CLS") pour effacer l'écran
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
            OrderMenu(m,i);
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
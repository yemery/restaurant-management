#include "Client/ClientMenu.cpp"
#include "Reservation/ReservationMenu.cpp"
#include "Menu/MenuMenu.cpp"

int main()
{
    int choice;
    bool exit = false;
    Menu m;
    
    do
    {
        system("CLS");

        cout << "1. Client Menu" << endl;
        cout << "2. Menu Menu" << endl;
        cout << "3. Reservation Menu" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ClientMenu();
            break;
        case 2:
            MenuMenu(m);
            break;
        case 3:
            ReservationMenu();
            break;

        case 4:
            exit = true;
            break;
        default:
            return 0;
        }
    } while (exit == false);

    return 0;
}
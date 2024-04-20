#include "Menu.cpp"
#include <stdlib.h>

void MenuMenu(Menu &m, Inventory& i)
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "1. Add items to the menu" << endl;
        cout << "2. Display the menu" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            m.addItems(i);
            break;
        case 2:
            m.display();
            break;
        case 3:
            exit = true;
            break;
        default:
            return ;
        }
        cout << "Do you want to continue in Menu Menu ?  yes (0) no (1): ";
        cin >> exit;
    } while (exit == false);
}

#include "Menu.cpp"
#include <stdlib.h>

void MenuMenu(Menu &m)
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
            m.addItems();
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
        cout << "Do you want to continue? yes (0) no (1): ";
        cin >> exit;
    } while (exit == false);
}

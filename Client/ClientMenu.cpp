#pragma once
#include "Client.cpp"
#include <stdlib.h>

void ClientMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "-------------- Client Management --------------" << endl;
        cout << "1. Add Client" << endl;
        cout << "2. Display Clients" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addClient();
            break;
        case 2:
            displayClients();
            break;
        case 3:
            exit = true;
            break;
        default:
            cout << "Invalid choice" << endl;
            return;
        }
        cout << "Do you want to continue in Client Menu ? yes (0) no (1):  ";
        cin >> exit;
    } while (exit == false);
}

#pragma once
#include "Client.cpp"
#include <stdlib.h>

void ClientMenu()
{
    // un menu pour gérer les clients (ajouter un client, afficher les clients)

    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "-------------- Client Management --------------" << endl;
        cout << "1. Add Client" << endl;
        cout << "2. Display Clients" << endl;
        cout << "3. Exit" << endl;
        // on demande à l'utilisateur de choisir une option
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
            // return pour sortir du menu client
            return;
        }
        // on demande à l'utilisateur s'il veut continuer dans le menu client
        cout << "Do you want to continue in Client Menu ? yes (0) no (1):  ";
        cin >> exit;
    } while (exit == false);
}

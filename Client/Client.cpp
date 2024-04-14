#pragma once
#include "Client.h"

int Client::idd = 0;
Client::Client() : firstName(""), lastName(""), phoneNumber(""), id(Client::idd++) {}
Client::Client(Client &c) : firstName(c.firstName), lastName(c.lastName), phoneNumber(c.phoneNumber), id(c.id) {}
Client::Client(string f, string l, string p) : firstName(f), lastName(l), phoneNumber(p),id(Client::idd++) {}
void Client::display()
{
    cout << "Client ID: " << id << endl;
    cout << "Client First Name: " << firstName << endl;
    cout << "Client Last Name: " << lastName << endl;
    cout << "Client Phone Number: " << phoneNumber << endl;

    // for (int i = 0; i < reservations.size(); i++)
    // {
    //     reservations[i]->display();
    // }
}

void displayClients()
{
    for (int i = 0; i < clients.size(); i++)
    {
        clients[i]->display();
    }
}

void addClient(){
    string firstName, lastName, phoneNumber;
    cout << "Enter the first name of the client: ";
    cin >> firstName;
    cout << "Enter the last name of the client: ";
    cin >> lastName;
    cout << "Enter the phone number of the client: ";
    cin >> phoneNumber;

    clients.push_back(new Client(firstName, lastName, phoneNumber));
    cout << "Client added successfully!" << endl;
}

int Client::getId()
{
    return id;
}
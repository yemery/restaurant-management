#pragma once
#include "Client.h"

// Initialisation de l'ID à 0 , on a un vecteurr de pointeurs de type Client pour stocker les clients, chaque client a un ID unique 
int Client::idd = 0;

// Différents Constructeurs (par default , paramétré et par copie)
Client::Client() : firstName(""), lastName(""), phoneNumber(""), id(Client::idd++) {}
Client::Client(Client &c) : firstName(c.firstName), lastName(c.lastName), phoneNumber(c.phoneNumber), id(c.id) {}
Client::Client(string f, string l, string p) : firstName(f), lastName(l), phoneNumber(p), id(Client::idd++) {}

//  une methode pour afficher les infromations du client
void Client::display()
{
    cout << "Client ID: " << id << endl;
    cout << "Client First Name: " << firstName << endl;
    cout << "Client Last Name: " << lastName << endl;
    cout << "Client Phone Number: " << phoneNumber << endl;
}

// une fonction pour afficher la liste des clients dans le vecteur clients en utilisant la methode display pour afficher un seul client et forrange pour itterater le vecteur
void displayClients()
{
    for (Client* c : clients)
    {
        c->display();
    }
}

// une fonction pour ajouter un client dans le vecteur clients
void addClient()
{
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

// une getter pour accéder à l'ID du client qui est privé
int Client::getId()
{
    return id;
}
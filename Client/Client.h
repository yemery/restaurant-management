#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "../utils.cpp"

class Client
{
    // pour utiliser une template dans le fichier utils.cpp on a utilisé friend pour qu'elle puisse accéder aux attributs privés de la classe
    template <class V, class I>
    friend optional<V> find(vector<V>, I);

private:
    int id;
    string firstName, lastName, phoneNumber;

public:
    static int idd;
    Client();
    Client(Client &);
    Client(string, string, string);
    int getId();  
    void display();
};
// vecteur dynamique de pointeurs de type Client pour stocker les clients
vector<Client *> clients;
#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "../Client/Client.h"
#include "../utils.cpp"

// classe reservation pour gérer les réservations des clients
class Reservation
{
    // pour utiliser une template dans le fichier utils.cpp on a utilisé friend pour qu'elle puisse accéder aux attributs privés de la classe
    // pour chercher une réservation par son id

    template <class V, class I>
    friend optional<V> find(vector<V>, I);

private:
    int id;
    string date,
        hour;
    int nbPeople,
        status = 1;
    // status est par défaut 1 pour en attente, 2 pour annulé et 3 pour confirmé
    Client *client;

public:
    static int idd;
    Reservation();
    Reservation(Client *, string, string, int, int);
    Reservation(Reservation &);
    void display();
    int getId();
    int getStatus();
    void setStatus(int);
    Client *getClient();
};

// vecteur dynamique de pointeurs de type Reservation pour stocker les réservations
vector<Reservation *> reservations;

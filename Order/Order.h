#pragma once
#include <iostream>
#include <vector>
#include "../Item/Item.cpp"
#include "../Menu/Menu.h"
#include "../Client/Client.cpp"
#include "../utils.cpp"
using namespace std;

// Classe Order qui contient un vecteur dynamique de pointeurs de type Item pour stocker les items de la commande
class Order
{
    // pour utiliser une template dans le fichier utils.cpp on a utilisé friend pour qu'elle puisse accéder aux attributs privés de la classe
    template <class V, class I>
    friend optional<V> find(vector<V>, I);

    // on a utilisé friend pour que la fonction SumPerOrder() puisse accéder aux attributs privés de la classe et calculer le total de chaque commande dans le vecteur orders
    friend void SumPerOrder();

private:
    vector<Item *> orderItems;
    Client *client;
    int id;

public:
    static int idd;
    Order();
    void display();
    void caculateSum();
    Client *getClient();
    vector<Item *> getOrderItems();
    void setClient(Client *c);
    void setOrderItems(Item &);
};

// vecteur dynamique de pointeurs de type Order pour stocker les commandes
vector<Order *> orders;

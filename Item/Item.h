#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "../utils.cpp"

// classe abstraite Item qui contient les attributs communs entre les plats et les boissons
// elle est utiliée pour éviter les conflits d'identifiants entre les plats et les boissons
class Item
{
    // pour utiliser une template dans le fichier utils.cpp on a utilisé friend pour qu'elle puisse accéder aux attributs privés de la classe
    template <class V, class I>
    friend optional<V> find(vector<V>, I);

protected:
    int id;
    string name, description;
    double price;

public:
    static int idd;
    double getPrice();
    Item();
    Item(string, string, double);
    Item(Item &);
    int getId();    
    virtual void display() = 0;
};
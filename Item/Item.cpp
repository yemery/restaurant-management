#pragma once
#include "Item.h"

// Identifiant de l'item
int Item::idd = 0;

// Constructeurs de la classe Item (par défaut, paramétré et par copie)
Item::Item() : name(""), description(""), price(0), id(Item::idd++){};
Item::Item(string n, string d, double p) : name(n), description(d), price(p), id(Item::idd++){};
Item::Item(Item &i) : name(i.name), description(i.description), price(i.price), id(Item::idd++){};

// getter pour obtenir le prix de l'item
double Item::getPrice()
{
    return price;
}

// getter pour obtenir l'ID de l'item
int Item::getId()
{
    return id;
}
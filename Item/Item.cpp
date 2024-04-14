#pragma once
#include "Item.h"

int Item::idd = 0;

Item::Item() : name(""), description(""), price(0), id(Item::idd++){};
Item::Item(string n, string d, double p) : name(n), description(d), price(p), id(Item::idd++){};
Item::Item(Item &i) : name(i.name), description(i.description), price(i.price), id(Item::idd++){};

double Item::getPrice()
{
    return price;
}   
int Item::getId()
{
    return id;
}
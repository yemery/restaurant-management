#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "../Client/Client.h"
#include "../utils.cpp"
class Reservation
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);

private:
    int id;
    string date, hour;
    int nbPeople, status = 1;
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
    Client* getClient();
    // ~Reservation();
};
vector<Reservation *> reservations;

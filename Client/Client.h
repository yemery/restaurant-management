#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "../utils.cpp"

class Client
{
    template <class V, class I>
    friend optional<V> find(vector<V>, I);

private:
    int id;
    string firstName, lastName, phoneNumber;
    // vector<Reservation *> reservations;

public:
    static int idd;
    Client();
    Client(Client &);
    Client(string, string, string);
    // ~Client();
    int getId();  
    void display();
};
vector<Client *> clients;
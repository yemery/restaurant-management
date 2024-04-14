// #pragma once
// #include <iostream>
// #include <vector>
// using namespace std;
// #include "utils.cpp"







// // we will add display items method by id for the menu

// class Reservation
// {
// private:
//     int id;
//     string date, hour;
//     int nbPeople, status = 1;
//     Client client;

// public:
//     static int idd;
//     Reservation();
//     Reservation(Client &, string, string, int, int);
//     Reservation(Reservation &);
//     void reserve();

//     void confirm();
//     void cancel();
//     void display();

//     // ~Reservation();
// };

// // anzido l client vector dialo bach n3rfou list d clients

// class Client
// {
//     template <class V, class I>
//     friend optional<V> find(vector<V>, I);

// private:
//     int id;
//     string firstName, lastName, phoneNumber;
//     // vector<Reservation *> reservations;

// public:
//     static int idd;
//     Client();
//     Client(Client &);
//     Client(string, string, string);
//     // ~Client();
//     void cancelReserve();
//     void display();
// };

// class Menu
// {
//     friend class Order;

// private:
//     // vector<Dish *> dishes;
//     // vector<Drink *> drinks;
//     vector<Item *> items;

// public:
//     // void addDish();
//     // void addDrink();
//     void addToMenu();
//     void display();
// };

// class Order
// {
// private:
//     // vector<Dish *> dishes_list;
//     // vector<Drink *> drinks_list;
//     vector<Item *> itemsList;

// public:
//     // void addDish(Menu &);
//     // void addDrink(Menu &);
//     void addItem(Menu &);
//     void caculateSum();
// };

// vector<Client *> clients;
// vector<Reservation *> reservations;
// vector<Order *> order;
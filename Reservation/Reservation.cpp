#include "Reservation.h"
int Reservation::idd = 0;
Reservation::Reservation() : date(""), hour(""), nbPeople(0), status(0), id(Reservation::idd++), client(){};
Reservation::Reservation(Client *c, string d, string h, int nb, int s) : date(d), hour(h), nbPeople(nb), status(s), id(Reservation::idd++), client(c) {}
Reservation::Reservation(Reservation &r) : date(r.date), hour(r.hour), nbPeople(r.nbPeople), status(r.status), client(r.client) {}

int Reservation::getStatus()
{
    return status;
}

void Reservation::setStatus(int i)
{
    status = i;
}
int Reservation::getId()
{
    return id;
}

//  1 for waiting 2 canceled 3 confirmed
void confirmReservation()
{
    cout << "Confirm a reservation: " << endl;
    cout << "Give ID of reservation: ";
    int id;
    cin >> id;
    auto findReservation = find(reservations, id);
    if (!findReservation.has_value())
    {
        cout << "Invalid reservation id" << endl;
    }
    else
    {
        for (Reservation *i : reservations)
        {
            if (i->getId() == id)
            {
                i->setStatus(3);
                cout << "Reservation confirmed!" << endl;
                break;
            }
        }
    }
}

void cancelReservation()
{
    cout << "Cancel a reservation: " << endl;
    cout << "Give ID of reservation: ";
    int id;
    cin >> id;
    auto findReservation = find(reservations, id);
    if (!findReservation.has_value())
    {
        cout << "Invalid reservation id" << endl;
    }
    else
    {
        for (Reservation *i : reservations)
        {
            if (i->getId() == id)
            {
                i->setStatus(2);
                cout << "Reservation canceled!" << endl;
                break;
            }
        }
    }
}


void Reservation::display()
{
    cout << "Reservation ID: " << id << endl;
    cout << "Reservation Date: " << date << endl;
    cout << "Reservation Hour: " << hour << endl;
    cout << "Number of people: " << nbPeople << endl;
    cout << "Reservation Status: " ;
    if (status == 1)
    {
        cout << "Waiting" << endl;
    }
    else if (status == 2)
    {
        cout << "Canceled" << endl;
    }
    else 
    {
        cout << "Confirmed" << endl;
    }
   
    cout << "Client Information:" << endl;
    client->display();
}

void reserve()
{
    cout << "Reserve a table: " << endl;
    cout << "Give ID of client: ";
    int id;
    cin >> id;

    auto client = find(clients, id);
    if (!client.has_value())
    {
        cout << "Invalid client id" << endl;
    }
    else
    {
        string date, hour;
        int nbPeople;
        cout << "Enter the date of the reservation: ";
        cin >> date;
        cout << "Enter the hour of the reservation: ";
        cin >> hour;
        cout << "Enter the number of people: ";
        cin >> nbPeople;
        // cout << "Enter the status of the reservation: ";
        // cin >> status;
        // Client c = *client.value();
        cout << "Reservation is by default pending!" << endl;
        // anzido option to add a client if not found in the list
        reservations.push_back(new Reservation(client.value(), date, hour, nbPeople, 1));
        cout << "Reservation added successfully!" << endl;
    }
}

void displayReservations()
{
    for (auto r : reservations)
    {
        r->display();
    }
}
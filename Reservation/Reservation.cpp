#include "Reservation.h"

// idd est un attribut static pour incrémenter l'ID de la réservation
int Reservation::idd = 0;

// constructeurs de la classe Reservation (par défaut, paramétré et par copie)
Reservation::Reservation() : date(""), hour(""), nbPeople(0), status(0), id(Reservation::idd++), client(){};
Reservation::Reservation(Client *c, string d, string h, int nb, int s) : date(d), hour(h), nbPeople(nb), status(s), id(Reservation::idd++), client(c) {}
Reservation::Reservation(Reservation &r) : date(r.date), hour(r.hour), nbPeople(r.nbPeople), status(r.status), client(r.client) {}

// getters et setters pour les attributs de la classe Reservation
int Reservation::getStatus()
{
    return status;
}

// setter pour modifier le status de la réservation
void Reservation::setStatus(int i)
{
    status = i;
}

// getter pour obtenir l'ID de la réservation
int Reservation::getId()
{
    return id;
}

// getter pour obtenir le client de la réservation
Client *Reservation::getClient()
{
    return client;
}

// confirmReservation est une fonction pour confirmer une réservation par son ID en changeant le status de la réservation à 3
void confirmReservation()
{
    cout << "Confirm a reservation: " << endl;
    cout << "Give ID of reservation: ";
    int id;
    cin >> id;
    // on cherche la réservation par son ID
    auto findReservation = find(reservations, id);
    // si la réservation n'est pas trouvée on affiche un message d'erreur
    if (!findReservation.has_value())
    {
        cout << "Invalid reservation id" << endl;
    }
    // si la réservation est trouvée on change le status de la réservation à 3 pour la confirmer
    else
    {
        for (Reservation *i : reservations)
        {
            // on cherche la réservation par son ID dans le vecteur reservations
            if (i->getId() == id)
            {
                // on change le status de la réservation à 3 pour la confirmer on utilise la méthode setStatus de la classe Reservation
                i->setStatus(3);
                cout << "Reservation confirmed!" << endl;
                break;
            }
        }
    }
}

// cancelReservation est une fonction pour annuler une réservation par son ID en changeant le status de la réservation à 2
void cancelReservation()
{
    cout << "Cancel a reservation: " << endl;
    cout << "Give ID of reservation: ";
    int id;
    cin >> id;
    // on cherche la réservation par son ID
    auto findReservation = find(reservations, id);
    // si la réservation n'est pas trouvée on affiche un message d'erreur
    if (!findReservation.has_value())
    {
        cout << "Invalid reservation id" << endl;
    }
    else
    {
        // si la réservation est trouvée on change le status de la réservation à 2 pour l'annuler
        for (Reservation *i : reservations)
        {
            if (i->getId() == id)
            {
                // on change le status de la réservation à 2 pour l'annuler on utilise la méthode setStatus de la classe Reservation
                i->setStatus(2);
                cout << "Reservation canceled!" << endl;
                break;
            }
        }
    }
}

// display est une méthode pour afficher les informations de la réservation
void Reservation::display()
{
    cout << "Reservation ID: " << id << endl;
    cout << "Reservation Date: " << date << endl;
    cout << "Reservation Hour: " << hour << endl;
    cout << "Number of people: " << nbPeople << endl;
    cout << "Reservation Status: ";
    // on affiche le status de la réservation selon sa valeur
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
    // on affiche les informations du client de la réservation en utilisant la méthode display de la classe Client
    client->display();
}

// reserve est une fonction pour réserver une table pour un client en ajoutant une réservation au vecteur reservations
void reserve()
{
    cout << "Reserve a table: " << endl;
    cout << "Give ID of client: ";
    int id;
    cin >> id;
    // on cherche le client par son ID dans le vecteur clients
    auto client = find(clients, id);
    // si le client n'est pas trouvé on affiche un message d'erreur
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
        cout << "Reservation is by default pending!" << endl;
        // on ajoute une réservation au vecteur reservations
        reservations.push_back(new Reservation(client.value(), date, hour, nbPeople, 1));
        cout << "Reservation added successfully!" << endl;
    }
}

// displayReservations est une fonction pour afficher toutes les réservations en utilisant la méthode display de la classe Reservation
void displayReservations()
{
    for (Reservation *r : reservations)
    {
        // on affiche les réservations en utilisant la méthode display de la classe Reservation
        r->display();
    }
}

// clientReservationById est une fonction pour afficher les réservations d'un client par son ID
void clientReservationById()
{
    cout << "Enter the client id to display the reservations:";
    int id;
    cin >> id;
    // on cherche le client par son ID dans le vecteur clients
    auto foundClient = find(clients, id);
    // si le client n'est pas trouvé on affiche un message d'erreur
    if (!foundClient.has_value())
    {
        cout << "Invalid client id" << endl;
    }
    else

    {
        // si le client est trouvé on affiche les réservations du client en utilisant la méthode display de la classe Reservation
        for (Reservation *i : reservations)
        {
            // on cherche les réservations du client par son ID dans le vecteur reservations
            if (i->getClient()->getId() == id)
            {
                // on affiche les réservations du client en utilisant la méthode display de la classe Reservation
                i->display();
            }
        }
    }
}
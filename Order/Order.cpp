#include "Order.h"

// Inialisation de l'attribut statique idd de la classe Order à 0
int Order::idd = 0;

// Constructeur de la classe Order
Order::Order() : id(Order::idd++){};

// fonction pour ajouter des items à la commande
void addItemsOrder(Menu &m, Inventory &inv)
// on passe en paramètre un objet de type Menu pour pouvoir accéder aux items du menu sans perdre la cohérence des données et éviter plusieurs instances de la classe Menu qui est declarée dans le main
{
    cout << "-----------Add items to the order: ------------------" << endl;
    int id, idClient;

    bool exist = false;

    // instanciation dynamique d'un objet de type Order
    Order *o = new Order();
    cout << "Enter ID of the client: ";
    cin >> idClient;

    // on vérifie si le client existe dans le vecteur clients pour l'ajouter à la commande
    bool check = false;
    for (Client *i : clients)
    {
        if (i->getId() == idClient)
        {
            // affectation du client à la commande
            o->setClient(i);
            cout << "Client added to the order" << endl;
            // s'il existe on sort de la boucle et on change la valeur de la variable check à true
            check = true;
            break;
        }
    }
    // si le client n'existe pas on affiche un message d'erreur et on sort de l'ajout des items à la commande vers le menu client
    if (!check)
    {
        cout << "Client not found" << endl;
        return;
    }

    // boucle pour ajouter des items à la commande
    do
    {
        cout << "Enter the id of the item you want to add:";
        cin >> id;
        // on vérifie si l'item existe dans le menu pour l'ajouter à la commande

        for (Item *i : m.getMenuItems())
        {
            if (i->getId() == id)
            {
                // check pour vérifier si l'item est un plat ou une boisson dans l'invetaire
                for (Ingrediant *ing : inv.getItemsIngrediant())
                {
                    if (ing->getItemId() == id)
                    {
                        // on vérifie si la quantité de l'item est égale à 0 pour afficher un message d'erreur
                        if (ing->getQuantity() <= 0)
                        {
                            cout << "Item not available" << endl;
                            // continue;
                        }
                        else
                        {
                            // si la quantité de l'item est supérieure à 0 on l'ajoute à la commande
                            // on utilise la méthode setOrderItems() de la classe Order pour ajouter l'item à la commande
                            o->setOrderItems(*i);
                            // on utilise la méthode setQuantity() de la classe Ingrediant pour soustraire la quantité de l'item de l'inventaire
                            ing->setQuantity(-1);
                            break;
                        }
                    }
                }

                break;
            }
            else
            {
                cout << "Item not found" << endl;
            }
        }
        // on demande à l'utilisateur s'il veut ajouter plus d'items à la commande

        cout << "Do you want to add more items? yes (0) no (1): ";
        cin >> exist;
        // la variable exist pour vérifier si l'utilisateur veut ajouter plus d'items à la même commande
    } while (exist == false);

    // on vérifie si la commande contient des items avant de l'ajouter au vecteur orders
    if (o->getOrderItems().size() != 0)
    {
        // ajout de la commande au vecteur orders
        orders.push_back(o);
        cout << "Order added successfully" << endl;
    }
    else
    {
        // si la commande ne contient pas d'items on affiche un message d'erreur
        cout << "No items added to the order, order cancelled" << endl;
    }
}

// méthode pour afficher une commande avec les items et les informations du client
void Order::display()
{

    if (orderItems.size() == 0)
    {
        cout << "No orders registered on the system" << endl;
    }
    else
    {
        cout << "Order ID: " << id << endl;
        for (Item *i : orderItems)
        {
            // on affiche les items de la commande  en utilisant virtual display() et les pointeurs pour afficher les informations de l'item qui dépend du type de l'item (Dish ou Drink)
            i->display();
        }
        cout << "Client Information:" << endl;
        // on affiche les informations du client en utilisant la méthode display() de la classe Client
        client->display();
    }
}

// fonction pour afficher les commandes du vecteur orders
void displayOrders()
{
    cout << "-----------Display the order: ------------------" << endl;
    for (Order *i : orders)
    {
        // on affiche les commandes en utilisant la méthode display() de la classe Order
        i->display();
    }
}

// méthode pour calculer le total de la commande
void Order::caculateSum()
{
    double sum = 0;
    // on utilise la méthode getPrice() de la classe Item pour accéder au prix de chaque item de la commande
    for (auto &i : orderItems)
    {
        // on incrémente la somme par le prix de chaque item
        sum += i->getPrice();
    }
    // on affiche la somme totale de la commande
    cout << "The total sum of the order is: " << sum << endl;
}

// fonction pour l'affichage de chaque commande dans le vecteur orders avec son total
void SumPerOrder()
{
    for (auto &i : orders)
    {
        // on utilise les méthodes display() et caculateSum() de la classe Order pour afficher et calculer le total de chaque commande
        i->display();
        i->caculateSum();
    }
}

// getter pour accéder au client de la commande
Client *Order::getClient()
{
    return client;
}

// getter pour accéder aux items de la commande
vector<Item *> Order::getOrderItems()
{
    return orderItems;
}

// setter pour modifier le client de la commande
void Order::setClient(Client *c)
{
    client = c;
}

// setter pour ajouter des items à la commande
void Order::setOrderItems(Item &i)
{
    orderItems.push_back(&i);
}

// fonction pour afficher le total d'une commande en demandant son ID
void calculateSumById()
{
    int id;

    cout << "Enter the id of the order you want to calculate the sum: ";
    cin >> id;
    // on utilise la fonction find() pour trouver la commande dans le vecteur orders
    auto foundOrder = find(orders, id);
    // si la commande existe on utilise la méthode caculateSum() de la classe Order pour calculer le total de la commande, sinon on affiche un message d'erreur
    if (foundOrder.has_value())
    {
        foundOrder.value()->caculateSum();
    }
    else
    {
        cout << "Order not found" << endl;
    }
}

// fonction pour afficher les commandes d'un client en demandant son ID
void clientOrdersById()
{
    int id;

    cout << "Enter the client id to display the Orders:";
    cin >> id;

    // on utilise la fonction find() pour trouver le client dans le vecteur clients
    auto foundClient = find(clients, id);
    // si le client existe on affiche les commandes du client, sinon on affiche un message d'erreur
    if (foundClient.has_value())
    {
        for (Order *i : orders)
        {
            // on vérifie si le client de la commande est le client qu'on cherche , on  utilise les methodes getId() de la classe Client et getClient() de la classe Order pour accéder à l'ID du client et au client de la commande
            if (i->getClient()->getId() == id)
            {
                i->display();
            }
        }
    }
    else
    {
        cout << "Client not found" << endl;
    }
}
#include "Order.cpp"

void OrderMenu(Menu &m)
{
    int choice;
    bool exit = false;
    // Order o;
    do
    {
        system("CLS");

        cout << "1. Add Order" << endl;
        cout << "2. Display Orders" << endl;
        cout << "3. Sum per Order" << endl;
        cout << "4. Calculate Sum by Order ID" << endl;
        cout << "5. Reservation of a client" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addItemsOrder(m);
            break;
        case 2:
            displayOrders();
            break;
        case 3:
            SumPerOrder();
            break;
        case 4:
            calculateSumById();
            break;
        case 5:
            clientReservationsById();
            break;
        case 6:
            exit = true;
            break;
        default:
            return;
        }
        cout << "Do you want to continue? yes (0) no (1): ";
        cin >> exit;
    } while (exit == false);
}
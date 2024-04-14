#include "Reservation.cpp"
#include <stdlib.h>

void ReservationMenu()
{
    int choice;
    bool exit = false;
    do
    {
        system("CLS");

        cout << "-------------- Reservation Management --------------" << endl;
        cout << "1. Reserve a table" << endl;
        cout << "2. Display Reservations" << endl;
        cout << "3. Confirm Reservation" << endl;
        cout << "4. Cancel Reservation" << endl;
        cout << "5. Get reservation by ID" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            reserve();
            break;
        case 2:
            displayReservations();
            break;
        case 3:
            confirmReservation();
            break;
        case 4:
            cancelReservation();
            break;
        case 5:
            clientReservationById();
            break;
        case 6:
            exit = true;
            break;
        default:
            cout << "Invalid choice" << endl;
            return;
        }
        cout << "Do you want to continue? yes (0) no (1): ";
        cin >> exit;
    } while (exit == false);
}
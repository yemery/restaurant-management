#include "method.cpp"

int main() {
    Dish d1("Dish1", "Dish1 description", 10.0);
    Drink dr1("Drink1", "Drink1 description", 5);
    d1.display();
    dr1.display();
    Menu m;
    // m.addToMenu();
    // m.display();
    Client c("Client1", "Client1 address", "Client1 phone");
    c.reserve();

    c.display();
    return 0;
}
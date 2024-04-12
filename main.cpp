#include "method.cpp"

int main() {
    Dish d1("Dish1", "Dish1 description", 10.0);
    Dish d2("Dish1", "Dish1 description", 10.0);
    Drink dr1("Drink1", "Drink1 description", 5);
    Drink dr2("Drink1", "Drink1 description", 5);
    d1.display();
    d2.display();
    dr1.display();
    dr2.display();
    Menu m;
    m.addToMenu();
    m.addToMenu();
    m.display();
    // Client c("Client1", "Client1 address", "Client1 phone");
    // // c.reserve();

    // c.display();

    // Order o;
    // o.addDish(m);
    return 0;
}
#include "Order.h"
#include "Menus.h"

int main() {
    // Create toppings
    Topping* pepperoni = new Topping("Pepperoni", 20.00);
    ToppingGroup* pepperoniPizza = new ToppingGroup("Pepperoni Pizza", 30.00); // Dough + Sauce + Cheese
    pepperoniPizza->add(pepperoni);

    Topping* mushrooms = new Topping("Mushrooms", 12.00);
    Topping* peppers = new Topping("Green Peppers", 10.00);
    Topping* onions = new Topping("Onions", 8.00);
    ToppingGroup* vegetarian = new ToppingGroup("Vegetarian", 30.00);
    vegetarian->add(mushrooms);
    vegetarian->add(peppers);
    vegetarian->add(onions);
    vegetarian->remove(onions); // Testing remove

    // Create pizzas
    BasePizza* basePepperoni = new BasePizza(pepperoniPizza);
    Pizza* extraCheesePepperoni = new ExtraCheese(basePepperoni);
    Pizza* stuffedCrustPepperoni = new StuffedCrust(extraCheesePepperoni);
    stuffedCrustPepperoni->printPizza();

    BasePizza* vegetarianPizza = new BasePizza(vegetarian);
    vegetarianPizza->printPizza();

    // Create order
    Customer* customer = new Customer("John", true);
    Order* order = new Order(customer);
    order->addPizza(stuffedCrustPepperoni);
    std::cout << "Order total: " << order->calculateTotal() << " ZAR" << std::endl; // (30 + 20 + 12 + 20) * 0.85 = 69.7 ZAR
    std::cout << "Order state: " << order->getStateName() << std::endl;
    // Process order
    order->cancelOrder();
    order->setState(new PendingState()); // Reset state to Pending for further testing
    order->processOrder(); // Pending -> Preparing
    order->cancelOrder(); // Preparing -> Pending
    order->processOrder(); // Pending -> Preparing
    order->processOrder(); // Preparing -> Ready
    order->cancelOrder();
    order->processOrder(); // Pending -> Preparing
    order->processOrder(); // Preparing -> Ready
    order->processOrder(); // Ready -> Delivered
    order->cancelOrder(); // Error: Cannot cancel a delivered order
    order->processOrder(); // Error: Cannot process a delivered order
    order->getStateName();

    // Menu notifications
    Menus* menu = new PizzaMenu();
    menu->addObserver(customer);
    //menu->addPizza(basePepperoni);
    Customer* customer1 = new Customer("Sam", false);
    delete order;
    order = new Order(customer1);
    order->addPizza(menu->buyPizza(1));
    order->addPizza(menu->buyPizza(0));
    order->calculateTotal();
    order->addPizza(menu->buyPizza(0));
    order->addPizza(menu->buyPizza(3));
    order->addPizza(menu->buyPizza(1));
    order->addPizza(vegetarianPizza);
    std::cout << "Order total after adding pizza from menu: " << order->calculateTotal() << " ZAR" << std::endl;
    std::cout << "Total pizzas in order: " << order->getPizzaCount() << std::endl;

    menu->addObserver(customer1);
    menu->notifyObservers("New pizza added to the menu: BBQ Chicken");
    menu->removeObserver(customer);
    Pizza* bbqChickenPizza = new StuffedCrust (new ExtraCheese(new BasePizza(new ToppingGroup("BBQ Chicken", 50.00))));
    Pizza* copy = bbqChickenPizza->replicate();
    copy->printPizza();
    delete copy;
    menu->addPizza(bbqChickenPizza);
    menu->removePizza(bbqChickenPizza);
    delete menu;

    menu = new SpecialsMenu();
    Observer* observer = new Website();
    menu->addObserver(observer);
    menu->addObserver(customer1);
    menu->notifyObservers("New special pizza added: Hawaiian");
    order->addPizza(menu->buyPizza(0));
    order->addPizza(menu->buyPizza(5));
    // Clean up
    delete order;
    delete customer;
    delete customer1;
    delete observer;
    delete menu;

    return 0;
}
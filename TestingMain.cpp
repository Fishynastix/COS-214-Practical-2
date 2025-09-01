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

    // Create pizzas
    BasePizza* basePepperoni = new BasePizza(pepperoniPizza);
    Pizza* extraCheesePepperoni = new ExtraCheese(basePepperoni);
    Pizza* stuffedCrustPepperoni = new StuffedCrust(extraCheesePepperoni);

    // Create order
    Customer* customer = new Customer("John", true);
    Order* order = new Order(customer);
    order->addPizza(stuffedCrustPepperoni);
    order->setDiscountStrategy(new FamilyDiscount());
    std::cout << "Order total: " << order->calculateTotal() << " ZAR" << std::endl; // (30 + 20 + 12 + 20) * 0.85 = 69.7 ZAR
    std::cout << "Order state: " << order->getStateName() << std::endl;
    // Process order
    order->processOrder(); // Pending -> Preparing
    order->processOrder(); // Preparing -> Ready
    order->processOrder(); // Ready -> Delivered

    // Menu notifications
    PizzaMenu* menu = new PizzaMenu();
    menu->addObserver(customer);
    menu->addPizza(basePepperoni);

    // Clean up
    delete order;
    delete customer;
    delete menu;

    return 0;
}
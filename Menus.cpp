#include "Menus.h"

Menus::~Menus() {
	for (Pizza* pizza : pizzas) delete pizza;
	// Observers are not deleted as they may be shared
}

void Menus::addObserver(Observer* observer) {
    observers.push_back(observer);
}

void Menus::removeObserver(Observer* observer) {
	for (auto it = observers.begin(); it != observers.end(); ++it) {
		if (*it == observer) {
			observers.erase(it);
			break;
		}
	}
}

//we cannot add pizzas which will also be added to order here and vica versa
void Menus::addPizza(Pizza* pizza) {
	pizzas.push_back(pizza);
	notifyObservers("Added pizza: " + pizza->getName());
}

void Menus::removePizza(Pizza* pizza) {
	for (auto it = pizzas.begin(); it != pizzas.end(); ++it) {
		if (*it == pizza) {
			pizzas.erase(it);
			notifyObservers("Removed pizza: " + pizza->getName());
			break;
		}
	}
}

SpecialsMenu::SpecialsMenu() {
	// Initialize special pizzas
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
	pepperoniPizza->add(new Topping("Beef Sausage", 25.00));
	pepperoniPizza->add(new Topping("salami", 22.00));
	vegetarian->add(new Topping("Feta Cheese", 18.00));
	vegetarian->add(new Topping("Olives", 15.00));
    // Create pizzas
    BasePizza* meatLovers = new BasePizza(pepperoniPizza);
	BasePizza* vegetarianDeluxe = new BasePizza(vegetarian);
    pizzas.push_back(meatLovers);
    pizzas.push_back(vegetarianDeluxe);
}

void SpecialsMenu::notifyObservers(std::string message) {
    for (Observer* observer : observers) {
        observer->update("SpecialsMenu: " + message);
    }
}

Pizza* SpecialsMenu::buyPizza(int menuIndex) {
    if (menuIndex >= 0 && menuIndex < pizzas.size()) {
        Pizza* pizza = pizzas[menuIndex]->replicate(); //creates new pizza
        return pizza;
    }
    return nullptr;
}

PizzaMenu::PizzaMenu() {
	// Initialize regular pizzas
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
	BasePizza* baseVegetarian = new BasePizza(vegetarian);
    pizzas.push_back(basePepperoni);
    pizzas.push_back(baseVegetarian);
}

void PizzaMenu::notifyObservers(std::string message) {
    for (Observer* observer : observers) {
        observer->update("PizzaMenu: " + message);
    }
}

Pizza* PizzaMenu::buyPizza(int menuIndex) {
    if (menuIndex >= 0 && menuIndex < pizzas.size()) {
        Pizza* pizza = pizzas[menuIndex]->replicate(); //creates new pizza
        return pizza;
    }
    return nullptr;
}

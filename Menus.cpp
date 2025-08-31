#include "Menus.h"

~Menus() {
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

void SpecialsMenu::notifyObservers(std::string message) {
    for (Observer* observer : observers) {
        observer->update("SpecialsMenu: " + message);
    }
}

void PizzaMenu::notifyObservers(std::string message) {
    for (Observer* observer : observers) {
        observer->update("PizzaMenu: " + message);
    }
}

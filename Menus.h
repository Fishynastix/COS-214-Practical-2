#ifndef MENUS_H
#define MENUS_H

#include "Observer.h"
#include "Pizza.h"

class Menus {

private:
	Observer* observers;
	Pizza* pizzas;

public:
	void addObserver(Observer observer);

	void removeObserver(Observer observer);

	void addPizza(Pizza pizza);

	void removePizza(Pizza pizza);

	void notifyObservers(std::string message);
};

#endif

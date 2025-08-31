#ifndef MENUS_H
#define MENUS_H

#include "Observer.h"
#include "Pizza.h"
#include <vector>

class Menus {

private:
	std::vector<Observer*> observers;
	std::vector<Pizza*> pizzas;
public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void addPizza(Pizza* pizza);
	void removePizza(Pizza* pizza);
	virtual void notifyObservers(std::string message) = 0;
};

class SpecialsMenu : public Menus {
public:
	void notifyObservers(std::string message) override;
};

class PizzaMenu : public Menus {
public:
	void notifyObservers(std::string message) override;
};

#endif

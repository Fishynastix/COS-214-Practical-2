#ifndef MENUS_H
#define MENUS_H

#include "Observer.h"
#include "Pizza.h"
#include <vector>

class Menus {

protected:
	std::vector<Observer*> observers;
	std::vector<Pizza*> pizzas;
public:
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	void addPizza(Pizza* pizza);
	void removePizza(Pizza* pizza);
	virtual void notifyObservers(std::string message) = 0;
	virtual Pizza* buyPizza(int menuIndex) = 0; //factory method to create pizzas where the order will get pizzas
	virtual ~Menus();
};

class SpecialsMenu : public Menus {
public:
	SpecialsMenu();
	void notifyObservers(std::string message) override;
	Pizza* buyPizza(int menuIndex) override;
};

class PizzaMenu : public Menus {
public:
	PizzaMenu();
	void notifyObservers(std::string message) override;
	Pizza* buyPizza(int menuIndex) override;
};

#endif

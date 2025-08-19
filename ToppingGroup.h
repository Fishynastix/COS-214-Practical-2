#ifndef TOPPINGGROUP_H
#define TOPPINGGROUP_H

#include <string>
#include "PizzaComponent.h"

class ToppingGroup {

private:
	double price;
	std::string name;
	PizzaComponent* toppings;

public:
	std::string getName();

	double getPrice();

	void add(PizzaComponent component);

	void remove(PizzaComponent component);

	ToppingGroup(std::string name);
};

#endif

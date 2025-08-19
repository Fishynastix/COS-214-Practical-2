#ifndef BASEPIZZA_H
#define BASEPIZZA_H

#include "PizzaComponent.h"

class BasePizza {

private:
	PizzaComponent toppings;

public:
	double getPrice();

	std::string getName();

	void printPizza();

	BasePizza(PizzaComponent toppings);
};

#endif

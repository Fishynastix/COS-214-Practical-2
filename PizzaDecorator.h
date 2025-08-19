#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include "Pizza.h"
#include <string>

class PizzaDecorator {

private:
	Pizza pizza;

public:
	double getPrice();

	std::string getName();

	void printPizza();
};

#endif

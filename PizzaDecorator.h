#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

class PizzaDecorator {

private:
	Pizza pizza;

public:
	double getPrice();

	string getName();

	void printPizza();
};

#endif

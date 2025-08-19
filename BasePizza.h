#ifndef BASEPIZZA_H
#define BASEPIZZA_H

class BasePizza {

private:
	PizzaComponent toppings;

public:
	double getPrice();

	string getName();

	void printPizza();

	BasePizza(PizzaComponent toppings);
};

#endif

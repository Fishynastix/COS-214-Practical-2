#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>

class PizzaComponent {

private:
	double price;
	std::string name;

public:
	std::string getName();
	double getPrice();
};

#endif

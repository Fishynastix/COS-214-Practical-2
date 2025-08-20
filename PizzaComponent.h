#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>

class PizzaComponent {

private:
	double price;
	std::string name;

public:
	PizzaComponent(std::string name, double price) : name(name), price(price) {}
	virtual std::string getName();
	virtual double getPrice();
};

class Topping : public PizzaComponent {
private:
	double price;
	std::string name;

public:
	std::string getName();
	double getPrice();
	Topping(std::string name, double price);
};

class ToppingGroup : public PizzaComponent {
private:
	double price;
	std::string name;
	PizzaComponent* toppings;

public:
	void add(PizzaComponent component);

	void remove(PizzaComponent component);

	ToppingGroup(std::string name, double price);
};


#endif

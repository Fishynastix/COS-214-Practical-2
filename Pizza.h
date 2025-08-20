#ifndef PIZZA_H
#define PIZZA_H

#include <string>

#include "PizzaComponent.h"

class Pizza 
{
public:
	virtual double getPrice() = 0;
	virtual std::string getName() = 0;
	void printPizza();
};

class BasePizza : public Pizza 
{
private:
	PizzaComponent* toppings;
public:
	double getPrice() override;
	std::string getName() override;
	BasePizza(PizzaComponent* toppings);
};

class PizzaDecorator : public Pizza 
{
private:
	Pizza* pizza;
public:
	virtual double getPrice() = 0;
	virtual std::string getName() = 0;
	void printPizza();
	PizzaDecorator(Pizza* pizza = nullptr) : pizza(pizza) {}
};

class ExtraCheese : public PizzaDecorator
{
public:
	double getPrice() override;
	std::string getName() override;
	ExtraCheese(Pizza* pizza);
};

class StuffedCrust : public PizzaDecorator
{
public:
	double getPrice() override;
	std::string getName() override;
	StuffedCrust(Pizza* pizza);
};

#endif

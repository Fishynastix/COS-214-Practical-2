#ifndef PIZZA_H
#define PIZZA_H

#include "PizzaComponent.h"
#include <iostream>

class Pizza 
{
public:
	virtual double getPrice() = 0;
	virtual std::string getName() = 0;
	virtual Pizza* replicate() = 0;
	virtual void printPizza();
	virtual ~Pizza() {}
};

class BasePizza : public Pizza 
{
private:
	PizzaComponent* toppings;
public:
	double getPrice() override;
	std::string getName() override;
	void printPizza() override;
	Pizza* replicate() override;
	BasePizza(PizzaComponent* toppings);
	virtual ~BasePizza() {
		if (toppings != nullptr)
		{
			delete toppings;
		}
	}
};

class PizzaDecorator : public Pizza 
{
private:
	Pizza* pizza;
public:
	virtual double getPrice() = 0;
	virtual std::string getName() = 0;
	Pizza* getPizza() const { return pizza; }
	void printPizza() override;
	PizzaDecorator(Pizza* pizza = nullptr) : pizza(pizza) {}
	virtual ~PizzaDecorator() {
		if (pizza != nullptr)
		{
			delete pizza;
		}
	}
};

class ExtraCheese : public PizzaDecorator
{
public:
	double getPrice() override;
	std::string getName() override;
	Pizza* replicate() override;
	ExtraCheese(Pizza* pizza);
};

class StuffedCrust : public PizzaDecorator
{
public:
	double getPrice() override;
	std::string getName() override;
	Pizza* replicate() override;
	StuffedCrust(Pizza* pizza);
};

#endif

#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H

#include <string>
#include <vector>

class PizzaComponent {

private:
	double price;
	std::string name;
public:
	PizzaComponent(std::string name, double price) : name(name), price(price) {}
	virtual std::string getName();
	virtual double getPrice();
	virtual PizzaComponent* replicate();
};

class Topping : public PizzaComponent {
private:
	double price;
	std::string name;
public:
	std::string getName() override;
	double getPrice() override;
	PizzaComponent* replicate() override;
	Topping(std::string name, double price);
};

class ToppingGroup : public PizzaComponent {
private:
	double price;
	std::string name;
	std::vector<PizzaComponent*> toppings;
public:
	void add(PizzaComponent* component);
	void remove(PizzaComponent* component);
	std::string getName() override;
	double getPrice() override;
	PizzaComponent* replicate() override;
	ToppingGroup(std::string name, double price);
	~ToppingGroup();
};


#endif

#ifndef TOPPINGGROUP_H
#define TOPPINGGROUP_H

class ToppingGroup {

private:
	double price;
	string name;
	PizzaComponent* toppings;

public:
	string getName();

	double getPrice();

	void add(PizzaComponent component);

	void remove(PizzaComponent component);

	ToppingGroup(string name);
};

#endif

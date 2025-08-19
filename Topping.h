#ifndef TOPPING_H
#define TOPPING_H

class Topping {

private:
	double price;
	string name;

public:
	string getName();

	double getPrice();

	Topping(string name, double price);
};

#endif

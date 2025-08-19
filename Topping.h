#ifndef TOPPING_H
#define TOPPING_H

#include <string>

class Topping {

private:
	double price;
	std::string name;

public:
	std::string getName();

	double getPrice();

	Topping(std::string name, double price);
};

#endif

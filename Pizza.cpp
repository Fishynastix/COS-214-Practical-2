#include "Pizza.h"

void Pizza::printPizza() {
	std::cout << this->getName() << ": " << this->getPrice() << std::endl;
}

void BasePizza::printPizza() {
	std::cout << this->getName() << ": " << this->getPrice() << std::endl;
}

double BasePizza::getPrice() {
	return toppings->getPrice();
}

std::string BasePizza::getName() {
	return toppings->getName();
}

BasePizza::BasePizza(PizzaComponent* toppings) : toppings(toppings) {
}

void PizzaDecorator::printPizza() {
	std::cout << this->getName() << ": " << this->getPrice() << std::endl;
	if (pizza != nullptr)
	{
		pizza->printPizza();
	}	
}

double ExtraCheese::getPrice() {
	return 12.00;
}

std::string ExtraCheese::getName() {
	return "Extra Cheese";
}

ExtraCheese::ExtraCheese(Pizza* pizza) : PizzaDecorator(pizza) {
}

double StuffedCrust::getPrice() {
	return 20.00;
}

std::string StuffedCrust::getName() {
	return "Stuffed Crust";
}

StuffedCrust::StuffedCrust(Pizza* pizza) : PizzaDecorator(pizza) {
}
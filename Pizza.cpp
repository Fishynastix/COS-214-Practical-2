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

Pizza* BasePizza::replicate() {
	if (toppings != nullptr)
	{
		return new BasePizza(toppings->replicate());
	}
	return new BasePizza(nullptr);
}

void PizzaDecorator::printPizza() {
	if (this->getName() == "Extra Cheese")
	{
		std::cout << this->getName() << ": " << this->getPrice() << std::endl;
	}
	if (pizza != nullptr)
	{
		pizza->printPizza();
	}	
	if (this->getName() == "Stuffed Crust")
	{
		std::cout << this->getName() << ": " << this->getPrice() << std::endl;
	}
}

double ExtraCheese::getPrice() {
	return 12.00 + getPizza()->getPrice();
}

std::string ExtraCheese::getName() {
	return "Extra Cheese";
}

ExtraCheese::ExtraCheese(Pizza* pizza) : PizzaDecorator(pizza) {
}

Pizza* ExtraCheese::replicate() {
	return new ExtraCheese(this->getPizza()->replicate());
}

double StuffedCrust::getPrice() {
	return 20.00 + getPizza()->getPrice();
}

std::string StuffedCrust::getName() {
	return "Stuffed Crust";
}

StuffedCrust::StuffedCrust(Pizza* pizza) : PizzaDecorator(pizza) {
}

Pizza* StuffedCrust::replicate() {
	return new StuffedCrust(this->getPizza()->replicate());
}
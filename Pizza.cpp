#include "Pizza.h"

void Pizza::printPizza() {
	// TODO - implement Pizza::printPizza
	throw "Not yet implemented";
}

double BasePizza::getPrice() {
	// TODO - implement BasePizza::getPrice
	throw "Not yet implemented";
}

std::string BasePizza::getName() {
	// TODO - implement BasePizza::getName
	throw "Not yet implemented";
}

BasePizza::BasePizza(PizzaComponent* toppings) : toppings(toppings) {
	// TODO - implement BasePizza::BasePizza
	throw "Not yet implemented";
}

double PizzaDecorator::getPrice() {
	// TODO - implement PizzaDecorator::getPrice
	throw "Not yet implemented";
}

std::string PizzaDecorator::getName() {
	// TODO - implement PizzaDecorator::getName
	throw "Not yet implemented";
}

void PizzaDecorator::printPizza() {
	// TODO - implement PizzaDecorator::printPizza
	throw "Not yet implemented";
}

double ExtraCheese::getPrice() {
	// TODO - implement ExtraCheese::getPrice
	throw "Not yet implemented";
}

std::string ExtraCheese::getName() {
	// TODO - implement ExtraCheese::getName
	throw "Not yet implemented";
}

ExtraCheese::ExtraCheese(Pizza* pizza) : PizzaDecorator(pizza) {
}

double StuffedCrust::getPrice() {
	// TODO - implement StuffedCrust::getPrice
	throw "Not yet implemented";
}

std::string StuffedCrust::getName() {
	// TODO - implement StuffedCrust::getName
	throw "Not yet implemented";
}

StuffedCrust::StuffedCrust(Pizza* pizza) : PizzaDecorator(pizza) {
}
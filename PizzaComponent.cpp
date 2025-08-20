#include "PizzaComponent.h"

std::string PizzaComponent::getName() {
	return this->name;
}

double PizzaComponent::getPrice() {
	return this->price;
}

Topping::Topping(std::string name, double price) : PizzaComponent(name, price) {
}

void ToppingGroup::add(PizzaComponent component) {
	// TODO - implement ToppingGroup::add
	throw "Not yet implemented";
}

void ToppingGroup::remove(PizzaComponent component) {
	// TODO - implement ToppingGroup::remove
	throw "Not yet implemented";
}

ToppingGroup::ToppingGroup(std::string name, double price) : PizzaComponent(name, price) {
}
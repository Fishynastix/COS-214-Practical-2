#include "PizzaComponent.h"

std::string PizzaComponent::getName() {
	return this->name;
}

double PizzaComponent::getPrice() {
	return this->price;
}

PizzaComponent* PizzaComponent::replicate() {
	return new PizzaComponent(this->name, this->price);
}

Topping::Topping(std::string name, double price) : PizzaComponent(name, price) {
}

std::string Topping::getName() {
	return PizzaComponent::getName();
}

double Topping::getPrice() {
	return PizzaComponent::getPrice();
}

PizzaComponent* Topping::replicate() {
	return new Topping(this->getName(), this->getPrice());
}

void ToppingGroup::add(PizzaComponent* component) {
	if (component == nullptr) {
		return;
	}
	toppings.push_back(component);
}

/*If there are more hierchies of toppings then
the remove function will require a component that will be the same as the hierarchy whishing to be removed*/
void ToppingGroup::remove(PizzaComponent* component) {
	if (component == nullptr) {
		return;
	}
	
	for (int i = 0; i < toppings.size(); i++)
	{
		if (toppings[i]->getName() == component->getName() && toppings[i]->getPrice() == component->getPrice())
		{
			delete toppings[i];
			toppings.erase(toppings.begin() + i);
			break;
		}
	}
}

ToppingGroup::ToppingGroup(std::string name, double price) : PizzaComponent(name, price) {
}

std::string ToppingGroup::getName() {
	std::string fullName = PizzaComponent::getName() + " (";
	for (int i = 0; i < toppings.size(); i++)
	{
		fullName += toppings[i]->getName();
		if (i < toppings.size() - 1) {
			fullName += ", ";
		}
	}
	fullName += ")";
	return fullName;
}

double ToppingGroup::getPrice() {
	double totalPrice = PizzaComponent::getPrice();
	for (int i = 0; i < toppings.size(); i++)
	{
		totalPrice += toppings[i]->getPrice();
	}
	return totalPrice;
}

ToppingGroup::~ToppingGroup() {
	for (PizzaComponent* topping : toppings) {
		delete topping;
	}
	toppings.clear();
}

PizzaComponent* ToppingGroup::replicate() {
	ToppingGroup* newGroup = new ToppingGroup(this->getName(), this->getPrice());
	for (PizzaComponent* topping : toppings) {
		newGroup->add(topping->replicate());
	}
	return newGroup;
}
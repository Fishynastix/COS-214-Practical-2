#include "Order.h"

void Order::addPizza(Pizza* pizza) {
	pizzas.push_back(pizza);
}

double Order::calculateTotal() {
        total = 0.0;
        for (Pizza* pizza : pizzas) total += pizza->getPrice();
		if (discountStrategy != nullptr)
		{
			total = discountStrategy->applyDiscount(total, *this);
		}
        return total;
}

void Order::setDiscountStrategy(DiscountStrategy* strategy) {
	if (strategy == nullptr)
	{
		return;
	}
	if (this->discountStrategy != nullptr)
	{
		delete this->discountStrategy;
	}
	this->discountStrategy = strategy;
}

void Order::processOrder() {
	if (state != nullptr)
	{
		state->processOrder(this);
	}
}

void Order::cancelOrder() {
	if (state != nullptr)
	{
		state->cancelOrder(this);
	}
}

void Order::setState(OrderState* state) {
	if (this->state != nullptr)
	{
		delete this->state;
		this->state = nullptr;
	}
	this->state = state;
}

std::string Order::getStateName() {
	return state ? state->getStateName() : "None";
}

Order::Order(Customer* customer) : customer(customer), total(0.0) {
	state = new PendingState();
	discountStrategy = new RegularPrice();
}

Order::~Order() {
	if (state != nullptr)
	{
		delete state;
		state = nullptr;
	}
	if (discountStrategy != nullptr)
	{
		delete discountStrategy;
		discountStrategy = nullptr;
	}
}

int Order::getPizzaCount() { return pizzas.size(); } // Helper for BulkDiscount

bool Order::isFamilyOrder() { return customer->getIsFamily(); } // Helper for FamilyDiscount

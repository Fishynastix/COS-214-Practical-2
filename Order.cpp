#include "Order.h"

void Order::addPizza(Pizza* pizza) {
	pizzas.push_back(pizza);
}

double Order::calculateTotal() {
        total = 0.0;
        for (Pizza* pizza : pizzas) total += pizza->getPrice();
        total = strategy->applyDiscount(total, *this);
        return total;
}

void Order::setDiscountStrategy(DiscountStrategy* strategy) {
	delete this->strategy;
	this->strategy = strategy;
}

void Order::processOrder() {
	state->processOrder(*this);
}

void Order::cancelOrder() {
	state->cancelOrder(*this);
}

void Order::setState(OrderState* state) {
	delete this->state;
	this->state = state;
}

std::string Order::getStateName() {
	return state ? state->getStateName() : "None";
}

Order::Order(Customer* customer) : customer(customer), state(new PendingState()), discountStrategy(new RegularPrice()), total(0.0) {
}

Order::~Order() {
	delete state;
	delete discountStrategy;
}

int Order::getPizzaCount() { return pizzas.size(); } // Helper for BulkDiscount

bool Order::isFamilyOrder() { return customer->getIsFamily(); } // Helper for FamilyDiscount

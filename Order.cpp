#include "Order.h"

//don't add a pizza here that is already added in the menu only use menu replicate or build your own pizza
void Order::addPizza(Pizza* pizza) {
	if (pizza == nullptr)
	{
		return;
	}
	pizzas.push_back(pizza);
}

double Order::calculateTotal() {
        total = 0.0;
        for (Pizza* pizza : pizzas) total += pizza->getPrice();
		if (discountContext != nullptr)
		{
			total = discountContext->applyDiscount(total, this);
		}
        return total;
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
}

Order::~Order() {
	if (state != nullptr)
	{
		delete state;
		state = nullptr;
	}
	if (discountContext != nullptr)
	{
		delete discountContext;
		discountContext = nullptr;
	}
	for (int i = 0; i < pizzas.size(); i++)
	{
		delete pizzas[i];
	}
	pizzas.clear();
}

int Order::getPizzaCount() { return pizzas.size(); } // Helper for BulkDiscount

bool Order::isFamilyOrder() { return customer->getIsFamily(); } // Helper for FamilyDiscount

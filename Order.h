#ifndef ORDER_H
#define ORDER_H

#include "Pizza.h"
#include "Customer.h"
#include "DiscountStrategy.h"

class OrderState;

class Order {

private:
	Pizza* pizzas;
	Customer customer;
	OrderState state; //maybe use a pointer to store order state instead?
	double total;

public:
	void addPizza(Pizza pizza);

	double calculateTotal();

	void setDiscountStrategy(DiscountStrategy strategy);

	void processOrder();

	void cancelOrder();

	void setState(OrderState state);

	std::string getStateName();

	Order(Customer customer);
};

#endif

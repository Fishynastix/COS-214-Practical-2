#ifndef ORDER_H
#define ORDER_H

#include "Pizza.h"
#include "Observer.h"
#include "DiscountStrategy.h"
#include <vector>
#include <iostream>

class OrderState;

class Order {

private:
	std::vector<Pizza*> pizzas;	
	Customer* customer;
	OrderState* state; //maybe use a pointer to store order state instead?
	DiscountStrategy* discountStrategy;
	double total;

public:

	void addPizza(Pizza* pizza);

	double calculateTotal();

	void setDiscountStrategy(DiscountStrategy* strategy);

	void processOrder();

	void cancelOrder();

	void setState(OrderState* state);

	std::string getStateName();

	Order(Customer* customer);

	~Order();

	int getPizzaCount();
	bool isFamilyOrder();
};

#endif

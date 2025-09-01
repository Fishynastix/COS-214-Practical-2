#ifndef ORDER_H
#define ORDER_H

#include "Pizza.h"
#include "Observer.h"
#include "DiscountStrategy.h"
#include "OrderState.h"
#include <vector>
#include <iostream>

class Order {

private:
	std::vector<Pizza*> pizzas;	
	Customer* customer;
	OrderState* state = nullptr; 
	DiscountContext* discountContext = new DiscountContext();
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

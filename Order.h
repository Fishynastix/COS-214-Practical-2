#ifndef ORDER_H
#define ORDER_H

class Order {

private:
	Pizza* pizzas;
	Customer customer;
	OrderState state;
	double total;

public:
	void addPizza(Pizza pizza);

	double calculateTotal();

	void setDiscountStrategy(DiscountStrategy strategy);

	void processOrder();

	void cancelOrder();

	void setState(OrderState state);

	string getStateName();

	Order(Customer customer);
};

#endif

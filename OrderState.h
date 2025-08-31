#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include <iostream>

class Order;

class OrderState {
public:
	virtual void processOrder(Order order) = 0;
	virtual void cancelOrder(Order order) = 0;
	virtual std::string getStateName() = 0;
};

class DeliveredState : public OrderState {
public:
	void processOrder(Order order) override;
	void cancelOrder(Order order) override;
	std::string getStateName() override;
};

class ReadyState : public OrderState {
public:
	void processOrder(Order order) override;
	void cancelOrder(Order order) override;
	std::string getStateName() override;
};

class PendingState : public OrderState {
public:
	void processOrder(Order order) override;
	void cancelOrder(Order order) override;
	std::string getStateName() override;
};

class PreparingState : public OrderState {
public:
	void processOrder(Order order) override;
	void cancelOrder(Order order) override;
	std::string getStateName() override;
};

#include "Order.h"

#endif

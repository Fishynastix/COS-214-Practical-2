#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include "Order.h"
#include <iostream>

class OrderState {
public:
	virtual void processOrder(Order order);
	virtual void cancelOrder(Order order);
	virtual std::string getStateName();
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

#endif

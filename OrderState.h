#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include "Order.h"

class OrderState {


public:
	void processOrder(Order order);

	void cancelOrder(Order order);

	std::string getStateName();
};

#endif

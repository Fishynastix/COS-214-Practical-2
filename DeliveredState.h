#ifndef DELIVEREDSTATE_H
#define DELIVEREDSTATE_H

#include "Order.h"

class DeliveredState {


public:
	void processOrder(Order order);

	void cancelOrder(Order order);

	std::string getStateName();
};

#endif

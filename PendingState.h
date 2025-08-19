#ifndef PENDINGSTATE_H
#define PENDINGSTATE_H

#include "Order.h"

class PendingState {


public:
	void processOrder(Order order);

	void cancelOrder(Order order);

	std::string getStateName();
};

#endif

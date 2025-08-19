#ifndef PREPARINGSTATE_H
#define PREPARINGSTATE_H

#include "Order.h"

class PreparingState {


public:
	void processOrder(Order order);

	void cancelOrder(Order order);

	std::string getStateName();
};

#endif

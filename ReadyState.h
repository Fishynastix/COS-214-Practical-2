#ifndef READYSTATE_H
#define READYSTATE_H

#include "Order.h"

class ReadyState {


public:
	void processOrder(Order order);

	void cancelOrder(Order order);

	std::string getStateName();
};

#endif

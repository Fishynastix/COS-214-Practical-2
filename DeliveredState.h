#ifndef DELIVEREDSTATE_H
#define DELIVEREDSTATE_H

class DeliveredState {


public:
	void processOrder(Order order);

	void cancelOrder(Order order);

	string getStateName();
};

#endif

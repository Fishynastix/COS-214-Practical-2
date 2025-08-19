#ifndef PENDINGSTATE_H
#define PENDINGSTATE_H

class PendingState {


public:
	void processOrder(Order order);

	void cancelOrder(Order order);

	string getStateName();
};

#endif

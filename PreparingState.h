#ifndef PREPARINGSTATE_H
#define PREPARINGSTATE_H

class PreparingState {


public:
	void processOrder(Order order);

	void cancelOrder(Order odrer);

	string getStateName();
};

#endif

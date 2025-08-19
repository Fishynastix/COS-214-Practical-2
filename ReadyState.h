#ifndef READYSTATE_H
#define READYSTATE_H

class ReadyState {


public:
	void processOrder(Order order);

	void cancelOrder(Order order);

	string getStateName();
};

#endif

#ifndef ORDERSTATE_H
#define ORDERSTATE_H

class OrderState {


public:
	void processOrder(Order order);

	void cancelOrder(Order order);

	string getStateName();
};

#endif

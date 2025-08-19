#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#include "Order.h"

class DiscountStrategy {


public:
	double applyDiscount(double total, Order order);
};

#endif

#ifndef REGULARPRICE_H
#define REGULARPRICE_H

#include "Order.h"

class RegularPrice {


public:
	double applyDiscount(double total, Order order);
};

#endif

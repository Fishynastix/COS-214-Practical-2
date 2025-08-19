#ifndef BULKDISCOUNT_H
#define BULKDISCOUNT_H

#include "Order.h"

class BulkDiscount {


public:
	double applyDiscount(double total, Order order);
};

#endif

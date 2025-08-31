#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#include "Order.h"

class DiscountStrategy {
public:
	virtual double applyDiscount(double total, Order order) = 0;
};

class BulkDiscount : public DiscountStrategy {
public:
	double applyDiscount(double total, Order order) override;
};

class FamilyDiscount : public DiscountStrategy {
public:
	double applyDiscount(double total, Order order) override;
};

class RegularPrice : public DiscountStrategy {
public:
	double applyDiscount(double total, Order order) override;
};

#endif

#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

class Order; 

class DiscountStrategy {
public:
	virtual double applyDiscount(double total) = 0;
};

class BulkDiscount : public DiscountStrategy {
public:
	double applyDiscount(double total) override;
};

class FamilyDiscount : public DiscountStrategy {
public:
	double applyDiscount(double total) override;
};

class RegularPrice : public DiscountStrategy {
public:
	double applyDiscount(double total) override;
};

class DiscountContext {
private:
	DiscountStrategy* strategy = nullptr;
public:
	double applyDiscount(double total, Order* order);
	~DiscountContext() { if (strategy != nullptr) delete strategy; }
};

#include "Order.h"

#endif

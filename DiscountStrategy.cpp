#include "DiscountStrategy.h"

double DiscountContext::applyDiscount(double total, Order* order) {
    if (strategy != nullptr)
    {
        delete strategy;
        strategy = nullptr;
    }
    
    if (order->isFamilyOrder())
    {
        strategy = new FamilyDiscount();
    }
    else if (order->getPizzaCount() >= 5)
    {
        strategy = new BulkDiscount();
    }
    else
    {
        strategy = new RegularPrice();
    }

    return strategy->applyDiscount(total);
}

double BulkDiscount::applyDiscount(double total) {
    return total * 0.9; // 10% discount
}

double FamilyDiscount::applyDiscount(double total) {
    return total * 0.85; // 15% discount
}

double RegularPrice::applyDiscount(double total) {
    return total;
}
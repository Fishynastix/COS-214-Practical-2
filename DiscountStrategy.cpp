#include "DiscountStrategy.h"

double BulkDiscount::applyDiscount(double total, Order* order) {
    return total; // No discount
}

double FamilyDiscount::applyDiscount(double total, Order* order) {
    if (order->isFamilyOrder()) return total * 0.85; // 15% discount
    return total;
}

double RegularPrice::applyDiscount(double total, Order* order) {
    if (order->getPizzaCount() >= 5) return total * 0.9; // 10% discount
    return total;
}
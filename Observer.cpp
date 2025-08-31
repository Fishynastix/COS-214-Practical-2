#include "Observer.h"

void Customer::update(std::string message) {
    std::cout << "Customer " << name << " received: " << message << std::endl;
}

Customer::Customer(std::string name, bool isFamily) : name(name), isFamily(isFamily) {}

bool Customer::getIsFamily() const { return isFamily; } // Helper for FamilyDiscount

void Website::update(std::string message) {
    std::cout << "Website updated: " << message << std::endl;
}
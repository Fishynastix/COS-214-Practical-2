#include "OrderState.h"

void OrderState::processOrder(Order order) {}

void OrderState::cancelOrder(Order order) {}

std::string OrderState::getStateName() {
	return "";
}

void ReadyState::processOrder(Order order) {
    std::cout << "Order moving from Ready to Delivered" << std::endl;
    order.setState(new DeliveredState());
}

void ReadyState::cancelOrder(Order order) {
    std::cout << "Order reverted from Ready to Pending" << std::endl;
    order.setState(new PendingState()); // Backward transition
}

std::string ReadyState::getStateName() {
    return "Ready";
}

void DeliveredState::processOrder(Order order) {
    std::cout << "Error: Cannot process a delivered order" << std::endl;
}

void DeliveredState::cancelOrder(Order order) {
    std::cout << "Error: Cannot cancel a delivered order" << std::endl;
}

std::string DeliveredState::getStateName() {
    return "Delivered";
}

void PreparingState::processOrder(Order order) {
    std::cout << "Order moving from Preparing to Ready" << std::endl;
    order.setState(new ReadyState());
}

void PreparingState::cancelOrder(Order order) {
    std::cout << "Order reverted from Preparing to Pending" << std::endl;
    order.setState(new PendingState()); // Backward transition
}

std::string PreparingState::getStateName() {
    return "Preparing";
}

void PendingState::processOrder(Order order) {
    std::cout << "Order moving from Pending to Preparing" << std::endl;
    order.setState(new PreparingState());
}

void PendingState::cancelOrder(Order order) {
    std::cout << "Order cancelled in Pending state" << std::endl;
    order.setState(nullptr); // Or a CancelledState
}

std::string PendingState::getStateName() {
    return "Pending";
}

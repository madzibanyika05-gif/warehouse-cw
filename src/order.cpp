#include "order.h"
//responsible for getting order details
Order::Order(const std::string& orderId,
             const std::string& productId,
             int quantity,
             const std::string& employeeId,
             const std::string& status)
    : orderId(orderId),
      productId(productId),
      quantity(quantity),
      employeeId(employeeId),
      status(status) {}

std::string Order::getOrderId() const {// returns order id
    return orderId;
}

std::string Order::getProductId() const {// return product id
    return productId;
}

int Order::getQuantity() const {// returns amount
    return quantity;
}

std::string Order::getEmployeeId() const {
    return employeeId;
}

std::string Order::getStatus() const {
    return status;
}

void Order::setProductId(const std::string& newProductId) {
    productId = newProductId;
}

void Order::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

void Order::setEmployeeId(const std::string& newEmployeeId) {
    employeeId = newEmployeeId;
}

void Order::setStatus(const std::string& newStatus) {
    status = newStatus;
}
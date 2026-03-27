#ifndef ORDERSTORE_H
#define ORDERSTORE_H

#include <vector>
#include <string>
#include "order.h"
//class responsible for storing order data
class OrderStore {
private:
    std::vector<Order> orders;

public:
    bool addOrder(const Order& o);
    const std::vector<Order>& list() const;

    bool removeOrder(const std::string& orderId);

    bool updateOrder(const std::string& orderId,
                     const std::string& productId,
                     int quantity);

    bool assignOrder(const std::string& orderId,
                     const std::string& employeeId);

    bool completeOrder(const std::string& orderId);

    std::vector<Order> getOrdersForEmployee(const std::string& employeeId) const;

    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};

#endif
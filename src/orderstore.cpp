#include "orderstore.h"
#include <fstream>
#include <sstream>

bool OrderStore::addOrder(const Order& o) {
    for (const auto& existing : orders) {
        if (existing.getOrderId() == o.getOrderId()) {
            return false;
        }
    }
    orders.push_back(o);
    return true;
}

const std::vector<Order>& OrderStore::list() const {
    return orders;
}

bool OrderStore::removeOrder(const std::string& orderId) {
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        if (it->getOrderId() == orderId) {
            orders.erase(it);
            return true;
        }
    }
    return false;
}

bool OrderStore::updateOrder(const std::string& orderId,
                             const std::string& productId,
                             int quantity) {
    for (auto& o : orders) {
        if (o.getOrderId() == orderId) {
            o.setProductId(productId);
            o.setQuantity(quantity);
            return true;
        }
    }
    return false;
}

bool OrderStore::assignOrder(const std::string& orderId,
                             const std::string& employeeId) {
    for (auto& o : orders) {
        if (o.getOrderId() == orderId) {
            o.setEmployeeId(employeeId);
            return true;
        }
    }
    return false;
}

bool OrderStore::completeOrder(const std::string& orderId) {
    for (auto& o : orders) {
        if (o.getOrderId() == orderId) {
            o.setStatus("COMPLETED");
            return true;
        }
    }
    return false;
}

std::vector<Order> OrderStore::getOrdersForEmployee(const std::string& employeeId) const {
    std::vector<Order> matches;

    for (const auto& o : orders) {
        if (o.getEmployeeId() == employeeId) {
            matches.push_back(o);
        }
    }

    return matches;
}

void OrderStore::loadFromFile(const std::string& filename) {
    orders.clear();

    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string orderId, productId, quantityStr, employeeId, status;

        std::getline(ss, orderId, ',');
        std::getline(ss, productId, ',');
        std::getline(ss, quantityStr, ',');
        std::getline(ss, employeeId, ',');
        std::getline(ss, status, ',');

        int quantity = std::stoi(quantityStr);
        orders.emplace_back(orderId, productId, quantity, employeeId, status);
    }
}

void OrderStore::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& o : orders) {
        file << o.getOrderId() << ","
             << o.getProductId() << ","
             << o.getQuantity() << ","
             << o.getEmployeeId() << ","
             << o.getStatus() << "\n";
    }
}
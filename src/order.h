#ifndef ORDER_H
#define ORDER_H

#include <string>
//responsible for system orders
class Order {
private:
    std::string orderId;
    std::string productId;
    int quantity;
    std::string employeeId;
    std::string status;

public:// create new order and getting info
    Order(const std::string& orderId,
          const std::string& productId,
          int quantity,
          const std::string& employeeId,
          const std::string& status);

    std::string getOrderId() const;
    std::string getProductId() const;
    int getQuantity() const;
    std::string getEmployeeId() const;
    std::string getStatus() const;

    void setProductId(const std::string& newProductId);
    void setQuantity(int newQuantity);
    void setEmployeeId(const std::string& newEmployeeId);
    void setStatus(const std::string& newStatus);
};

#endif

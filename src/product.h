

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string id;
    std::string name;
    int quantity;
    std::string location;

public:
    Product(const std::string& id,
            const std::string& name,
            int quantity,
            const std::string& location);

    std::string getId() const;
    std::string getName() const;
    int getQuantity() const;
    std::string getLocation() const;

    void setQuantity(int q);
};

#endif
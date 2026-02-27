#include "product.h"

Product::Product(const std::string& id,
                 const std::string& name,
                 int quantity,
                 const std::string& location)
    : id(id), name(name), quantity(quantity), location(location) {}

std::string Product::getId() const {
    return id;
}

std::string Product::getName() const {
    return name;
}

int Product::getQuantity() const {
    return quantity;
}

std::string Product::getLocation() const {
    return location;
}

void Product::setQuantity(int q) {
    quantity = q;
}

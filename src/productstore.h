#ifndef PRODUCTSTORE_H
#define PRODUCTSTORE_H

#include <vector>
#include <string>
#include "product.h"
//class for storing and handling product data
class ProductStore {
private:
    std::vector<Product> products;

public:
    bool addProduct(const Product& p);
    const std::vector<Product>& list() const;
    bool removeProduct(const std::string& id);
    bool updateProduct(const std::string& id,
                       const std::string& name,
                       int quantity,
                       const std::string& location);
    std::vector<Product> searchProducts(const std::string& term) const;

    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};

#endif

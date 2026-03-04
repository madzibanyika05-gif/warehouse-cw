#include "productstore.h"
#include <fstream>
#include <sstream>

bool ProductStore::addProduct(const Product& p) {
    // Prevent duplicate IDs
    for (const auto& existing : products) {
        if (existing.getId() == p.getId()) {
            return false;
        }
    }
    products.push_back(p);
    return true;
}

const std::vector<Product>& ProductStore::list() const {
    return products;
}

bool ProductStore::removeProduct(const std::string& id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            return true;
        }
    }
    return false;
}

void ProductStore::loadFromFile(const std::string& filename) {
    products.clear();

    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string id, name, quantityStr, location;

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::getline(ss, quantityStr, ',');
        std::getline(ss, location, ',');

        try {
            int quantity = std::stoi(quantityStr);
            products.emplace_back(id, name, quantity, location);
        } catch (...) {
            // Skip malformed lines
        }
    }
}

void ProductStore::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& p : products) {
        file << p.getId() << ","
             << p.getName() << ","
             << p.getQuantity() << ","
             << p.getLocation() << "\n";
    }
}

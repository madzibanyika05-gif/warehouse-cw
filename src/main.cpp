#include <iostream>
#include <string>
#include "productstore.h"

void showProducts(const ProductStore& store) {
    const auto& products = store.list();

    if (products.empty()) {
        std::cout << "No products found.\n";
        return;
    }

    for (const auto& p : products) {
        std::cout << "ID: " << p.getId()
                  << " | Name: " << p.getName()
                  << " | Qty: " << p.getQuantity()
                  << " | Location: " << p.getLocation()
                  << "\n";
    }
}

void addProduct(ProductStore& store) {
    std::string id, name, location;
    int quantity;

    std::cout << "Enter Product ID: ";
    std::getline(std::cin, id);

    std::cout << "Enter Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Quantity: ";
    std::cin >> quantity;
    std::cin.ignore();

    std::cout << "Enter Location: ";
    std::getline(std::cin, location);

    Product p(id, name, quantity, location);

    if (!store.addProduct(p)) {
        std::cout << "Product with this ID already exists.\n";
    } else {
        store.saveToFile("data/products.csv");
        std::cout << "Product added successfully.\n";
    }
}

int main() {
    ProductStore store;
    store.loadFromFile("data/products.csv");

    while (true) {
        std::cout << "\nWarehouse Inventory System\n";
        std::cout << "1. View Products\n";
        std::cout << "2. Add Product\n";
        std::cout << "3. Exit\n";
        std::cout << "Choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            showProducts(store);
        }
        else if (choice == 2) {
            addProduct(store);
        }
        else if (choice == 3) {
            break;
        }
        else {
            std::cout << "Invalid option.\n";
        }
    }

    return 0;
}
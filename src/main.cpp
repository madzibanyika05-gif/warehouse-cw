#include <iostream>
#include <string>
#include <vector>
#include "productstore.h"
#include "employeestore.h"
#include "orderstore.h"

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

void deleteProduct(ProductStore& store) {
    std::string id;

    std::cout << "Enter Product ID to delete: ";
    std::getline(std::cin, id);

    if (store.removeProduct(id)) {
        store.saveToFile("data/products.csv");
        std::cout << "Product deleted successfully.\n";
    } else {
        std::cout << "Product not found.\n";
    }
}

void editProduct(ProductStore& store) {
    std::string id, name, location;
    int quantity;

    std::cout << "Enter Product ID to edit: ";
    std::getline(std::cin, id);

    std::cout << "Enter New Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter New Quantity: ";
    std::cin >> quantity;
    std::cin.ignore();

    std::cout << "Enter New Location: ";
    std::getline(std::cin, location);

    if (store.updateProduct(id, name, quantity, location)) {
        store.saveToFile("data/products.csv");
        std::cout << "Product updated successfully.\n";
    } else {
        std::cout << "Product not found.\n";
    }
}

void searchProduct(const ProductStore& store) {
    std::string term;
    std::cout << "Enter Product ID or Name to search: ";
    std::getline(std::cin, term);

    std::vector<Product> results = store.searchProducts(term);

    if (results.empty()) {
        std::cout << "No matching products found.\n";
        return;
    }

    std::cout << "\nMatching Products:\n";
    for (const auto& p : results) {
        std::cout << "ID: " << p.getId()
                  << " | Name: " << p.getName()
                  << " | Qty: " << p.getQuantity()
                  << " | Location: " << p.getLocation()
                  << "\n";
    }
}

void showEmployees(const EmployeeStore& store) {
    const auto& employees = store.list();

    if (employees.empty()) {
        std::cout << "No employees found.\n";
        return;
    }

    for (const auto& e : employees) {
        std::cout << "ID: " << e.getId()
                  << " | Name: " << e.getName()
                  << "\n";
    }
}

void addEmployee(EmployeeStore& store) {
    std::string id, name;

    std::cout << "Enter Employee ID: ";
    std::getline(std::cin, id);

    std::cout << "Enter Employee Name: ";
    std::getline(std::cin, name);

    Employee e(id, name);

    if (!store.addEmployee(e)) {
        std::cout << "Employee with this ID already exists.\n";
    } else {
        store.saveToFile("data/employees.csv");
        std::cout << "Employee added successfully.\n";
    }
}

void deleteEmployee(EmployeeStore& store) {
    std::string id;

    std::cout << "Enter Employee ID to delete: ";
    std::getline(std::cin, id);

    if (store.removeEmployee(id)) {
        store.saveToFile("data/employees.csv");
        std::cout << "Employee deleted successfully.\n";
    } else {
        std::cout << "Employee not found.\n";
    }
}

void editEmployee(EmployeeStore& store) {
    std::string id, name;

    std::cout << "Enter Employee ID to edit: ";
    std::getline(std::cin, id);

    std::cout << "Enter New Employee Name: ";
    std::getline(std::cin, name);

    if (store.updateEmployee(id, name)) {
        store.saveToFile("data/employees.csv");
        std::cout << "Employee updated successfully.\n";
    } else {
        std::cout << "Employee not found.\n";
    }
}

void searchEmployee(const EmployeeStore& store) {
    std::string term;
    std::cout << "Enter Employee ID or Name to search: ";
    std::getline(std::cin, term);

    std::vector<Employee> results = store.searchEmployees(term);

    if (results.empty()) {
        std::cout << "No matching employees found.\n";
        return;
    }

    std::cout << "\nMatching Employees:\n";
    for (const auto& e : results) {
        std::cout << "ID: " << e.getId()
                  << " | Name: " << e.getName()
                  << "\n";
    }
}

void showOrders(const OrderStore& store) {
    const auto& orders = store.list();

    if (orders.empty()) {
        std::cout << "No orders found.\n";
        return;
    }

    for (const auto& o : orders) {
        std::cout << "OrderID: " << o.getOrderId()
                  << " | ProductID: " << o.getProductId()
                  << " | Qty: " << o.getQuantity()
                  << " | Employee: " << o.getEmployeeId()
                  << " | Status: " << o.getStatus()
                  << "\n";
    }
}

void viewAssignedOrders(const OrderStore& store) {
    std::string employeeId;

    std::cout << "Enter Employee ID to view assigned orders: ";
    std::getline(std::cin, employeeId);

    std::vector<Order> assignedOrders = store.getOrdersForEmployee(employeeId);

    if (assignedOrders.empty()) {
        std::cout << "No orders assigned to this employee.\n";
        return;
    }

    std::cout << "\nAssigned Orders:\n";
    for (const auto& o : assignedOrders) {
        std::cout << "OrderID: " << o.getOrderId()
                  << " | ProductID: " << o.getProductId()
                  << " | Qty: " << o.getQuantity()
                  << " | Employee: " << o.getEmployeeId()
                  << " | Status: " << o.getStatus()
                  << "\n";
    }
}

void createOrder(OrderStore& store, const ProductStore& productStore) {
    std::string orderId, productId;
    int quantity;

    std::cout << "Enter Order ID: ";
    std::getline(std::cin, orderId);

    std::cout << "Enter Product ID: ";
    std::getline(std::cin, productId);

    std::cout << "Enter Quantity: ";
    std::cin >> quantity;
    std::cin.ignore();

    bool productFound = false;
    bool enoughStock = false;

    for (const auto& p : productStore.list()) {
        if (p.getId() == productId) {
            productFound = true;

            if (quantity > 0 && p.getQuantity() >= quantity) {
                enoughStock = true;
            }
            break;
        }
    }

    if (!productFound) {
        std::cout << "Product not found.\n";
        return;
    }

    if (!enoughStock) {
        std::cout << "Not enough stock available for this order.\n";
        return;
    }

    Order o(orderId, productId, quantity, "UNASSIGNED", "PENDING");

    if (!store.addOrder(o)) {
        std::cout << "Order with this ID already exists.\n";
    } else {
        store.saveToFile("data/orders.csv");
        std::cout << "Order created successfully.\n";
    }
}

void editOrder(OrderStore& store) {
    std::string orderId, productId;
    int quantity;

    std::cout << "Enter Order ID to edit: ";
    std::getline(std::cin, orderId);

    std::cout << "Enter New Product ID: ";
    std::getline(std::cin, productId);

    std::cout << "Enter New Quantity: ";
    std::cin >> quantity;
    std::cin.ignore();

    if (store.updateOrder(orderId, productId, quantity)) {
        store.saveToFile("data/orders.csv");
        std::cout << "Order updated successfully.\n";
    } else {
        std::cout << "Order not found.\n";
    }
}

void assignOrder(OrderStore& store) {
    std::string orderId, employeeId;

    std::cout << "Enter Order ID to assign: ";
    std::getline(std::cin, orderId);

    std::cout << "Enter Employee ID: ";
    std::getline(std::cin, employeeId);

    if (store.assignOrder(orderId, employeeId)) {
        store.saveToFile("data/orders.csv");
        std::cout << "Order assigned successfully.\n";
    } else {
        std::cout << "Order not found.\n";
    }
}

void completeOrder(OrderStore& store, ProductStore& productStore) {
    std::string orderId;

    std::cout << "Enter Order ID to complete: ";
    std::getline(std::cin, orderId);

    // find the order first
    const auto& orders = store.list();

    std::string productId;
    int orderQty = 0;
    bool found = false;

    for (const auto& o : orders) {
        if (o.getOrderId() == orderId) {
            productId = o.getProductId();
            orderQty = o.getQuantity();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Order not found.\n";
        return;
    }

    // find the product and reduce stock
    const auto& products = productStore.list();

    for (const auto& p : products) {
        if (p.getId() == productId) {
            int newQty = p.getQuantity() - orderQty;
            if (newQty < 0) newQty = 0;

            productStore.updateProduct(
                p.getId(),
                p.getName(),
                newQty,
                p.getLocation()
            );

            productStore.saveToFile("data/products.csv");
            break;
        }
    }

    // now mark order as completed
    if (store.completeOrder(orderId)) {
        store.saveToFile("data/orders.csv");
        std::cout << "Order completed and stock updated.\n";
    }
}

int main() {
    ProductStore store;
    store.loadFromFile("data/products.csv");

    EmployeeStore employeeStore;
    employeeStore.loadFromFile("data/employees.csv");

    OrderStore orderStore;
    orderStore.loadFromFile("data/orders.csv");

    while (true) {
        std::cout << "\nWarehouse Inventory System\n";

        std::cout << "\nPRODUCTS\n";
        std::cout << "1. View Products\n";
        std::cout << "2. Add Product\n";
        std::cout << "3. Delete Product\n";
        std::cout << "4. Edit Product\n";
        std::cout << "5. Search Product\n";

        std::cout << "\nEMPLOYEES\n";
        std::cout << "6. View Employees\n";
        std::cout << "7. Add Employee\n";
        std::cout << "8. Delete Employee\n";
        std::cout << "9. Edit Employee\n";
        std::cout << "10. Search Employee\n";

        std::cout << "\nORDERS\n";
        std::cout << "11. View Orders\n";
        std::cout << "12. Create Order\n";
        std::cout << "13. Edit Order\n";
        std::cout << "14. Assign Order\n";
        std::cout << "15. View Assigned Orders\n";
        std::cout << "16. Complete Order\n";

        std::cout << "\n17. Exit\n";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) showProducts(store);
        else if (choice == 2) addProduct(store);
        else if (choice == 3) deleteProduct(store);
        else if (choice == 4) editProduct(store);
        else if (choice == 5) searchProduct(store);
        else if (choice == 6) showEmployees(employeeStore);
        else if (choice == 7) addEmployee(employeeStore);
        else if (choice == 8) deleteEmployee(employeeStore);
        else if (choice == 9) editEmployee(employeeStore);
        else if (choice == 10) searchEmployee(employeeStore);
        else if (choice == 11) showOrders(orderStore);
        else if (choice == 12) createOrder(orderStore, store);
        else if (choice == 13) editOrder(orderStore);
        else if (choice == 14) assignOrder(orderStore);
        else if (choice == 15) viewAssignedOrders(orderStore);
        else if (choice == 16) completeOrder(orderStore, store);
        else if (choice == 17) break;
        else std::cout << "Invalid option.\n";
    }

    return 0;
}
#include "employeestore.h"
#include <fstream>
#include <sstream>

bool EmployeeStore::addEmployee(const Employee& e) {
    for (const auto& existing : employees) {
        if (existing.getId() == e.getId()) {
            return false;
        }
    }
    employees.push_back(e);
    return true;
}

const std::vector<Employee>& EmployeeStore::list() const {
    return employees;
}

bool EmployeeStore::removeEmployee(const std::string& id) {
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->getId() == id) {
            employees.erase(it);
            return true;
        }
    }
    return false;
}

bool EmployeeStore::updateEmployee(const std::string& id, const std::string& name) {
    for (auto& e : employees) {
        if (e.getId() == id) {
            e.setName(name);
            return true;
        }
    }
    return false;
}

std::vector<Employee> EmployeeStore::searchEmployees(const std::string& term) const {
    std::vector<Employee> matches;

    for (const auto& e : employees) {
        if (e.getId() == term || e.getName().find(term) != std::string::npos) {
            matches.push_back(e);
        }
    }

    return matches;
}

void EmployeeStore::loadFromFile(const std::string& filename) {
    employees.clear();

    std::ifstream file(filename);
    if (!file.is_open()) return;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string id, name;

        std::getline(ss, id, ',');
        std::getline(ss, name, ',');

        employees.emplace_back(id, name);
    }
}

void EmployeeStore::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return;

    for (const auto& e : employees) {
        file << e.getId() << "," << e.getName() << "\n";
    }
}
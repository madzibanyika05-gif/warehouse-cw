#ifndef EMPLOYEESTORE_H
#define EMPLOYEESTORE_H

#include <vector>
#include <string>
#include "employee.h"

class EmployeeStore {
private:
    std::vector<Employee> employees;

public:
    bool addEmployee(const Employee& e);
    const std::vector<Employee>& list() const;
    bool removeEmployee(const std::string& id);
    bool updateEmployee(const std::string& id, const std::string& name);
    std::vector<Employee> searchEmployees(const std::string& term) const;

    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};

#endif
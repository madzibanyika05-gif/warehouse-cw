#include "employee.h"
//class representing employee id and name
Employee::Employee(const std::string& id, const std::string& name)
    : id(id), name(name) {}

std::string Employee::getId() const {
    return id;
}

std::string Employee::getName() const {
    return name;
}

void Employee::setName(const std::string& newName) {
    name = newName;
}
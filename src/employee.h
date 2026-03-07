#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:
    std::string id;
    std::string name;

public:
    Employee(const std::string& id, const std::string& name);

    std::string getId() const;
    std::string getName() const;

    void setName(const std::string& newName);
};

#endif
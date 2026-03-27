#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
//header for employee class
class Employee {
private:
    std::string id;
    std::string name;

public:
    Employee(const std::string& id, const std::string& name);

    std::string getId() const;// get employee id
    std::string getName() const; // get employee name

    void setName(const std::string& newName);
};

#endif
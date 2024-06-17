// This file defines a container of employees, which is maintained during
// the lifetime of the program.
module;
#include <vector>
import employee;
export module employees;

export class Employees{
private:
    std::vector<Employee> employees;

};
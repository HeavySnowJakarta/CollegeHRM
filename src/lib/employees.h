// This file defines a container of employees, which is maintained during
// the lifetime of the program.
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

#include "employee.h"

// `Employees` includes a vector container of `Employee` objects, which is
// designed to be maintained during the whole lifetime of the program.
class Employees{
private:
    // Where the info of the employees are stored.
    std::vector<Employee> employees;

    // A list of different faculties.
    // As there is no limit of faculties (there are as string), it's not wasy
    // for us to see how many faculties we have. Thus we have to maintain a
    // list that records the faculties. The key of this container stands for
    // the faculty, and the value stands for the number of it.
    std::unordered_map<std::string, int> faculties;

public:
    // Initialize the container.
    inline Employees(){
        employees = std::vector<Employee>();
    }

    // Add an employee.
    // Note repeated ids are not accepted.
    void add(Employee employee);

    // Delete an employee based on its id number.
    void del(unsigned int id);

    // Get the pointer of an employee, then get and revise its infomation.
    // I think getting the pointer here is actually safe because when there
    // is something that have to be considered carefully (eg. the major may
    // be limited on a list) the methods of `Employee` should be designed
    // properly. Someone may think provide methods here instead may be safer
    // which I actually don't think so. In fact it provides more redundancy
    // here.
    Employee* get(unsigned int id);

    // Fuzzy search by id and return a list of employees.
    std::vector<Employee*> getById(unsigned int id);

    // Fuzzy search by name.
    std::vector<Employee*> getByName(char* name);

    // Fuzzy search by sex.
    std::vector<Employee*> getBySex(Sex sex);

    // Fuzzy search by type.
    std::vector<Employee*> getByType(EmployeeType type);

    // Count the number of given properity.
    unsigned int countBySex(Sex sex);
    unsigned int countByFaculty(char* faculty);
    unsigned int countByType(EmployeeType type);
    unsigned int countByLevel(EmployeeTitle title);

    // Spread the list of faculties to the outer world.
    std::vector<const char*> getCurrentFaculties();
};
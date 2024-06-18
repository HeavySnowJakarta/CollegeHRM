// This file defines a container of employees, which is maintained during
// the lifetime of the program.
#ifndef _EMPLOYEES
#define _EMPLOYEES

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

    // To count the number of the same properity (the private fields of the
    // employees) conveniently, we use unordered maps to store and manage
    // them dynamically.
    std::unordered_map<Sex, int> sex_num;
    std::unordered_map<std::string, int> faculty_num;
    std::unordered_map<EmployeeType, int> type_num;
    std::unordered_map<EmployeeTitle, int> title_num;

    // The function to initialize the containers above. Called by the
    // constructor(s).
    void initContainers();

    // TODO: The path to save autoly.

public:
    // Initialize the container.
    // Used to create a new database.
    inline Employees(){
        initContainers();
    }

    // Add an employee.
    // Note repeated ids are not accepted.
    void add(Employee employee);

    // Delete an employee based on its id number.
    void del(unsigned int id);

    // Get the iterator of a needed employee by its id. Then you can
    // read and write the fields of it. What can be accessed has been
    // already controled by `struct Employee`. When it does not exist,
    // `employees.end()` would be returned.
    std::vector<Employee>::iterator get(unsigned int id);

    // When there is no matching `Employee` object on `employees`,
    // `employees.end()` would be returned. So the outer world have to know
    // a way to compare the result with `employees.end()`. That's why we
    // return `employees.end()` here.
    inline std::vector<Employee>::iterator getEnd(){
        return employees.end();
    }

    // Fuzzy search by id and return a list of employees.
    std::vector<std::vector<Employee>::iterator> getById(unsigned int id);

    // Fuzzy search by name.
    std::vector<std::vector<Employee>::iterator> getByName(char* name);

    // Fuzzy search by sex.
    std::vector<std::vector<Employee>::iterator> getBySex(Sex sex);

    // Fuzzy search by type.
    std::vector<std::vector<Employee>::iterator> getByType(EmployeeType type);

    // Count the number of given properity.
    unsigned int countBySex(Sex sex);
    unsigned int countByFaculty(char* faculty);
    unsigned int countByType(EmployeeType type);
    unsigned int countByLevel(EmployeeTitle title);

    // Spread the list of faculties to the outer world.
    std::vector<const char*> getCurrentFaculties();
};

#endif
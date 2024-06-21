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

    // See if a string includes another string. Used by `getById()` and
    // `getByName()`.
    inline static bool contains(
        const std::string& long_str,
        const std::string& short_str
    );

public:
    // Initialize the container. Automatically open the database file.
    // Used for empty databases.
    inline Employees(){
        initContainers();
    };

    // Load from employees that already exist.
    Employees(std::vector<Employee> employees);

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

    // To save all the employees, the iterator of begin() has to be provided.
    inline std::vector<Employee>::iterator getBegin(){
        return employees.begin();
    }

    // Set the provate fields of an employee, with updating the counters.
    void setSex(std::vector<Employee>::iterator employee, Sex sex);
    void setFaculty(
        std::vector<Employee>::iterator employee,
        const char* faculty
    );
    void setType(std::vector<Employee>::iterator employee, EmployeeType type);
    void setTitle(
        std::vector<Employee>::iterator employee,
        EmployeeTitle title
    );

    // Fuzzy search by id and return a list of employees.
    std::vector<std::vector<Employee>::iterator> getById(unsigned int id);

    // Fuzzy search by name.
    std::vector<std::vector<Employee>::iterator> getByName(char* name);

    // Get a list that the elements fits the given sex.
    std::vector<std::vector<Employee>::iterator> getBySex(Sex sex);

    // Get a list that the elements fits the given type.
    std::vector<std::vector<Employee>::iterator> getByType(EmployeeType type);

    // Count the number of given properity.
    inline int countBySex(Sex sex){
        return sex_num[sex];
    }
    int countByFaculty(const char* faculty);
    inline int countByType(EmployeeType type){
        return type_num[type];
    }
    inline int countByLevel(EmployeeTitle title){
        return title_num[title];
    }

    // Spread the list of faculties to the outer world.
    std::vector<const char*> getCurrentFaculties();
};

#endif
#pragma once
#include "employees.h"
#include "exceptions.h"

void Employees::add(Employee employee){
    // Check if the id of the new employee is not repeated.
    for (Employee i : employees){
        if (i.id == employee.id) throw RepeatedIdException(id);
    }
    employees.push_back(employee);
}

// For a GUI program there should not be a moment when the user delete a
// non-valid employee. So we regard it as an error here. But for a CLI program
// it somtimes is actually just an exception.
void Employees::del(unsigned int id){
    // Look if there is an id that matches the parameter. If yes, erase and
    // return.
    for (
        std::vector<Employee>::iterator i=employees.begin();
        i!=employees.end();
        i++
    ){
        if (i->id == id){
            employees.erase(i);
            return;
        }
    }

    // If not, throw an error.
    throw EmployeeNotFoundError(id);
}
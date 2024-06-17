#pragma once
#include "employees.h"
#include "exceptions.h"
#include <vector>

void Employees::add(Employee employee){
    // Check if the id of the new employee is not repeated.
    for (Employee i : employees){
        if (i.id == employee.id) throw RepeatedIdException(id);
    }
    employees.push_back(employee);

    // See if the container of faculties includes the new employee's.
    std::unordered_map<std::string, int>::iterator f_where =
        faculties.find(employee.faculty);
    // If it does not exist, add it into the container.
    if (f_where == faculties.end()){
        faculties[employee.faculty] = 1;
    }
    // If it does, increase it by 1.
    else{
        faculties[employee.faculty]++;
    }
}

// For a GUI program there should not be a moment when the user delete a
// non-valid employee. So we regard it as an error here. But for a CLI program
// it somtimes is actually just an exception.
void Employees::del(unsigned int id){
    // Look if there is an id that matches the parameter. If yes, erase and
    // return.
    for (
        std::vector<Employee>::iterator i = employees.begin();
        i!=employees.end();
        i++
    ){
        if (i->id == id){
            std::string faculty = i->faculty;
            employees.erase(i);

            // Manage the container of faculties, and decrease it by 1.
            // If it comes to 0 after the decrease, just delete it.
            if (faculties[faculty]<2) faculties.erase(faculty);
            else faculties[faculty]--;
            return;
        }
    }

    // If not, throw an error.
    throw EmployeeNotFoundError(id);
}

Employee* Employees::get(unsigned int id){
    for (
        std::vector<Employee>::iterator i = employees.begin();
        i!=employees.end();
        i++
    ){
        if (i->id == id){
            return &(*i);
        }
    }

    // If not, return NULL.
    return NULL;
}
#pragma once
#include "employees.h"
#include "exceptions.h"
#include <string>
#include <unordered_map>
#include <vector>

/* == Things about initializing == */

Employees::Employees(const char* db_path){
    
}

void Employees::initContainers(){
    // The vector of `Employee` objects.
    employees = std::vector<Employee>();

    // `faculty_num`. Leave it as blank.
    faculty_num = std::unordered_map<std::string, int>();

    // The following counters should be initialized as
    // container[every_enum_value] = 0.

    // `sex_num`.
    sex_num = std::unordered_map<Sex, int>();
    sex_num[Sex::male] = 0;
    sex_num[Sex::female] = 0;
    sex_num[Sex::others] = 0;

    // `type_num`.
    type_num = std::unordered_map<EmployeeType, int>();
    type_num[EmployeeType::faculty] = 0;
    type_num[EmployeeType::assistant] = 0;
    type_num[EmployeeType::staff] = 0;

    // `title.num`.
    title_num = std::unordered_map<EmployeeTitle, int>();
    title_num[EmployeeTitle::professor] = 0;
    title_num[EmployeeTitle::associateProfessor] = 0;
    title_num[EmployeeTitle::seniorLecturer] = 0;
    title_num[EmployeeTitle::lecturer] = 0;
    title_num[EmployeeTitle::teachingAssistant] = 0;
}

/* == CRUD operations == */

void Employees::add(Employee employee){
    // Check if the id of the new employee is not repeated.
    for (Employee i : employees){
        if (i.id == employee.id) throw RepeatedIdException(i.id);
    }
    employees.push_back(employee);

    // See if the counter of faculties includes the new employee's.
    std::unordered_map<std::string, int>::iterator f_where =
        faculty_num.find(employee.faculty);
    // If it does not exist, add it into the container.
    if (f_where == faculty_num.end()){
        faculty_num[employee.faculty] = 1;
    }
    // If it does, increase it by 1.
    else{
        faculty_num[employee.faculty]++;
    }

    // Increase the other counters.
    sex_num[employee.sex]++;
    type_num[employee.type]++;
    title_num[employee.title]++;
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
            // Manage the counter of faculties, and decrease it by 1.
            // If it comes to 0 after the decrease, just delete it.
            if (faculty_num[i->faculty]<2)
                faculty_num.erase(i->faculty);
            else faculty_num[i->faculty]--;

            // Decrease the other counters.
            sex_num[i->sex]--;
            type_num[i->type]--;
            title_num[i->title]--;

            employees.erase(i);
            return;
        }
    }

    // If not, throw an error.
    throw EmployeeNotFoundError(id);
}

std::vector<Employee>::iterator Employees::get(unsigned int id){
    for (
        std::vector<Employee>::iterator i = employees.begin();
        i!=employees.end();
        i++
    ){
        if (i->id == id){
            return i;
        }
    }

    // If nothing matches, return employees.end().
    return employees.end();
}

void Employees::setSex(std::vector<Employee>::iterator employee, Sex sex){
    sex_num[employee->sex]--;
    employee->sex = sex;
    sex_num[sex]++;
}

void Employees::setFaculty(
    std::vector<Employee>::iterator employee,
    const char* faculty
){
    // Decrease the precious faculty number.
    if (faculty_num[employee->faculty]<2)
        faculty_num.erase(employee->faculty);
    else faculty_num[employee->faculty]--;

    employee->faculty = std::string(faculty);

    // Increase the new faculty number.
    if (faculty_num.find(employee->faculty) == faculty_num.end())
        faculty_num[employee->faculty] = 1;
    else faculty_num[employee->faculty]++;
}

void Employees::setType(
    std::vector<Employee>::iterator employee,
    EmployeeType type
){
    type_num[employee->type]--;
    employee->type = type;
    type_num[type]++;
}

void Employees::setTitle(
    std::vector<Employee>::iterator employee,
    EmployeeTitle title
){
    title_num[employee->title]--;
    employee->title = title;
    title_num[title]++;
}

/* == Get lists that require that following needs == */
// TODO: Sorting is not considered now. It costs time.

bool Employees::contains(
    const std::string& long_str,
    const std::string& short_str
){
    return long_str.find(short_str) != std::string::npos;
}

std::vector<std::vector<Employee>::iterator>
    Employees::getById(unsigned int id)
{
    std::string id_str = std::to_string(id);
    std::vector<std::vector<Employee>::iterator> result =
        std::vector<std::vector<Employee>::iterator>();
    for (
        std::vector<Employee>::iterator i = employees.begin();
        i != employees.end();
        i++
    ){
        if(contains(std::to_string(i->id), id_str))
            result.push_back(i);
    }
    return result;
}

std::vector<std::vector<Employee>::iterator> Employees::getByName(char* name)
{
    std::string name_str = std::string(name);
    std::vector<std::vector<Employee>::iterator> result =
        std::vector<std::vector<Employee>::iterator>();
    for (
        std::vector<Employee>::iterator i = employees.begin();
        i != employees.end();
        i++
    ){
        if(contains(i->name, name_str))
            result.push_back(i);
    }
    return result;
}

std::vector<std::vector<Employee>::iterator> Employees::getBySex(Sex sex){
    std::vector<std::vector<Employee>::iterator> result =
        std::vector<std::vector<Employee>::iterator>();
    for(
        std::vector<Employee>::iterator i = employees.begin();
        i != employees.end();
        i++
    ){
        if (i->getSex() == sex) result.push_back(i);
    }
    return result;
}

std::vector<std::vector<Employee>::iterator>
    Employees::getByType(EmployeeType type)
{
    std::vector<std::vector<Employee>::iterator> result =
        std::vector<std::vector<Employee>::iterator>();
    for(
        std::vector<Employee>::iterator i = employees.begin();
        i != employees.end();
        i++
    ){
        if (i->getType() == type) result.push_back(i);
    }
    return result;
}

/* == Counters == */
// Considering the complexity of logic, only `countByFaculty` is not an 
// inline method here.

int Employees::countByFaculty(char* faculty){
    std::string faculty_str = std::string(faculty);
    // If the faculty is not fount on the counter, return 0.
    if (faculty_num.find(faculty_str)==faculty_num.end())
        return 0;
    // Else, return its actual number.
    return faculty_num[faculty_str];
}

std::vector<const char*> Employees::getCurrentFaculties(){
    std::vector<const char*> result =
        std::vector<const char*>();
    for (std::pair<std::string, int> i : faculty_num){
        result.push_back(i.first.c_str());
    }
    return result;
}
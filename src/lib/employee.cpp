#pragma once
#include "employee.h"

Employee::Employee(
    unsigned long id,
    char* name,
    enum Sex sex,
    enum EmployeeType type,
    char* faculty,
    char* major,
    enum EmployeeTitle title
){
    this->id = id;
    this->name = std::string(name);
    this->sex = sex;
    this->type = type;
    this->faculty = std::string(faculty);
    this->major = std::string(major);
    this->title = title;
}
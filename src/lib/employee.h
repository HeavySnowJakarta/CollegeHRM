// This file defines the structure of a person.
#pragma once
#include <string>

// An employee includes the infomation of id, name, sex, type, faculty, major,
// title, etc. So let's define some enums here.
enum Sex{
    Male,
    Female,
    Others
};

enum EmployeeType{
    Faculty,
    Assistant,
    Staff
};

enum EmployeeTitle{
    Professor,
    AssociateProfessor,
    SeniorLecturer,
    Lecturer,
    TeachingAssistant
};

// The main character of this file.
struct Employee{
    unsigned long id;
    std::string name;
    enum Sex sex;
    enum EmployeeType type;
    std::string faculty;
    std::string major;
    enum EmployeeTitle title;
};
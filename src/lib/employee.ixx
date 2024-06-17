// This file defines the structure of a person.
module;
#include <string>
export module employee;

// An employee includes the infomation of id, name, sex, type, faculty, major,
// title, etc. So let's define some enums here.
export enum Sex{
    Male,
    Female,
    Others
};

export enum EmployeeType{
    Faculty,
    Assistant,
    Staff
};

export enum EmployeeTitle{
    Professor,
    AssociateProfessor,
    SeniorLecturer,
    Lecturer,
    TeachingAssistant
};

// The main character of this file.
export struct Person{
    unsigned long id;
    std::string name;
    enum Sex sex;
    enum EmployeeType type;
    std::string faculty;
    std::string major;
    enum EmployeeTitle title;
};
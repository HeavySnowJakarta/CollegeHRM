// This file defines the structure of a person.
#pragma once
#include <string>

// An employee includes the infomation of id, name, sex, type, faculty, major,
// title, etc. So let's define some enums here.
enum Sex{
    male,
    female,
    others
};

enum EmployeeType{
    faculty_type,
    assistant,
    staff
};

enum EmployeeTitle{
    professor,
    associateProfessor,
    seniorLecturer,
    lecturer,
    teachingAssistant
};

// We have to maintain a list of employees, where we may sort or filter the
// list by some kinds of properities, and that's why we need another enum
// here.
enum EmployeeProperity{
    id,
    name,
    sex,
    type,
    faculty_prop,
    title
};

// The main character of this file.
struct Employee{
// As there is almost no limits to revise the infomation of an employee, I
// keep all of them to be public.
public:
    unsigned long id;
    std::string name;
    enum Sex sex;
    enum EmployeeType type;
    std::string faculty;
    std::string major;
    enum EmployeeTitle title;

    // but there will be no default constructor to generate a null employee.
    Employee(
        unsigned long id,
        char* name,
        enum Sex sex,
        enum EmployeeType type,
        char* faculty,
        char* major,
        enum EmployeeTitle title
    );
};
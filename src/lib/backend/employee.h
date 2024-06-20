// This file defines the structure of a person.
#ifndef _EMPLOYEE
#define _EMPLOYEE


#include <string>
class Employees; // The friend class of `Employee`.

// An employee includes the infomation of id, name, sex, type, faculty, major,
// title, etc. So let's define some enums here.
enum class Sex{
    male,
    female,
    others
};

enum class EmployeeType{
    faculty,
    assistant,
    staff
};

enum class EmployeeTitle{
    professor,
    associateProfessor,
    seniorLecturer,
    lecturer,
    teachingAssistant
};

// We have to maintain a list of employees, where we may sort or filter the
// list by some kinds of properities, and that's why we need another enum
// here.
enum class EmployeeProperity{
    id,
    name,
    sex,
    type,
    faculty,
    title
};

// The main character of this file.
struct Employee{
// We will have to power tables to count the number of the same of some
// properities, so some of the fields should not be revised optionally.
// Instead the array of employees will provide methods to achieve that.
private:
    enum Sex sex;
    std::string faculty;
    enum EmployeeType type;
    enum EmployeeTitle title;

// The others would make no trouble even if they are public,
public:
    unsigned long id;
    std::string name;
    // TODO: This should not be public!
    std::string major;

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

    // Get the restricted properities.
    Sex getSex();
    const char* getFaculty();
    EmployeeType getType();
    EmployeeTitle getTitle();

    // To set the four fields, you have to use methods provided by
    // `Employees`.

    // class `Employees` should control the `employee` objects completely.
    friend class Employees;

    // Convert into JSON string.
    const char* toJson();

    // Get the `Employee` object from the JSON string.
    static Employee fromJson(const char* json_str);
};

#endif
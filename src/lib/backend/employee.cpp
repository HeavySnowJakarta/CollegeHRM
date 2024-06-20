#pragma once
#include "employee.h"

#include "cjson/cJSON.h"
#include <string>

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

Sex Employee::getSex(){
    return sex;
}

const char* Employee::getFaculty(){
    return faculty.c_str();
}

EmployeeType Employee::getType(){
    return type;
}

EmployeeTitle Employee::getTitle(){
    return title;
}

const char* Employee::toJson(){
    cJSON* json_obj = cJSON_CreateObject();

    // Id and name.
    cJSON_AddNumberToObject(json_obj, "id", id);
    cJSON_AddStringToObject(json_obj, "name", name.c_str());
    // Sex.
    std::string sex_str;
    switch (sex){
    case Sex::male:
        sex_str = "male";
        break;
    case Sex::female:
        sex_str = "female";
        break;
    case Sex::others:
        sex_str = "others";
    }
    cJSON_AddStringToObject(json_obj, "sex", sex_str.c_str());
    // Type.
    std::string type_str;
    switch (type){
    case EmployeeType::faculty:
        type_str = "faculty";
        break;
    case EmployeeType::assistant:
        type_str = "assistant";
        break;
    case EmployeeType::staff:
        type_str = "staff";
    }
    cJSON_AddStringToObject(json_obj, "type", type_str.c_str());
    // Faculty and major.
    cJSON_AddStringToObject(json_obj, "faculty", faculty.c_str());
    cJSON_AddStringToObject(json_obj, "major", major.c_str());
    // Title.
    std::string title_str;
    switch (title){
    case EmployeeTitle::professor:
        title_str = "professor";
        break;
    case EmployeeTitle::associateProfessor:
        title_str = "associateProfessor";
        break;
    case EmployeeTitle::seniorLecturer:
        title_str = "senoirLecturer";
        break;
    case EmployeeTitle::lecturer:
        title_str = "lecturer";
        break;
    case EmployeeTitle::teachingAssistant:
        title_str = "teachingAssistant";
    }
    cJSON_AddStringToObject(json_obj, "title", title_str.c_str());

    char* result = cJSON_Print(json_obj);
    cJSON_Delete(json_obj);
    return result;
}

Employee Employee::fromJson(const char *json_str){
    
}
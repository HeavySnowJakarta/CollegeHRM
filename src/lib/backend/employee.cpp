#pragma once
#include "employee.h"

#include "cjson/cJSON.h"
#include <string>
#include <cstring>

#include "exceptions.h"

Employee::Employee(
    unsigned long id,
    const char* name,
    enum Sex sex,
    enum EmployeeType type,
    const char* faculty,
    const char* major,
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
    cJSON* json_obj = cJSON_Parse(json_str);
    if (json_obj == NULL)
        throw DatabaseBrokenException(DatabaseBrokenType::failedToParse);

    cJSON* id_json = cJSON_GetObjectItem(json_obj, "id");
    cJSON* name_json = cJSON_GetObjectItem(json_obj, "name");
    cJSON* sex_json = cJSON_GetObjectItem(json_obj, "sex");
    cJSON* type_json = cJSON_GetObjectItem(json_obj, "type");
    cJSON* faculty_json = cJSON_GetObjectItem(json_obj, "faculty");
    cJSON* major_json = cJSON_GetObjectItem(json_obj, "major");
    cJSON* title_json = cJSON_GetObjectItem(json_obj, "title");

    unsigned long id;
    std::string name;
    Sex sex;
    EmployeeType type;
    std::string faculty;
    std::string major;
    EmployeeTitle title;

    if (cJSON_IsNumber(id_json)) id = id_json->valueint;
    else throw DatabaseBrokenException(
        DatabaseBrokenType::unexpectedString
        // (std::string("Found id: ")+std::to_string(id)).c_str()
    );

    if (cJSON_IsString(name_json)) name = name_json->valuestring;
    else throw DatabaseBrokenException(DatabaseBrokenType::unexpectedString);

    if (cJSON_IsString(sex_json)){
        if (strcmp(sex_json->valuestring, "male") == 0)
            sex = Sex::male;
        else if (strcmp(sex_json->valuestring, "female") == 0)
            sex = Sex::female;
        else if (strcmp(sex_json->valuestring, "others") == 0)
            sex = Sex::others;
        else throw DatabaseBrokenException(
            DatabaseBrokenType::unexpectedString,
            (std::string("Found sex ") + std::string(sex_json->valuestring))
                .c_str()
        );
    }
    else throw DatabaseBrokenException(DatabaseBrokenType::unexpectedString);

    if (cJSON_IsString(type_json)){
        if ((strcmp(type_json->valuestring, "faculty") == 0)){
            type = EmployeeType::faculty;
        }
        else if ((strcmp(type_json->valuestring, "assistant") == 0)){
            type = EmployeeType::assistant;
        }
        else if ((strcmp(type_json->valuestring, "staff") == 0)){
            type = EmployeeType::staff;
        }
        else throw DatabaseBrokenException(
            DatabaseBrokenType::unexpectedString,
            (std::string("Found employee type ") + std::string(type_json->valuestring))
                .c_str()
        );
    }
    else throw DatabaseBrokenException(DatabaseBrokenType::unexpectedString);

    if (cJSON_IsString(title_json)){
        if ((strcmp(title_json->valuestring, "professor") == 0)){
            title = EmployeeTitle::professor;
        }
        else if ((strcmp(title_json->valuestring, "associateProfessor") == 0)){
            title = EmployeeTitle::associateProfessor;
        }
        else if ((strcmp(title_json->valuestring, "seniorLecturer") == 0)){
            title = EmployeeTitle::seniorLecturer;
        }
        else if ((strcmp(title_json->valuestring, "lecturer") == 0)){
            title = EmployeeTitle::lecturer;
        }
        else if ((strcmp(title_json->valuestring, "teachingAssistant") == 0)){
            title = EmployeeTitle::teachingAssistant;
        }
        else throw DatabaseBrokenException(
            DatabaseBrokenType::unexpectedString,
            (std::string("Found employee title ") + std::string(title_json->valuestring))
                .c_str()
        );
    }
    else throw DatabaseBrokenException(DatabaseBrokenType::unexpectedString);

    if (cJSON_IsString(faculty_json)) faculty = faculty_json->valuestring;
    else throw DatabaseBrokenException(DatabaseBrokenType::unexpectedString);

    if (cJSON_IsString(major_json)) major = major_json->valuestring;
    else throw DatabaseBrokenException(DatabaseBrokenType::unexpectedString);

    return Employee(
        id, name.c_str(), sex, type, faculty.c_str(), major.c_str(), title
    );
}
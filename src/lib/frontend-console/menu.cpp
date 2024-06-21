#include "menu.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cjson/cjson.h"
// TODO: Use custom objects to express `std::cout` and `std::cin`.

#include "clear_screen.h"
#include "../backend/exceptions.h"

Menu::Menu(){}

// This function runs the remained parts of the program.
int Menu::run(){
    // The start of the program.
    clearScreen();
    std::cout << "College Human Resource Manager\n";
    std::cout << "Provide your database path (it's suggested to end with .dat). If the file does not exist, the database will be created automatically.\n";
    std::cout << "Provide your path: ";

    std::cin >> db_path;
    load();

    return loop();
}

Employees Menu::load(){
    // Open the file.
    std::ifstream db_input;
    std::string file_content;
    db_input.open(db_path.c_str(), 'r');
    db_input >> file_content;
    db_input.close();

    // Parse the file and see if it's valid.
    cJSON* db_json_obj = cJSON_Parse(file_content.c_str());
    if (db_json_obj == NULL || !cJSON_IsArray(db_json_obj)) {
        createDatabase();
    }

    // Else, load from the database.
    std::vector<Employee> load_results;
    try{
        int list_size = cJSON_GetArraySize(db_json_obj);
        for (int i=0; i<list_size; i++){
            Employee load_result = Employee(
                cJSON_Print(cJSON_GetArrayItem(db_json_obj, i))
            );
            load_results.push_back(load_result);
        }
        employees = Employees(load_results);

        return employees;
    }
    catch(DatabaseBrokenException e){
        std::cout << "Error while reading from the database. Here is the msg: ";
        std::cout << e.what() << "\n";
    }
}

void Menu::createDatabase(){
    std::cout << "Invalid database. Gonna create a database for you.\n";
    std::cout << "If the precious database exists, it'll be cleared.\n";
    std::ofstream emptyDbCreator;
    emptyDbCreator.open(db_path.c_str(), 'w');
    emptyDbCreator << "";
    emptyDbCreator.close();

    // Employees will be empty.
    employees = Employees();
}

int Menu::loop(){
    char input;

    clearScreen();
    std::cout << "Operation Menu\n";
    std::cout << "========= ====\n";
    std::cout << "\n";

    std::cout << "a) Add a new employee\n";
    std::cout << "b) Find an employee\n";
    std::cout << "c) Delete an employee\n";
    std::cout << "d) Revise an employee\n";
    std::cout << "e) Stat the number\n";
    std::cout << "f) Exit the system\n";
    std::cout << "\n";

    std::cout << "Input your chioce: ";
    std::cin >> input;

    switch (input){
    case 'a':
        add();
        break;
    case 'b':
        find();
        break;
    case 'c':
        del();
        break;
    case 'd':
        revise();
        break;
    case 'e':
        stat();
        break;
    case 'f':
        return 0;
    default:
        std::cout << "Invalid input. Press any key to continue.";
        std::cin.get();
    }

    return loop();
}

void Menu::add(){
    std::string input;
    unsigned long id;
    std::string name;
    Sex sex;
    EmployeeType type;
    std::string faculty;
    std::string major;
    EmployeeTitle title;

    std::cout << "Input the id: ";
    std::cin >> input;
    id = std::stoul(input);

    std::cout << "Input the name: ";
    std::cin >> input;
    name = input;

    std::cout << "Input the sex. We accept 'male', 'female' or 'others': ";
    std::cin >> input;
    if (input == "male") sex = Sex::male;
    else if (input == "female") sex = Sex::female;
    else if (input == "others") sex = Sex::others;
    else {
        std::cout << "Invalid sex. Press any key to continue.";
        std::cin.get();
        return;
    }

    std::cout << "Input the type. We accept 'faculty', 'assistant' or 'staff': \n";
    std::cin >> input;
    if (input == "faculty") type = EmployeeType::faculty;
    else if (input == "assistant") type = EmployeeType::assistant;
    else if (input == "staff") type = EmployeeType::staff;
    else{
        std::cout << "Invalid faculty. Press any key to continue.";
        std::cin.get();
        return;
    }

    std::cout << "Input the faculty: ";
    std::cin >> input;
    faculty = input;

    std::cout << "Input the major: ";
    std::cin >> input;
    major = input;

    std::cout << "Press the title, we accept 'professor', 'associateProfessor', 'seniorLecturer', 'lecturer' and 'teachingAssistant': ";
    std::cin >> input;
    if (input == "professor") title = EmployeeTitle::professor;
    else if (input == "associateProfessor") title = EmployeeTitle::associateProfessor;
    else if (input == "seniorLecturer") title = EmployeeTitle::seniorLecturer;
    else if (input == "lecturer") title = EmployeeTitle::lecturer;
    else if (input == "teachingAssistant") title = EmployeeTitle::teachingAssistant;
    else {
        std::cout << "Invalid title. Press any key to continue.";
        std::cin.get();
        return;
    }

    try{
        employees.add(Employee(
            id, name.c_str(), sex, type, faculty.c_str(),
            major.c_str(), title
        ));
    }
    catch (RepeatedIdException e){
        std::cout << "Id is repeated: " << id
            << ". Press any key to continue.";
        std::cin.get();
        return;
    }

    save();
}

void Menu::del(){
    std::string input;
    unsigned long id;
    std::cout << "Input the id you want to delete: ";
    std::cin >> input;
    id = std::stoul(input);

    try{
        employees.del(id);
    }
    catch (EmployeeNotFoundError e){
        std::cout << "Cannot find employee " << input
            << ". Press any key to continue: ";
        std::cin.get();
        return;
    }

    save();
}

void Menu::revise(){
    clearScreen();
    char selection;
    std::string input;
    unsigned long id;
    std::vector<Employee>::iterator employee;

    // Get the pointer to the employee to revise.
    std::cout << "Input the id of the employee you want to revise:";
    std::cin >> input;
    id = std::stoul(input);
    employee = employees.get(id);
    // See if the employee is valid.
    if (employee == employees.getEnd()){
        std::cout << "Cannot find the employee. Press any key to continue.";
        std::cin.get();
        return;
    }

    std::cout << "Select the item you want to revise:\n";
    std::cout << "a) id\n";
    std::cout << "b) name\n";
    std::cout << "c) sex\n";
    std::cout << "d) type\n";
    std::cout << "e) faculty\n";
    std::cout << "f) major\n";
    std::cout << "g) title\n";
    std::cout << "\n";
    std::cout << "Input your choice: ";

    std::cin >> selection;
    switch(selection){
    case 'a':
        std::cout << "Input the new id: ";
        std::cin >> input;
        id = std::stoul(input);
        // TODO: See if the id is repeated.
        employee->id = id;
        break;
    case 'b':
        std::cout << "Input the new name: ";
        std::cin >> input;
        employee->name = input;
        break;
    case 'c':
        std::cout << "Input the sex. We accept 'male', 'female' or 'others': ";
        std::cin >> input;
        if (input == "male") employees.setSex(employee, Sex::male);
        else if (input == "female")
            employees.setSex(employee, Sex::female);
        else if (input == "others")
            employees.setSex(employee, Sex::others);
        else{
            std::cout << "Invalid sex. Press any key to continue.";
            std::cin.get();
            return;
        }
        break;
    default:
            std::cout << "Invalid input. Press any key to continue.";
            std::cin.get();
            return;
    }
}

void Menu::find(){
    std::string input;
    std::vector<Employee>::iterator employee;
    std::cout << "Input the id of the employee:\n";
    std::cin >> input;
    unsigned long id;
    id = std::stoul(input);
    employee = employees.get(id);

    std::cout << "Name: " << employee->name;
    std::cout << "Faculty: " << employee->getFaculty();
    std::cout << "major" << employee->major;
}

void Menu::stat(){
    std::cout << "Here are the stat data:\n";

    // Stat by sex.
    std::cout << "by sex:\n";
    std::cout << "    Male: " << employees.countBySex(Sex::male) << '\n';
    std::cout << "    Female: " << employees.countBySex(Sex::female) << '\n';
    std::cout << "    Others: " << employees.countBySex(Sex::others) << '\n';

    // Stat by faculty.
    std::cout << "By facluty:\n";
    for (const char* i : employees.getCurrentFaculties()){
        std::cout << i << ": " << employees.countByFaculty(i);
    }


}

void Menu::save(){
    // Get the JSON string of the employees.
    cJSON* json_obj = cJSON_CreateArray();
    std::ofstream db_saver;
    std::string json_str;
    for (
        std::vector<Employee>::iterator i = employees.getBegin();
        i != employees.getEnd();
        i++
    ){
        cJSON_AddItemToArray(json_obj, cJSON_Parse(i->toJson()));
    }
    json_str = cJSON_Print(json_obj);

    // Save the file.
    db_saver.open(db_path, 'w');
    db_saver << json_str;
    db_saver.close();
}
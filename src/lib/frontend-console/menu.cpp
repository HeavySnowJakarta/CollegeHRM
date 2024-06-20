#include "menu.h"

#include <iostream>
#include <fstream>
// TODO: Use custom objects to express `std::cout` and `std::cin`.

#include "cjson/cjson.h"
#include "clear_screen.h"

Menu::Menu(){
    // The start of the program.
    clearScreen();
    std::cout << "College Human Resource Manager\n";
    std::cout << "Provide your database path (it's suggested to end with .dat). If the file does not exist, the database will be created automatically.\n";
    std::cout << "Provide your path: ";

    std::cin >> db_path;
}

Employees Menu::load(){
    // Open the file.
    std::ifstream db_input;
    std::string file_content;
    db_input.open(db_path.c_str(), 'r');
    db_input >> file_content;

    // Parse the file and see if it's valid.
    cJSON* db_json_obj = cJSON_Parse(file_content.c_str());
    if (db_json_obj == NULL) noticeCreation();
}

void Menu::noticeCreation(){
    std::cout << "Invalid database. Gonna create a database for you.\n";
}
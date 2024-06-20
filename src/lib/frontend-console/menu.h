// The file to manage the console menu.

#include "../backend/employees.h"

#include <fstream>

class Menu{
private:
    // File operations.
    std::string db_path;

    Employees employees;

    // A basic operation, let the user to input and do the command.
    void operate();

    // Load the database from the file.
    Employees load();

    // Tell the user the database has been created.
    // Run when the database is not valid.
    void noticeCreation();

public:
    // Let the user create or open a database.
    Menu();

    // Run and return the result value (for the whole program).
    int run();
};
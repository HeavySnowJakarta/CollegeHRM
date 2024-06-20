// The file to manage the console menu.

#include "../backend/employees.h"

class Menu{
private:
    Employees employees;

    // A basic operation, let the user to input and do the command.
    void operate();

public:
    // Let the user create or open a database.
    Menu();

    // Run and return the result value (for the whole program).
    int run();
};
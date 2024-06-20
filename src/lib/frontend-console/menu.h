// The file to manage the console menu.

#include "../backend/employees.h"

class Menu{
private:
    Employees employees;

public:
    // Let the user create or open a database.
    Menu();

    // A basic operation, let the user to input and do the command.
    void operate();
};
// The file to manage the console menu, as well as file storation managing.

#include "../backend/employees.h"

class Menu{
private:
    // File operations.
    std::string db_path;
    Employees employees;

    /* Basic flow paths. */

    // Let the user to input and do the command.
    int loop();

    // Load the database from the file.
    Employees load();

    // Tell the user the database has been created.
    // Run when the database is not valid.
    void createDatabase();

    /* Single operations */
    void add();
    void del();
    void revise();
    void find();
    void stat();
    void save();

public:
    // Let the user create or open a database.
    Menu();

    // Run and return the result value (for the whole program).
    int run();
};
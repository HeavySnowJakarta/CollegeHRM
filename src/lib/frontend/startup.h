// This file is used to descibe the logic when the program starts.
// There are two operations of the startup screen: create a new database
// and open an existing database.

#pragma once
#include <QString>

class Startup{
private:
    // Open the page of operations after opening the database.
    static void openNewWindow(QString db_path);

public:
    // Create a new database. Corresponding to the button `New`.
    static void create();

    // Open an existing database. Corresponding to the button `Open`.
    static void open();
};
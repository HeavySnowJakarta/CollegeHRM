// This file is used to descibe the logic when the program starts.
// There are two operations of the startup screen: create a new database
// and open an existing database.

class Startup{
public:
    // Create a new database. Corresponding to the button `New`.
    static void create();

    // Open an existing database. Corresponding to the button `Open`.
    static void open();
};
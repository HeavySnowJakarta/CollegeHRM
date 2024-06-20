#include "menu.h"

#include <iostream>
// TODO: Use custom objects to express `std::cout` and `std::cin`.

#include "clear_screen.h"

Menu::Menu(){
    clearScreen();
    std::cout << "College Human Resource Manager\n";
    std::cout << "a) Create a new database\n";
    std::cout << "b) Open an existing database\n";
    std::cout << "\n";
    std::cout << "Input your choice: ";

    char input;
    std::cin >> input;

    switch (input){

    }
}
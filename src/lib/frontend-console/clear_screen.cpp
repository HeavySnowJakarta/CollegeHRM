#include "clear_screen.h"

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
    #include <term.h>
#endif

void clearScreen(){
#ifdef _WIN32
    // Windows system.
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = {0, 0};    // Home cursor position
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    // Get the number of character cells in the current buffer.
    if(!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }
    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks.
    if(!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten)) {
        return;
    }

    // Get the current text attribute.
    if(!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }

    // Set the buffer's attributes accordingly.
    if(!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten)) {
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hConsole, coordScreen);
#else
    // Unix-based system.
    if (!cur_term) {
        int result;
        setupterm(NULL, STDOUT_FILENO, &result);
        if (result <= 0) return;
    }

    putp(tigetstr("clear"));
#endif
}
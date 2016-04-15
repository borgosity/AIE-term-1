#include <iostream>
#include <Windows.h>

#include "Console.h"

/******************************************************************************
*******************************************************************************/
void main()
{
    // Instantiate a console object with a specified window size and position
    // Console console(10, 10, 40, 20);

    // Instantiate a console object with a full-screen window
    Console console;

    // Write characters at various X,Y positions
    console.write(39, 0, 'x');
    console.write(10, 10, 'a');
    console.write(11, 10, 'x', 20);
    console.write(21, 18, 'y', 20);

    // Write a character at the right-hand edge of the screen
    console.write(console.width() - 1, 10, 'a');

    // This is a hack to get the default "Press any key to continue..." message 
    // to appear at teh bottom of the full screen (we just output new lines for
    // the height of the screen).
    for (int i = 0; i < console.height(); i++)
    {
        std::cout << "\n";
    }
}
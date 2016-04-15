#pragma once

#include <Windows.h>



/******************************************************************************
This is a basic wrrapper around the WIndows console that provides some 
additional functionality, e.g.:
    - Full screen
    - Writing to specific locations on the screen
    - Clearing the screen
*******************************************************************************/
class Console
{
public:
    Console(int x, int y, int width, int height);
    Console();
    ~Console();

    //bool setFullScreen();

    //bool setWindowed(int x, int y, int width, int height);

    void write(int xPos, int yPos, char character, int numCharacters = 1);

    void clearScreen();

    const int width() const;

    const int height() const;

private:
    HANDLE m_hScreenBuffer;
    int m_width;
    int m_height;

    bool setFullScreen();
    bool setWindowed(int x, int y, int width, int height);
};


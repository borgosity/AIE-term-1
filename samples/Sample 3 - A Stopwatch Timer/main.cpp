#include "Timer.h"
#include <iostream>
#include <conio.h>




/******************************************************************************
This program demonstrates the use of an object-based timer.
*******************************************************************************/
void main()
{
	std::cout << "Press any key to restart the clock or ESC to quit:\n\n";

	Timer myTimer;

	myTimer.start();

	while (_getch() != 27)
	{
		std::cout << myTimer.elapsed() << " seconds\n";
		myTimer.start();
	}

	std::cout << "\n";
}
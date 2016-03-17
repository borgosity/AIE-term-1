#include "Error.h"
#include <iostream>



/******************************************************************************
*******************************************************************************/
void Error::fatal(const std::string & message)
{
	std::cout << "\n\n**** FATAL FAILURE ****  " << message << "\n\nProgram aborted!\n\n";

	exit(0);
}

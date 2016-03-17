#pragma once

#include <string>
#include <sstream>



// This is a convenience macro to streamline error reporting, particularly where 
// you want to output some diagnostic values with your error message. You can
// stream any number of values into an error message using the standard streaming
// operator '<<'. For example:
//		int age = 12;
//		if(age < 16)
//			FATAL_ERROR( age << "is too young to play this game!" );
#define FATAL_ERROR(stream_)				\
{											\
	std::ostringstream oss_;				\
	oss_ << stream_;						\
	Error::fatal(oss_.str());				\
}



/******************************************************************************
'Error' is the program-wide error handler. It is a singleton.
*******************************************************************************/
class Error
{
public:

	// Fail the application with an appropriate error message.
	static void fatal(const std::string & message);

private:
	Error() {}
	~Error() {}
};


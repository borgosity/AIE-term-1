#pragma once

#include <Windows.h>



/******************************************************************************
'Timer' is a simple stop-watch timer built over the top of the Windows 
high-performance counter. This provides micro-second precision, considerably 
better than other timing functions, e.g. the Windows GetTickCount() timing 
function only has millisecond accuracy. 
The Timer has a total size of 24 bytes, so is quite cheap to add as a member
of other objects that require timing functionality.
*******************************************************************************/
class Timer
{
public:
	Timer();
	~Timer();

	// Start the timer. Note that the timer doesn't actually do anything while
	// it is actually running. The only overhead occurs when you call 'start' or
	// 'elapsed'. This means that you can have thousands of Timers 'running' 
	// simultaneously with no performance hit.
	void start();

	// Returns the time elapsed (in seconds) since the Timer was started. If this
	// is called before starting the Timer, it will return zero.
	double elapsed() const;

private:
	LARGE_INTEGER m_frequency, m_startTime;
	bool m_started;
};


#include "Timer.h"
#include <exception>



/******************************************************************************
*******************************************************************************/
Timer::Timer() : m_started(false)
{
	if (::QueryPerformanceFrequency(&m_frequency) == FALSE)
	{
		throw std::exception("No high performance counter available");
	}
}

/******************************************************************************
*******************************************************************************/
Timer::~Timer()
{
}

/******************************************************************************
*******************************************************************************/
double Timer::elapsed() const
{
	LARGE_INTEGER timeNow;
	if (::QueryPerformanceCounter(&timeNow) == FALSE)
	{
		throw std::exception("No high performance counter available");
	}

	if (m_started)
	{
		return static_cast<double>(timeNow.QuadPart - m_startTime.QuadPart) / m_frequency.QuadPart;
	}
	else
	{
		return 0;
	}
}

/******************************************************************************
*******************************************************************************/
void Timer::start()
{
	if (::QueryPerformanceCounter(&m_startTime) == FALSE)
	{
		throw std::exception("No high performance counter available");
	}

	m_started = true;
}

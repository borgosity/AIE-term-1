#pragma once


// 'NonCopyable' represents an object that cannot be copied. All classes
// derived from this base class will generate a compile error when copied
// (rather than a run-time failure).
//
// Hiding the copy constructor and assignment operator means that the 
// compiler will catch any attempt at copying.
class NonCopyable
{
public:

    NonCopyable() {}

private:

	NonCopyable(const NonCopyable & other) {}
	void operator=(const NonCopyable & other) {}
};


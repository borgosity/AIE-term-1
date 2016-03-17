#pragma once



/******************************************************************************
'NonCopyable' is an old C++ trick to prevent the compiler (or you) from copying
any class a class derived from NonCopyable (either accidentally or on purpose).
You would usually make a class NonCopyable if it has complex inner resources 
(e.g. pointers) that you DON'T want to allocate more than once (as would happen 
if the class was copied).
*******************************************************************************/
class NonCopyable
{
public:
	NonCopyable() {}
	~NonCopyable() {}

private:

	// The copy constructor and overloaded assignment operator together are 
	// what normally makes object copyable. Because these are private, a
	// compile error will occur whenever an attempt is made to copy any class
	// derived from 'NonCopyable'.
    NonCopyable(const NonCopyable & other) {}
    NonCopyable & operator=(const NonCopyable & other) {}
};


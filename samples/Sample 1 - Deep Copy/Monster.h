#pragma once

#include "Gun.h"
#include "NonCopyable.h"
#include <string>



class Monster : public NonCopyable
{
public:
	Monster(const std::string & name);
	~Monster();

	// Provide both a copy constructor and an assignment operator to
	// make the class deep-copyable. Without doing this, copying a
	// Monster object will crash the heap.
//    Monster(const Monster & other);
//    Monster & operator=(const Monster & other);

    // Return the monster's gun
	Gun & gun() const;

private:
    std::string m_name;
	Gun *m_gun;

    void copy(const Monster & other);
};

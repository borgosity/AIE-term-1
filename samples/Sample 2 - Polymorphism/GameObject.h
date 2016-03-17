#pragma once



/******************************************************************************
'GameObject' is the base-class from which all other game object classes derive.
*******************************************************************************/
class GameObject
{
public:

protected:

	// We make the constructor 'protected' so that only the Factory can make 
	// new game objects. To achieve this, we need to make the Factory class a
	// 'friend' of the GameObject class so that the Factory can access the 
	// proected constructor (and destructor).
	GameObject();
	friend class Factory;

	// Note the 'virtual' destructor! This is NECESSARY for base classes (i.e. classes
	// that will be inherited from 'GameObject') to prevent memory leaks. You 
	// don't need to repeat the 'virtual' keyword in the derived classes (which will 
	// automatically 'inherit' the virtual destructor from the base class), 
	// but it's probably good practice to do so for readability.
	virtual ~GameObject();
};


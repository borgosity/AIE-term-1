#pragma once

#include <exception>
#include <sstream>



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Macros
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// The error-handling macros given here would probably not appear in a Dynamic
// Array class in 'real life', but would more likely be tucked  away in some
// sort of error-handling component. But these are here to illustrate the 
// usefulness of macros (used judiciously), and the importance of robust
// error handling in a C++ application (given all the things that can go wrong).
// These macros are designed to be short and very easy to use so that can be
// sprinkled liberally throughout the code without the clutter of in-line
// error-handling.


// This macro 'asserts' that some specified boolean condition must be true, 
// that is a condition that would otherwise result in a fatal failure of the 
// application. If the condition is false, we throw an exception (which will 
// 'land' out at the nearest 'catch' clause - see 'main.cpp').
#define MY_ASSERT( any_boolean_condition_ )                             \
{                                                                       \
if (!(any_boolean_condition_))                                          \
	{                                                                   \
	std::ostringstream oss;                                             \
	oss << "Assertion failure: " << __FILE__ << ", line " << __LINE__;  \
	throw std::exception(oss.str().c_str());                            \
	}                                                                   \
}

// This macro checks that the heap has not become corrupt (always a possibility
// with C++).
#define MY_HEAP_CHECK( pointer_ )    if ((pointer_) == 0) throw std::exception("Memory failure");



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// DynamicArray
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
'Dynamic Array' is a template for arrays that can expand automatically when 
items are added (using the heap). Because it is a template, the compiler requires 
all of the code to appear in the same file (i.e. no sepaate cpp file allowed).
However, we can still separate the functions into prototypes and implementations
as long as they appear in the same file. We do that here to make the class 
definition more readable.
*******************************************************************************/
template< typename T_ >
class DynamicArray
{
public:

    // 'growSize' is the number of elemnts by which the array expands when it
    // runs out of memory. Note the use of the 'optional argument' which will
    // automatically supply the specified value if the caller doesn't supply
    // one (this feature has only recently been introduced into C#).
    DynamicArray(int growSize = 100);

    ~DynamicArray();

    // Add a single element to the array. The array will expand automatically
    // by the specified grow size if it runs out of memory.
    void add(const T_ & element);

    // Return the number of elements currently in the array
    int size() const;

    // Get the 'index'th element of the array. Note that this returns a non-const
    // reference to the element, so the returned element can be modified. 
	// Throws an exception if 'index' is out of range.
    T_ & get(int index);

    // Overloaded operator to access the elements via '[]'. Throws an exception 
	// if 'index' is out of range.
    T_ & operator[](int index);

    // A copy constructor and overloaded assignment operator is required to
    // make 'DynamicArray' fully copyable, i.e. 'deep' copyable. If we didn't
    // do this, the class would only be 'shallow' copyable, meaning that 
    // each time we copy a DynamicArray, each of their 'm_array' members would 
    // all point to the same block of memory, resulting in multiple deletions
    // of the same pointer (causing heap corruption).
    DynamicArray(const DynamicArray & other);
    DynamicArray & operator=(const DynamicArray & other);

private:

    // This is the array itself, i.e. a pointer to T_ (which becomes an array
    // of T_ when we allocate memory for multiple elements via operator 'new').
    T_ *m_array;

    // The size of the memory allocated to the array (in numbers of elements).
    int m_capacity; 

    // The amount by which the array will grow whenever we run out of memory
    // (in numbers of elements).
    int m_growSize; 

    // The number of elements actually stored in the array (always <= m_capacity)
    int m_numElements;

    // Private methods - see implementation section, below
    void copy(const DynamicArray & other);
    void expand();
};



///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Implementation
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/******************************************************************************
*******************************************************************************/
template< typename T_ >
DynamicArray< typename T_ >::DynamicArray(int growSize)
{
    m_growSize = growSize;
    m_numElements = 0; // The array will be initially empty

    // Start out with no memory allocated. This will be more efficient than 
    // allocating some amount of memory to start with, as we can then create many 
    // empty DynamicArray objects with no memory being used. However, this will 
    // make the code slightly more complicated, since we'll always need to check
    // that 'm_array' actually points to valid memory.
    m_capacity = 0;
    m_array = 0;
}
 
/******************************************************************************
*******************************************************************************/
template< typename T_ >
DynamicArray< typename T_ >::~DynamicArray()
{
    // Because 'm_array' starts out as zero, we'll need to check that it 'exists'
    // before we delete it.
    if (m_array != 0)
    {
        delete[] m_array; // DANGER!!! Must always use 'delete []' with dynamic arrays!

        // A good safety practice is to always set pointers to zero immediately 
        // after you delete them. That way, if you accidentally use them later, you'll
        // at least get a clean crash (rather than random bad behaviour).
        m_array = 0;
    }
}

/******************************************************************************
*******************************************************************************/
template< typename T_ >
DynamicArray< typename T_ >::DynamicArray(const DynamicArray & other)
{
    copy(other);
}

/******************************************************************************
*******************************************************************************/
template< typename T_ >
DynamicArray< typename T_ > & DynamicArray< typename T_ >::operator=(const DynamicArray & other)
{
    if (this != &other)
    {
        copy(other);
    }
    return *this;
}

/******************************************************************************
*******************************************************************************/
template< typename T_ >
T_ & DynamicArray< typename T_ >::operator[](int index)
{
    return get(index);
}

/******************************************************************************
*******************************************************************************/
template< typename T_ >
void DynamicArray< typename T_ >::add(const T_ & element)
{
    if (m_numElements >= m_capacity)
    {
        expand();
    }

    MY_ASSERT(m_numElements < m_capacity);
    m_array[m_numElements] = element;

    m_numElements++;
}

/******************************************************************************
This function copies the 'other' DynamicArray onto this one. It's called from 
a couple of places within the class.
*******************************************************************************/
template< typename T_ >
void DynamicArray< typename T_ >::copy(const DynamicArray & other)
{
	// First, assign the various member variables to the values of those in 'other'
    m_numElements = other.m_numElements;
    m_growSize    = other.m_growSize;
    m_capacity    = other.m_capacity;

	// Since we'll be copying from the other array, the first thing we can do is 
	// to delete this array's memory. 
    if (m_array != 0)
    {
        delete[] m_array; // Again, use the correct form of 'delete' or else horror will ensue.
        m_array = 0;
    }

    if (other.m_capacity > 0)
    {
		// Example of sopmething worth an ASSERT check. If the other array has
		// a non-zero capacity, then, in theory, there SHOULD be an actual m_array' 
		// pointer present. But to trap a possible logic error, we can assert
		// that 'm_array' MUST be present. Then if it's not, we'll get a decent 
		// error message (with a file and line number), rather than just a crash.
        MY_ASSERT(other.m_array != 0);

		// Allocate this array to the size of 'other's array.
        m_array = new T_[m_capacity];
        MY_HEAP_CHECK(m_array);

		// ...and copy from 'other'
        for (int i = 0; i < other.m_capacity; i++)
        {
            m_array[i] = other.m_array[i];
        }
    }
}

/******************************************************************************
Expand the memory allocated to the array so that we can store more elements.
The array will expand by 'm_growSize'.
*******************************************************************************/
template< typename T_ >
void DynamicArray< typename T_ >::expand()
{
    m_capacity += m_growSize;

	// In C++, we can't just increase a dynamic array in memory (although some of 
	// the lower-level memory management functions can in fact do this). So, we need
	// a temporary array in memory into which we can copy 'm_array'.
    T_ *tempArray = new T_[m_capacity];
    MY_HEAP_CHECK(tempArray);

	// Note that we always check that 'm_array' actually exists before we try and use it.
    if (m_array != 0)
    {
		// Copy all existing elements from the 'm_array' into the temporary array.
		// Note that we ASSERT that 'm_numElements' is actually less than the capacity
		// before we copy. Although it SHOULD be (if our logic is always correct),
		// if ever it is not, then we'll be assinging elements into memory that we 
		// don't own (a guaranteed crash or undefined behaviour). Given that this is a 
		// vital condition, we can ASSERT it to be absolutely safe.
		MY_ASSERT(m_numElements <= m_capacity);
        for (int i = 0; i < m_numElements; i++)
        {
            tempArray[i] = m_array[i];
        }

		// All of the elements have now been copied over to the temporary array, so
		// we can now delete the original 'm_array'. If we left this step out, 
		// we'd get a memory leak.
        delete[] m_array;

		// Again, always zero-ize a pointer after deleting it so there's no chance
		// of using an invalid pointer (at least attempting to use a zero pointer
		// will give a consistent failure, rather than undefined behaviour).
        m_array = 0;
    }

	// Finally, store the address of the temporary array back to 'm_array'. 
	// Because these are both pointers, there is no actual copying of elements 
	// caused by doing this. We are simply storing an address. The end result is
	// that 'm_array' will now point to the expanded block of memory that was 
	// allocated to the temporary array. Note that we DON'T now delete the 
	// temporary array, since that memory is now 'connected to' the 'm_array' variable.
    m_array = tempArray;
}

/******************************************************************************
Get an element from the array by specifying its index position. Throw an exception
if the supplied index is out of range. This will make it 'impossible' for the
caller to inadvertently misuse the array.
*******************************************************************************/
template< typename T_ >
T_ & DynamicArray< typename T_ >::get(int index)
{
    if (index < 0 || index >= m_numElements)
    {
        throw std::exception("DynamicArray::get - index out of range");
    }

    MY_ASSERT(m_array != 0);
    MY_ASSERT(index < m_capacity);

    return m_array[index];
}

/******************************************************************************
*******************************************************************************/
template< typename T_ >
int DynamicArray< typename T_ >::size() const
{
    return m_numElements;
}



// Any macros that we defined and are only used within this file, we should 'un-define',
// otherwise the symbols may clash with other symbols defined with the same names.
#undef MY_ASSERT
#undef MY_HEAP_CHECK

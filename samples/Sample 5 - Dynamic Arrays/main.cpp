/******************************************************************************

This sample shows:

    - How to create a dynamic array of generic items (i.e. we use a template). 
      
    - Using C++ exception handling for dealing with fatal errors. 

    - Using some simple macros to streamline error-handling in the code.

*******************************************************************************/
#include <iostream>
#include "DynamicArray.h"
#include <string>



/******************************************************************************
Test function for a DynamicArray of ints (memory handling and deep-copying).
*******************************************************************************/
void testWithInts()
{
    // The first array, populated with some strings (setting a grow-size of 2
    // to force an expansion).
    DynamicArray<int> array_1(2);
    array_1.add(1);
    array_1.add(2);
    array_1.add(3);

    // We can also allocate elements directly via '[]' (as long as we stay
    // within the bounds of the array)
    array_1[0] = 1;

    // For example, un-commenting the following line will throw an 'out of bounds' exception.
    //array_1[10] = 10;

    // Display the contents of the first array
    std::cout << "\nArray 1:\n";
    for (int i = 0; i < array_1.size(); i++)
    {
        std::cout << "   " << array_1[i] << "\n";
    }

    // The second array, populated with some more ints (grow-size of 3)
    DynamicArray<int> array_2(3);
    array_2.add(4);
    array_2.add(5);
    array_2.add(6);
    array_2.add(7);

	// Display the contents of the second array
	std::cout << "\nArray 2:\n";
    for (int i = 0; i < array_2.size(); i++)
    {
        std::cout << "   " << array_2[i] << "\n";
    }

    // Trigger a deep copy
    array_1 = array_2;

    // We should now see all of array_2's elements replacing those in array_1
    std::cout << "\nArray 1 = Array 2:\n";
    for (int i = 0; i < array_1.size(); i++)
    {
        std::cout << "   " << array_1[i] << "\n";
    }
}

/******************************************************************************
Test function for a DynamicArray of strings (memory handling and deep-copying).
*******************************************************************************/
void testWithStrings()
{
    // The first array, populated with some strings (setting a grow-size of 2
    // to force an expansion).
    DynamicArray<std::string> array_1(2);
    array_1.add("one");
    array_1.add("two");
    array_1.add("three");

    // Display the contents of the first array
    std::cout << "\nArray 1:\n";
    for (int i = 0; i < array_1.size(); i++)
    {
        std::cout << "   " << array_1[i] << "\n";
    }

    // The second array, populated with some more strings (grow-size of 3)
    DynamicArray<std::string> array_2(3);
    array_2.add("four");
    array_2.add("five");
    array_2.add("six");
    array_2.add("seven");

	// Display the contents of the second array
	std::cout << "\nArray 2:\n";
    for (int i = 0; i < array_2.size(); i++)
    {
        std::cout << "   " << array_2[i] << "\n";
    }

    // Trigger a deep copy
    array_1 = array_2;

    // We should now see all of array_2's elements replacing those in array_1
    std::cout << "\nArray 1 = Array 2:\n";
    for (int i = 0; i < array_1.size(); i++)
    {
        std::cout << "   " << array_1[i] << "\n";
    }
}

/******************************************************************************
*******************************************************************************/
void main()
{
    try
    {
		std::system("cls");

        // Run a test with a DynamicArray of ints.
        testWithInts();

        // Run another test with a DynamicArray of std::strings.
        testWithStrings();

        std::cout << "\n\nFinished\n\n";
    }
    catch (std::exception & e)
    {
        std::cout << "\n\nException - " << e.what() << "\n\n";
    }
    catch (...)
    {
        std::cout << "\n\nUnhandled exception\n\n";
    }
}
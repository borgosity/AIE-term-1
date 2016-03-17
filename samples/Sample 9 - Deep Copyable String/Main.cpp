#include <iostream>

#include "NonCopyable.h"


class MyString : public NonCopyable
{
public:
    // Constructor
    MyString();

    // Destructor
    ~MyString();



    //-------------------------------------------
    // Deep copyable!
    //-------------------------------------------

    // Copy constructors
    MyString(const MyString & other);
    MyString(const char *str);

    // Overloaded assignment operators
    MyString & operator=(const MyString & other);
    MyString & operator=(const char *str);



    //-------------------------------------------
    // Public Methods
    //-------------------------------------------

    // Copy the contents of 'other' into this string
    void copy(const MyString & other);

    // Copy 'str' into this string
    void copy(const char *str);

    // Getter to return the internal C-string
    const char *cstr() const { return m_str; }

private:

    char *m_str;

    void destroy();
};



// Constructor
MyString::MyString()
{
    m_str = nullptr;
}

// Destructor
MyString::~MyString()
{
    destroy();
}

///*******************************************************************
// Copy constructor for MyString objects
MyString::MyString(const MyString & other)
{
    m_str = new char[strlen(other.cstr()) + 1];
    strcpy(m_str, other.cstr());
}

// Copy constructor for C-strings
MyString::MyString(const char *str)
{
    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
}

// Overloaded assignment operator for a MyString argument
MyString & MyString::operator=(const MyString & other)
{
    if (&other != this) // Prevent self-assignment
    {
        copy(other);
    }
    return *this;
}

// Overloaded assignment operator for a C-string argument
MyString & MyString::operator=(const char *str)
{
    copy(str);
    return *this;
}
//********************************************************************/

// Copy the contents of 'other' into this string
void MyString::copy(const MyString & other)
{
    copy(other.cstr());
}

// Copy 'str' into this string
void MyString::copy(const char * str)
{
    destroy();
    m_str = new char[strlen(str) + 1]; 
    strcpy(m_str, str);
}

// Safely destroy the memory allocated to m_str
void MyString::destroy()
{
    if (m_str != nullptr)
    {
        delete[] m_str;
        m_str = 0;
    }
}



/******************************************************************************
*******************************************************************************/
void printString(MyString s)
{
    std::cout << "string = \"" << s.cstr() << "\"\n\n";

}

/******************************************************************************
Program entry point
*******************************************************************************/
void main()
{
    MyString s1;
    s1.copy ("Hello World");

    MyString s2 = s1;
    s2 = s1;

    s2 = "Hello world";

    printString(s1);

    system("pause");
}
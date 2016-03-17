#include <iostream>


class MyString
{
public:
    MyString();
    ~MyString();

    void copy(const char *str);

    void copy(MyString s);

    const char *cstr() { return m_str; }

private:

    char *m_str;

    void destroy();
};


MyString::MyString()
{
    m_str = nullptr;
}

MyString::~MyString()
{
    destroy();
}

void MyString::copy(const char * str)
{
    destroy();

    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
}

void MyString::copy(const MyString & s)
{
    s.copy("aaa");

    // dasdkasdkjas
}

void MyString::destroy()
{
    if (m_str != nullptr)
    {
        delete[] m_str;
//        m_str = nullptr;
    }
}



void main()
{
    MyString s;
    
    s.copy("Hello World");

    {
        MyString s2;
        s2.copy(s);
    }

    // asasjas djas
}
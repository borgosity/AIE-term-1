#include <iostream>

// Duncan told me to do this!
#define SAFE_ARRAY_DELETE(p_)   \
{                               \
    if(p_ != nullptr)           \
    {                           \
        delete[] p_;            \
        p_ = nullptr;           \
    }                           \
}




/******************************************************************************
My string class to satisfy the demonic teachers
Should be like std::string
*******************************************************************************/
class MyString
{
public:
    MyString();
    ~MyString();

    // Copies 'str' into this class.
    void copy(const char *str);

    bool equals(const char *str) const;

private:

    char *m_str;
};

/******************************************************************************
Constructor
*******************************************************************************/
MyString::MyString()
{
    m_str = nullptr;
}

/******************************************************************************
Destructor
*******************************************************************************/
MyString::~MyString()
{
    SAFE_ARRAY_DELETE(m_str);
}

/******************************************************************************
*******************************************************************************/
void MyString::copy(const char *str)
{
    SAFE_ARRAY_DELETE(m_str);

    m_str = new char[strlen(str) + 1];
    strcpy(m_str, str);
}

/******************************************************************************
*******************************************************************************/
bool MyString::equals(const char *str) const
{
    return strcmp(m_str, str) == 0;
}


/******************************************************************************
Program entry point
*******************************************************************************/
void main()
{
    {
        MyString str;
        str.copy("cat sat on the");


//        str.prepend("the ");
//        str.append(" mat");

        if (!str.equals("the cat sat on the mat"))
        {
            // ERROR!!!!!!!!!!!!!
        }
    }
//    str = "1111111111111";

/*
    MyString str2;
    str2 = "222222222";

    MyString str3;
    str3 = str1 + str2;
*/




    std::cout << "\n\n";
}


#undef SAFE_ARRAY_DELETE
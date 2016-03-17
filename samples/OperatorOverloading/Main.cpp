#include <iostream>



class MyString
{
public:

    bool equals(const char *str) const
    {
        return true;
    }

    bool equals(const MyString & str) const
    {
        return true;
    }

    void copy(const char *str)
    {
    }

    void append(const char *str)
    {
    }

    const char *c_str() const { return m_str; }


    MyString & operator+(const char *rhs)
    {
        append(rhs);
        return *this;
    }

    MyString & operator+(MyString & rhs)
    {
        append(rhs.m_str);
        return *this;
    }

    MyString & operator+=(const char *str)
    {

    }

    MyString & operator=(const char *rhs)
    {
        copy(rhs);
        return *this;
    }

    //MyString & operator=(const MyString & rhs)
    //{
    //    if (&rhs != this) // Prevent self-assignment!
    //    {
    //        copy(rhs.m_str);
    //    }
    //    return *this;
    //}


    bool operator==(const char *rhs) const
    {
//        return (strcmp(m_str, rhs) == 0);

        // SLightly less efficent
        return equals(rhs);
    }

    const char *operator<<(const MyString & str)
    {
        return str.c_str();
    }

    const char *operator()()
    {
        return m_str;
    }

    // Implicit type-casting
    operator char *()
    {
        return m_str;
    }

private:

    char *m_str;
};




bool operator==(const MyString & lhs, const MyString & rhs)
{
    return lhs.equals(rhs);
}



void main()
{
    MyString s1, s2, s3;

    std::cout << s1;

    s1.copy("Hello");
    s2.copy("World");

    s1 = "Hello";
    s1 = s1;

    s1 + s2 + s3;

    s1.append("World");

    if (s1 == "Hello")
    {

    }

    s1 = s1 + "World";
    s1 = s2 + s3;

    s1 += "World";

}
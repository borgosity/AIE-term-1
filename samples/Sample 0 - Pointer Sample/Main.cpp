/******************************************************************************

                                Pointer Sample
                                --------------

This project provides a simple example of C-string manipulation using pointers 
and dynamic memory allocation. The code is documented fairly heavily to explain
what is going on step-by-step.

There are two functions in this sample:

    1) 'getFirstWord' - returns the first word that occurs in a specified C-string,
                        i.e. it skips past any leading white space. Two versions 
                        are provided, one normal version and one with a deliberate
                        memory-corruption bug.

    2) 'myCat' - Concatenates one C-string onto the end of another (equivalent
                 to what the built-in 'strcat' function does. This requires 
                 dynamic memory allocation to work and is similar to what you'll 
                 need to do in your first assessment.

*******************************************************************************/
#include <iostream>



/******************************************************************************
Returns a pointer to the first word that occurs in 'cstr', i.e. the first 
non-whitespace character. Note that this function doesn't actually create a new 
C-string to contain the word, but simply points into the existing 'cstr'. This 
is one of the advantages of using C-strings: they can be very efficient and can
sometimes involve doing any memory allocation at all (unlike the higher-level 
std::string).
*******************************************************************************/
char *getFirstWord(char *cstr)
{
    // Whenever a pointer is passed into a function, we should ALWAYS check that
    // it isn't null. This will help avoid a memory curruption bug spreading
    // throughout your code. We'll be showing you some more advanced error-handling
    // techniques later in the course (e.g. exception handling), but for now we'll 
    // just return a null string if we see that 'cstr' is invalid.
    if (! cstr)
    {
        return nullptr;
    }

    // If we get to here then we know that we have a valid (hopefully) C-string.
    // The first thing we'll do is to create a local pointer which we'll set to 
    // point at the beginning of 'cstr'. We name the new pointer 'pChar' to 
    // indicate that it is a pointer to a character. Remember that a 'char *'
    // can be considered both as a C-string and also as a pointer to a single 
    // character (since a C-string is just a array of characters in memory
    // terminated by a zero.
    char *pChar = cstr;

    // This code 'advances' pChar character-by-character through the string
    // until we see a non-white space character. This takes advantage of the fact
    // that the space (ASCI 32) is the lowest human-readable character (all characters
    // lower than that are the 'special' characters, things like new-line, 
    // carriage-return, tab etc). 
    //      Note 1 - To access a character, we use '*pChar' which is the actual 
    //               character at which pChar is pointing. The asterisk (the indirection 
    //               operator) is the thing that 'follows' the pointer to arrive at 
    //               the memory location at which it pointing.
    //      Note 2 - We also have to be careful that we don't just run past the 
    //               end of the string by checking that the character we are pointing
    //               at is not a zero.
    while (*pChar <= ' ' && *pChar != 0)
    {
        pChar++;
    }

    // If we get to here, then 'pChar' will be pointing at the first non-whitespace
    // character. You should satisfy yourself that the above code will work
    // in all situations, regardless of whether 'cstr' is blank, contains no
    // leading whitespace, one space, or multiple spaces.

    // The last thing to do is to pass 'pChar' back to the caller.
    return pChar;
}

/******************************************************************************
This is another version of 'getFirstWord' but with a pretty horrible memory
corruption bug, just to illustrate the trouble you can get into if you don't 
thoroughly understand how memory and pointers actually work.
*******************************************************************************/
char *getFirstWord_BuggyVersion(char *cstr)
{
    // In this version of the function, we take the approach of creating a 
    // new C-string in which to store the first word, which we'll extract 
    // from C-string. It's this new string that we'll return to the caller.
    char newStr[100];

    // First, we'll copy 'cstr' into 'newStr' where we'll be able to work on it
    // separately from 'cstr'. We'll use 'strcpy', one of the built-in C run-time
    // functions to achieve this. Note that 'strcpy' takes a char * as the first
    // argument, i.e. a pointer. This might lead you to expect that we should 
    // pass '&newStr' as the first argument, i.e. because we need a pointer we
    // need to take the address of newStr (which is what the '&' does). But 
    // remember that C/C++ automatically treats arrays as pointers, so we
    // can pass in 'newStr' directly.
    strcpy(newStr, cstr);

    // At this point, we have 'cstr' copied into 'newStr' so we can now go
    // ahead and scan for the first non-whitespace character, just as we did
    // in the 'correct' version of getFirstWord above. First, point at the 
    // start of 'newStr'
    char *pChar = newStr;

    // Scan past the whitespace
    while (*pChar >= ' ' && *pChar != 0)
    {
        pChar++;
    }

    // pChar now points to the first non-whitespace in newStr, so we just 
    // need to pass the pointer back to the caller.
    //
    // !!!!!!!!!!!!!!!!!!!!!!! BAD BAD BAD BAD !!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!! DANGER DANGER DANGER !!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!  AAAAGGGGHHHH   !!!!!!!!!!!!!!!!!!!!!!!!!
    //
    // But here is where we make our disastrous mistake! Although there is 
    // nothing wrong with the logic within this function (the logic is the same
    // as the correct version just above), we now fall down the memory-hole 
    // by RETURNING THE ADDRESS OF A LOCAL VARIABLE ('newStr'). This is one of 
    // the nastier (and subtle) mistakes you can make, because the result may 
    // even be correct, or may be complete garbage, depnding on what the compiler
    // has had for dinner. The core issue is that 'newStr' goes out of scope
    // as we leave the function.
    return pChar;
}

/******************************************************************************
This function is an 'improved' version of the built-in C run-time function 'strcat'.
'strcat' does the same job of concatenating a source string onto a destination
string. But 'strcat' requires you to have enough memory in the destination string
to accept the extra characters appended to the end. This therefore runs the 
risk of overrunning the destination buffer and corrupting memory.

What we want to achieve with this function is to do the same thing as 'strcat', 
i.e. concatenate a source string onto a destination string. But we'd like the memory
allocated to the destination string to increase itself automatically to accommodate
the concatenated characters. This will involve some memory handling and will be 
very similar to the kind of thing that you'll need to do for your assessment.
*******************************************************************************/
void myCat(char **dest, char *src)
{
    // The first thing to note is the double-asterisk in front of 'dest'. This means
    // that 'dest' is a pointer to a pointer to a char. Another way of expressing it is
    // that it is an address of an address. We need to do this because if we just 
    // passed in the destination string as '*dest', we would be able to change
    // the string itself, that is '*dest', because 'dest' is a pointer and is therefore
    // pass-by-reference. Remember that anything we pass by reference we can change
    // inside the function, whereas anything passed by value (i.e. anything that 
    // isn't a pointer or a reference) cannot be changed. But the address of the string,
    // i.e. '*dest' is pass-by-value so we can't change it and we'll need to alter 
    // the address in order to allocate new memory to it. We achieve what we want
    // by passing it is '**dest', so that we now have the actual address of the pointer.

    // The first thing we need to do is to compute how much memory we are going to need 
    // for the destination string. This will be the sum of the two strings plus one more 
    // character to allow for the null termminator on the final concatenated string. 
    // Note that to refer to the destination string, we now have to use '*dest' rather 
    // than just 'dest'. Remember that 'dest' is the ADDRESS of a pointer to a char,
    // whereas '*dest' is the pointer to a char, which is what the 'strlen' function
    // requires for its argument.
    int newLen = strlen(*dest) + strlen(src) + 1;

    // Now we can allocate a new block of memory from the heap that will be big
    // enough to hold both strings plus a null terminator.
    char *newStr = new char[newLen];

    // WARNING - As always, we should check for a null return to guard against
    // running out of memory or a memory corruption, but we'll leave that out for
    // this sample.
    if (newStr == 0)
    {
        // Proper error handling should go here!
    }

    // Copy the destination string into the new block of memory. Again, note that
    // the actual string is '*dest', not 'dest'.
    strcpy(newStr, *dest);

    // Next, we call the C Run-Time Library function to concatenate the source 
    // string onto the new string we just previously copied. But now that we
    // have allocated enough memory to 'newStr', we are guaranteed that
    // 'strcat' will work and not run off the end of memory, which it would normally
    // do if you haven't arranged for enough memory to be available, one way or another.
    strcat(newStr, src);

    // There are now two dangerous things to take care of, either of which will be
    // disastrous if we get them wrong. 
    //
    //      First dangerous thing: Working out which chunk of memory needs to be
    //          deleted (if we didn't do the delete, then we'd have a memory leak, 
    //          since new memory has been allocated without a corresponding delete).
    //
    //      Second dangerous thing: Using the CORRECT version of delete, i.e. 'delete[]'
    //          and NOT straight 'delete'. 'delete[]' must ALWAYS be used with memory
    //          allocated via 'new...[]' and 'delete' always used with 'new'.
    //
    // You might think that we need to delete 'newStr' because that's the pointer we 
    // used to store teh new memory. But that would be WRONG (and DISASTROUS), because 
    // we want to pass that block of new memory with the concatenated strings back out 
    // to the caller. The correct thing is to delete the memory allocated to the original
    // 'dest' string, since that string is now being 'replaced' by the new string. And
    // remember that the original pointer (which is what we want to delete) is contained
    // in '*dest', not 'dest'. So, what we want is:
    delete[](*dest);

    // Now that the original memory has been deleted, we can modify the caller's original
    // pointer to point to the new memory. Since 'dest' is the address of the address of 
    // the string (or a pointer to the pointer to the string), '*dest' will contain the 
    // address of the pointer to the string. Since the address of the pointer has now
    // changed to that of the new memory, we need to change the old address to 'newStr',
    // that is:
    *dest = newStr;

    // WHEW! We're now done. The caller's string, i.e. their pointer to char, now contains
    // the address of a new block of memory, which in turn contains the concatenated string.
}



/******************************************************************************
Program entry point
*******************************************************************************/
void main()
{
    // Firstly, we'll demonstrate the use of the 'getFirstWord' function to skip
    // past whitespace.
    char someText[50] = "   Rumplestiltskin";

    char *pFirstWord = getFirstWord(someText);
    std::cout << "The first word is \"" << pFirstWord << "\" \n\n";

    // Next, we'll demonstrate the use of the 'myCat' function to automatically 
    // 'grow' a string in memory when another string is concatenated onto its end.

    // Allocate a C-string on the heap (i.e. in dynamic memory) using operator 'new'
    char *str1 = new char[8];

    // IMPORTANT - whenever you allocate memory, you should check for a null 
    // return. The heap manager will return null if for any reason it can't 
    // allocate the requested amount of memory. The usual reason for this would 
    // be that there is not enough memory left to grant the request. But the other
    // way that you can get a null return is if you have corrupted the heap through
    // bad code (C++ gives you quite a few ways in which you can corrupt the heap).
    // For this sample, we'll just write an error message to cout and quit the app).
    if (str1 == nullptr)
    {
        std::cout << "Memory failure!";
        return;
    }

    // Now allocate a second string on the heap.
    char *str2 = new char[8];
    if (str2 == nullptr)
    {
        std::cout << "Memory failure!";
        return;
    }

    // Store some text in both strings
    strcpy(str1, "Hello ");
    strcpy(str2, "World");

    // We now have our two strings. Next we want to concatenate str2 onto the end of
    // str1. If we used the C Run-Time Library function 'strcat' to do this, we'd
    // do the following:
    //
    //      strcat(str1, str2);
    //
    // But his would be VERY BAD!!! str1 can only contain 8 characters (including the 
    // null terminator at the end), it already contains 6 ("hello" plus the null terminator),
    // so a the above line of code would result in a buffer overrun  and subsequent memory 
    // corruption. This shows how easy it is to currupt memory unless you are ETERNALLY VIGILANT!

    // But if we call our new function, 'myCat', we can forget about the perils of 'strcat'
    // and relax, knowing that 'myCat' will take care of automatically expanding the memory 
    // allocated to str1 so that it will be be big enough to concatenate str2 onto its end.
    // Note 1 - We pass '&str1' to the myCat function because that function will be changing 
    // the value of str1 which, remember, is a pointer and therfore contains the ADDRESS of
    // the string, not the string itself. Since 'myCat' will be changing the ADDRESS stored in
    // 'str1' when it allocates more memory to that address, we need to use the address-of 
    // operator ('&') to pass the ADDRESS of the ADDRESS so that it can be modified by 'myCat'.
    myCat(&str1, str2);

    std::cout << "That concatenated string is \"" << str1 << "\" \n\n";
}
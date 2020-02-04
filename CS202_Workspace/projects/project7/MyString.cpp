// Abraham Meza //
// This file is a test driver for testing dynamic memory prescribed in Project 7 of CS-202 //

// header files//
#include <iostream>
#include <cstring>

// custom header files
#include "MyString.h"

using namespace std;

MyString::MyString() { // default constructor definition
    cout << "MyString: Default-ctor" <<  endl; // default constructor confirmation statement
    m_buffer = NULL; // initalizes buffer string to NULL
    m_size = 0; // initalizes size int to 0
}

MyString::MyString(const char *str) { // parameterized constructor definition 
    cout << "MyString: Parameterized-ctor" <<  endl; // parameterized constructor confirmation statement

    int len = strlen(str); // initalizing len variable to the int value of the string length

    try { // try/catch statements that allocate the memory of the given string
        buffer_allocate(len);
        strcpy(m_buffer, str);
    } catch (const bad_alloc& e) { // allocation error
        cout << "Failed Parameterized-ctor" <<  endl; // if allocation error, error message is provided
    }
}

MyString::MyString(const MyString & o_str) { // copy constructor definition (copies string data)
    cout << "MyString: Copy-ctor" <<  endl; // copy constructor confirmation statement

    try { // try/catch statements that allocate the memory of the given string
        buffer_allocate(o_str.m_size);
        strcpy(m_buffer, o_str.m_buffer);
    } catch (const bad_alloc& e) { // attempt to catch allocation error
        cout << "Failed Copy-ctor" <<  endl; // if allocation error caught, error message is provided
    }
}

MyString::~MyString() { // destructor definition
    cout << "MyString: Dtor" <<  endl; // destructor confirmation statement

    buffer_deallocate(); // call buffer_deallocate() function to deallocate memory at the end of the program
}

// Function / Method Definitions //

size_t MyString::size() const { // size() method definition
    cout << "MyString: size() Function" <<  endl; // size() confirmaton statement

    return m_size; // returns value of the string (including NULL terminator)
}

size_t MyString::length() const { // length() method definition
    cout << "MyString: length() Function" <<  endl; // length() confirmation statement

    return strlen(m_buffer); // returns value of string (strlen value; no NULL terminator)
}

const char *MyString::c_str() const { // c_str() method definition
    cout << "MyString: c_str() Function" <<  endl; // c_str() confrimation statement

    return m_buffer; // returns equivalent C-string
}

// Operator Overload Definitions //

bool MyString::operator==(const MyString &o_str) const { // comparison operator overload definition
    cout << "MyString: Comparison" <<  endl; // comparison operator confirmation statement

    return !strcmp(m_buffer, o_str.c_str()); // returns a bool value that compares if two strings are the same
}

MyString &MyString::operator=(const MyString &o_str) { // assignment operator overload definition
    cout << "MyString: Assignment" <<  endl; // assignment operator confirmation statement

    if (this != &o_str) { // if statement that checks if the called string is similar to original
        if (o_str.size() != m_size) { // if statement that checks if memory allocation is the same
            buffer_deallocate(); // deallocates current memory
            buffer_allocate(strlen(o_str.c_str())); // alllocates new memory
        }

        strcpy(m_buffer, o_str.c_str()); // copies string data (assignment)
    }

    return *this; // return new string data
}

MyString MyString::operator+(const MyString &o_str) const { // concatenate (addend) operator overload definition
    cout << "MyString: Concatenation" << endl; // concatenate operator confirmation statement

    char str[m_size + o_str.size()]; // size of string expanded based on the individual sizes (both added together)

    strcpy(str, c_str()); // copying first string data to new string
    strcat(str, o_str.c_str()); // concatenating second string data to new string

    return MyString(str); // returns new string data
}

char &MyString::operator[](size_t index) { // bracket operator overload definition
    cout << "MyString: Bracket" <<  endl; // bracket operator confirmation statement

    return m_buffer[index]; // returns specific character based on index value (array indexing) (read/write)
}

const char &MyString::operator[](size_t index) const {  // bracket operator overload definition
    cout << "MyString: Bracket Const" <<  endl; // bracket operator confrimation statement
  
    return m_buffer[index]; // returns specific character based on index (array indexing) as a const (read only)
}

ostream & operator<<(ostream &os, const MyString &myStr) { // friend insertion operator overload definition
    os << myStr.c_str(); // prints string data to screen

    return os;
}

void MyString::buffer_deallocate() { // buffer_deallocate() function defintion 
    cout << "MyString: buffer_deallocate() Function" <<  endl; // buffer_deallocate confirmation statement

    delete [] m_buffer; // deletes memory allocation of buffer string

    m_buffer = NULL; // reassigns buffer string to NULL
    m_size = 0; // reassigns size to 0
}

void MyString::buffer_allocate(size_t size) { // buffer_allocate() function definition
    cout << "MyString: buffer_allocate() Function" <<  endl; // buffer_allocate() confirmation statement

    try { // try/catch statement that allocates memory based on char * size 
        m_buffer = new char[size + 1];  // include null-terminator
        m_size = size + 1;
    } catch ( bad_alloc& e) { // attempt to catch allocation error
        cerr << e.what() <<  endl;
        throw;
    }
}
// Abraham Meza //
// This file is a test driver for testing dynamic memory prescribed in Project 7 of CS-202 //

// header files//
#include <iostream>
#include <cstring>

// custom header files
#include "MyString.h"

using namespace std;

int main() {
    cout << "\n" <<
          "////////////////////////////////\n" <<
          "/////   Constructor Tests  /////\n" <<
          "////////////////////////////////" << endl << endl; // test label design

    //(1)
    cout << "Testing Default ctor" << endl; // default constructor confirmation statement
        MyString ms_default; // testing default ctor
        cout << endl;

    //(2)
    cout << "Testing Paramterized ctor" << endl; // parameterized constructor confirmation statement
        MyString ms_parametrized("MyString parametrized constructor!"); // testing parameterized ctor with ("MyString parameterized constructor!")
        cout << endl;

    //(3)
    cout << "Testing Copy ctor" << endl; // copy constructor confirmation statement
        MyString ms_copy(ms_parametrized); // testing copy ctor
        cout << endl;

    //(4)
    cout << "Testing Destructor" << endl;// destrcutor confrimation statement
        MyString * ms_Pt = new MyString("MyString to be deleted..."); // setting a predetermined string to be deleted
        delete ms_Pt; // deleting predetermined string 
        ms_Pt = NULL; // reassigning string value to NULL
        cout << endl;

    cout << "\n" <<
          "////////////////////////////////////\n" <<
          "/////   Method/Function Tests  /////\n" <<
          "////////////////////////////////////" << endl << endl; // test label design

    //(5)
    cout << "Testing size() method" << endl << endl; // size() confirmation statement
        MyString ms_size("Size and length test"); // testing size() with ("Size and length test")
        cout << ms_size.size() << endl << endl; // outputting size data 
         
    //(6)
    cout << "Testing length() method" << endl << endl; // length() confirmation statement
        MyString ms_length("Size and length test"); // testing length() with ("Size and length test")
        cout << ms_length.length() << endl << endl; // outputting length data

    //(7)
    cout << "Testing c_str() method" << endl << endl; // c_str() confirmation statement
        MyString ms_toCstring("C-String equivalent successfully obtained!"); // tetsing c_str() with ("C-string equivalent successfuly obtained!")
        cout << ms_toCstring.c_str() << endl; // outputting c_str data 
        cout << endl;

    cout << "\n" <<
          "//////////////////////////////////////\n" <<
          "/////   Overload Operator Tests  /////\n" <<
          "//////////////////////////////////////" << endl << endl; // test label design

    //(8)
    cout << "Testing Comparison Operator" << endl << endl; // comparison operator confirmation statement
        MyString ms_same1("The same"), ms_same2("The same"); // testing comparsion operator with two pre-determined strings

        if (ms_same1==ms_same2) { // if statement that compares strings to see if identical 
            cout << endl;
            cout << "Same success" << endl << endl; // output if strings are the same
        }

        MyString ms_different("The same (NOT)"); // creating a new string to compare
        if (!(ms_same1==ms_different)) { // compring 1st string and new strirng to see if identical
            cout << endl;
            cout << "Different success" << endl << endl; // output if strings are not the same
        }

    //(9)
    cout << "Testing Assingment Operator" << endl << endl; // assignment operator confirmation statement
        MyString ms_assign("Before assignment"); // assigning a string to ("Before assignment")
        cout << ms_assign << endl << endl; // outputting assigned string

        ms_assign = MyString("After performing assignment"); // assigning previous string to ("After performing assignment")
        cout << ms_assign << endl << endl; // outputting assiigned string

    //(10)
    cout << "Testing Concatenation Operator" << endl << endl; // concatenation operator confirmation statement
        MyString ms_append1("The first part"); // assigning string 1
        MyString ms_append2(" and the second"); // assigning string 2
        MyString ms_concat = ms_append1 + ms_append2; // adding strings (concatenation)
        cout << ms_concat << endl; // outputting resulting string 
        cout << endl;

    //(11)
    cout << "Testing Bracket Operator" << endl << endl; // bracket operator confirmation statement
        MyString ms_access("Access successful (NOT)"); // assigning string to ("Access successful (NOT)")
        ms_access[17] = 0; // array indexing to 17th place value in string, assinging 0, thus omittng anything after
        cout << endl;

    //12
    cout << "Testing Insertion Operator" << endl << endl;
        cout << ms_access << endl << endl; // printing bracket string (memory allocation, etc.)

    cout << "\n" <<
          "////////////////////////////\n" <<
          "/////    Tests Done    /////\n" <<
          "////////////////////////////" << endl << endl; // test label design

    // Destructors activated and deallocate all utilized strings //

    return 0; // end program
}
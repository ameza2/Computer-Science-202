// Abraham Meza //
// This file is a test driver for testing queues in conjunction to array-based and node-based variants prescribed in Project 9 of CS-202 //

// header file(s) //

#include <iostream>

// custom header file(s) //

#include "ArrayQueue.h"
#include "NodeQueue.h"
#include "DataType.h"

using namespace std;

// int main program //

int main() {

    DataType dt(1, 2.6); // predetermined DataType

    cout << "\n" <<
            "////////////////////////////////\n" <<
            "/////   Node Queue Tests   /////\n" <<
            "////////////////////////////////" << endl << endl; // test label design

    cout << "\n" <<
            "************************\n"
            "**  Constuctor Tests  **\n" <<
            "************************" << endl << endl;

    cout << "Default Constructor Test (no expected output):" << endl << endl; // confirmation statement

    NodeQueue nq_default; // default constructor
    cout << nq_default << endl; // printing default data

    cout << "Parameterized Constructor Test:" << endl << endl; // confirmation statement

    NodeQueue nq_param(3, dt); // paramterized constructor
    cout << nq_param << endl << endl; // printing parameterized data

    cout << "Copy Constructor Test:" << endl << endl; // confirmation statement
          
    NodeQueue nq_copy(nq_param); // copy constructor
    cout << nq_copy << endl << endl; // printing copy data

    cout << "\n" <<
            "*****************************\n"
            "**  Method/Operator Tests  **\n" <<
            "*****************************" << endl << endl;

    cout << "Assignment Operator Test:" << endl << endl; // confirmation statement

    NodeQueue nq_assign; // assignment operator overload

    nq_assign = nq_param; // assigning two sets of data
    cout << nq_assign << endl << endl; // printing assigned data

    cout << "Push and Pop Tests:" << endl << endl; // confirmation statement
        
    DataType dt2(2, 5.2); // predetermined DataType

    nq_copy.push(dt2); // push method
    cout << nq_copy << endl << endl; // push (copy)

    nq_copy.pop(); // pop method
    cout << nq_copy << endl << endl; // pop (copy)

   cout << "\n" <<
            "////////////////////////////////\n" <<
            "/////   Array Queue Tests   ////\n" <<
            "////////////////////////////////" << endl << endl; // test label design

    cout << "\n" <<
            "************************\n"
            "**  Constuctor Tests  **\n" <<
            "************************" << endl << endl;

    cout << "Default Constructor Test (no expected output):" << endl << endl; // confirmation statement
    
    ArrayQueue aq_default; // default constructor
    cout << nq_default << endl; // printing default data

    cout << "Parameterized Constructor Test:" << endl << endl; // confirmation statement

    ArrayQueue aq_param(3, dt); // paramterized constructor
    cout << aq_param << endl << endl; // printing parameterized data

    cout << "Copy Constructor Test:" << endl << endl; // confirmation statement

    ArrayQueue aq_copy(aq_param); // copy constructor
    cout << aq_copy << endl << endl; // printing copy data


    cout << "\n" <<
            "*****************************\n"
            "**  Method/Operator Tests  **\n" <<
            "*****************************" << endl << endl;

    cout << "Assignment Operator Test:" << endl << endl; // confirmation statement
    
    ArrayQueue aq_assign; // assignment operator overload

    aq_assign = aq_param; // assigning two sets of data
    cout << aq_assign << endl << endl; // printing assigned data

    cout << "Push and Pop Tests:" << endl << endl; // confirmation statement
    
    aq_copy.push(dt2); // push method
    cout << aq_copy << endl << endl; // push (copy)

    aq_copy.pop(); // pop method
    cout << aq_copy << endl << endl; // pop (copy)

    cout << "\n" <<
            "////////////////////////////////\n" <<
            "/////   Testing Concluded   ////\n" <<
            "////////////////////////////////" << endl << endl; // test label design

    cout << "\n" <<
            "****************\n"
            "**  Goodbye!  **\n" <<
            "****************" << endl << endl;
            
    return 0; // end program
}
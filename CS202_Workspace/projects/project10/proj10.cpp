// Abraham Meza //
// This file is a test driver for testing templated Stack classes in conjunction to array-based and node-based variants prescribed in Project 10 of CS-202 //

// header file(s) //

#include <iostream>

// custom header file(s) //

#include "ArrayStack.h"
#include "NodeStack.h"

using namespace std;

// int main() program //

int main() {
    cout << "\n" <<
                "////////////////////////////////\n" <<
                "/////   Node Stack Tests   /////\n" <<
                "////////////////////////////////" << endl << endl; // test label design

    cout << "\n" <<
        "************************\n"
        "**  Constuctor Tests  **\n" <<
        "************************" << endl << endl; // cout labeling

    cout << "Default Constructor Test (no expected output):" << endl; // confirmation statement

    NodeStack<int> ns_default_int; // NodeStack declaration (int)
    NodeStack<double> ns_default_dbl; // NodeStack declaration (double)

    cout << ns_default_int << endl; // default constructor (int)
    cout << ns_default_dbl << endl; // defualt constructor (double)

    cout << "Parameterized Constructor Test:" << endl << endl; // confirmation statement

    NodeStack<int> ns_param_int(2, 2); // paramterized predetermined values (int)
    NodeStack<double> ns_param_dbl(2, 2.5); // parameterized predetermined values (double)

    cout << "Integer:" << endl << endl; // cout confirmation
        cout << ns_param_int << endl << endl; // paramterized constructor (int)

    cout << "Double:" << endl << endl; // cout confirmation
        cout << ns_param_dbl << endl << endl; // parameterized constructor (double)

    cout << "Copy Constructor Test:" << endl << endl; // confirmation statement

    NodeStack<int> ns_copy_int(ns_param_int); // copy declaration (int)
    NodeStack<double> ns_copy_dbl(ns_param_dbl); // copy declaration (double)

    cout << "Integer:" << endl << endl; // cout confirmation
        cout << ns_copy_int << endl << endl; // copy constructor (int)
    
    cout << "Double:" << endl << endl; // cout confirmation
        cout << ns_copy_dbl << endl << endl; // copy constructor (double)

    cout << "\n" <<
        "*****************************\n"
        "**  Method/Operator Tests  **\n" <<
        "*****************************" << endl << endl; // cout labeling

    cout << "Assignment Operator Test:" << endl << endl; // confirmation statement

    NodeStack<int> ns_assign_int; // NodeStack declaration (int)
    NodeStack<double> ns_assign_dbl; // NodeStack declaration (double)

    ns_assign_int = ns_param_int; // assignment to paramterized constructor (int)
    ns_assign_dbl = ns_param_dbl; // assignment to paramterized constructor (double)

    cout << "Integer:" << endl << endl; // cout confirmation
        cout << ns_assign_int << endl << endl; // assigned data (int)
    
    cout << "Double:" << endl << endl; // cout confirmation
        cout << ns_assign_dbl << endl << endl; // assigned data (double)

    cout << "Push and Pop Tests:" << endl << endl; // confirmation statement

    cout << "Integer:" << endl << endl; // cout confirmation
        ns_assign_int.push(3); // push() function
        cout << ns_assign_int << endl << endl; // push() data

        ns_assign_int.pop(); // pop() function
        cout << ns_assign_int << endl << endl; // pop() data

    cout << "Double:" << endl << endl; // cout confirmation
        ns_assign_dbl.push(3.3); // push() function
        cout << ns_assign_dbl << endl << endl; // push() data

        ns_assign_dbl.pop(); // pop() function
        cout << ns_assign_dbl << endl << endl; // pop() data

    cout << "\n" <<
                "////////////////////////////////;\n" <<
                "/////   Array Stack Tests   /////\n" <<
                "/////////////////////////////////" << endl << endl; // test label design

    cout << "\n" <<
        "************************\n"
        "**  Constuctor Tests  **\n" <<
        "************************" << endl << endl; // cout labeling

    cout << "Default Constructor Test (no expected output):" << endl; // confirmation statement

    ArrayStack<int> as_default_int; // ArrayStack declaration (int)
    ArrayStack<double> as_default_dbl; // ArrayStack declaration (double)

    cout << as_default_int << endl; // default constructor (int)
    cout << as_default_dbl << endl; // default constructor (double)

    cout << "Parameterized Constructor Test:" << endl << endl; // confirmation statement

    ArrayStack<int> as_param_int(2, 2); // paramterized predetermined values (int)
    ArrayStack<double> as_param_dbl(2, 2.2); // paramterized predetermined values (double)

    cout << "Integer:" << endl << endl; // cout confirmation
        cout << as_param_int << endl << endl; // paramterized constructor (int)

    cout << "Double:" << endl << endl; // cout confirmation
        cout << as_param_dbl << endl << endl; // paramterized constructor (double)

    cout << "Copy Constructor Test:" << endl << endl; // confirmation statement

    ArrayStack<int> as_copy_int(as_param_int); // copy declaration (int)
    ArrayStack<double> as_copy_dbl(as_param_dbl); // copy declaration (double)

    cout << "Integer:" << endl << endl; // cout confirmation
        cout << as_copy_int << endl << endl; // copy constructor (int)
    
    cout << "Double:" << endl << endl; // cout confirmation
        cout << as_copy_dbl << endl << endl; // copy constructor (double)

   cout << "\n" <<
        "*****************************\n"
        "**  Method/Operator Tests  **\n" <<
        "*****************************" << endl << endl; // cout labeling

    cout << "Assignment Operator Test:" << endl << endl; // confirmation statement

    ArrayStack<int> as_assign_int; // ArrayStack declaration (int)
    ArrayStack<double> as_assign_dbl; // ArrayStack declaration (double)

    as_assign_int = as_param_int; // assignment to paramterized constructor (int)
    as_assign_dbl = as_param_dbl; // assignment to paramterized constructor (double)

    cout << "Integer:" << endl << endl; // cout confirmation
        cout << as_assign_int << endl << endl; // assigned data (int)

    cout << "Double:" << endl << endl; // cout confirmation
        cout << as_assign_dbl << endl << endl; // assigned data (double)

    cout << "Push and Pop Tests:" << endl << endl; // confirmation statement

    cout << "Integer:" << endl << endl; // cout confirmation
        as_assign_int.push(3); // push() function
        cout << as_assign_int << endl << endl; // push() data

        as_assign_int.pop(); // pop() function
        cout << as_assign_int << endl << endl; // pop() data

    cout << "Double:" << endl << endl; // cout confirmation
        as_assign_dbl.push(3.3); // push() function
        cout << as_assign_dbl << endl << endl; // push() data

        as_assign_dbl.pop(); // pop() function
        cout << as_assign_dbl << endl << endl; // pop() data

    cout << "\n" <<
            "////////////////////////////////\n" <<
            "/////   Testing Concluded   ////\n" <<
            "////////////////////////////////" << endl << endl; // test label design

    cout << "\n" <<
            "****************\n"
            "**  Goodbye!  **\n" <<
            "****************" << endl << endl; // cout labeling
            
    return 0; // end of program
}
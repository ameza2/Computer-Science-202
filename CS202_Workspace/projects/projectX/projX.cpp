// Abraham Meza //
// This file is a test driver for testing dynamic memory in conjunction to SmartPtr prescribed in Project X of CS-202 //

// header files
#include <iostream>

// custom header files
#include "SmartPtr.h"
#include "DataType.h"

using namespace std;

int main() {
      cout << "\n" <<
            "////////////////////////////////\n" <<
            "/////   Constructor Tests  /////\n" <<
            "////////////////////////////////" << endl << endl; // test label design

      SmartPtr sp1; // smartpointer declaration (1)

      DataType * dtp1 = new DataType; // pointing variable to DataType (default constructor)
      SmartPtr sp2(dtp1); // parameterized constructor in relation to first pointer

      SmartPtr sp4(sp2); // copy constructor in relation to second pointer

      cout << "\n" <<
            "///////////////////////////////\n" <<
            "/////   Assignment Tests  /////\n" <<
            "///////////////////////////////" << endl << endl; // test label design

      SmartPtr sp5; // new SmartPtr (allocation)
      sp5 = sp2; // assignment operator (same data, but with different count)

      cout << "\n" <<
            "///////////////////////////////\n" <<
            "/////   Star/Arrow Tests  /////\n" <<
            "///////////////////////////////" << endl << endl; // test label design

      DataType * dtp2 = new DataType(5, 10.0); // re-evaluating 2nd pointer to match given values 
      SmartPtr sp6(dtp2); // constructing 6th pointer to data of 2nd pointer
      cout << *sp6 << endl; // printing current position @ 5
      sp6->setIntVal(3); // int value assignment
      cout << *sp6 << endl; // printing current position @ 3

      cout << "\n" <<
            "////////////////////////////////\n" <<
            "/////   Destructor Tests  //////\n" <<
            "////////////////////////////////" << endl << endl; // test label designs
      
      cout << "End-of-Scope, Destructors called in order of SmartPtr creation.\n" << endl;

      return 0; // end of program
}
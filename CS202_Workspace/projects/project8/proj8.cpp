// Abraham Meza //
// This file is a test driver for testing Lists in conjunction to Arrays and Nodes prescribed in Project 8 of CS-202 //

// header file(s)
#include <iostream>

// custom header file(s) 
#include "ArrayList.h"
#include "NodeList.h"

using namespace std;

int main(){
  /* Your test driver code here */
  cout << "\n" <<
            "/////////////////////////\n" <<
            "/////  Test Driver  /////\n" <<
            "/////////////////////////" << endl << endl; // test label design

  // declaring and assigning different predetermined DataType information

  DataType dt1(1, 2.0);
  DataType dt2(2, 4.0);
  DataType dt3(3, 6.0);
  DataType dt4(4, 8.0);
  DataType dt5(5, 10.0);
  NodeList nl(5, dt1);

  Node *tmp = NULL; // declaring/assinging temp node pointer object to NULL

  nl[0] = dt2; // assigning DataType (2) to nodeList
  nl[3] = dt3; // assigning DataType (3) to nodeList

  cout << "ORIGINAL DATA" << endl << endl; // confirmation/organization statement

  cout << nl << endl << endl; // printing original data

  cout << "INSERTION OF SPECIFIED DATA TYPE (BEFORE)" << endl << endl; // confirmation/organization statement

  nl.insertBefore(dt2, dt4); // calling NodeList insertionBefore
  cout << nl << endl << endl; // printing modified data 

  cout << "DELETING SPECIFIED DATA TYPE" << endl << endl; // confirmation/organization statement

  while ((tmp = nl.erase(dt1))); // deleting targeted data

  cout << nl << endl << endl; // printing modified data

  cout << "CLEARING LIST OF CONTENTS" << endl << endl; // confirmation/organization statement

  NodeList nl2;
  nl.clear(); // calling NodeList clear to clear Node data

  return 0; // end of program
}

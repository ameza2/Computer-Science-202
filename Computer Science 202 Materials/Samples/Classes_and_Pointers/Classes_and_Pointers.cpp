/**
 * @brief  CS-202 Classes and Pointers Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   February, 2019
 *
 * This file shows a sample implementation of the Pointer-based manipulation combined with simple and composite Class objects for the purposes of CS-202
 */

#include <iostream>

#include <cstring>  // Only for demonstration purposes, you are not allowed to use cstring and its built-in functions

using namespace std;

/*
 * Class Car - Default Ctor, Parametrized Ctor, Get/Set Methods
 */
const char * Car_Default_Plates = "XXX-XXX";

class Car{
  public:
    Car();
    Car(const char * plates);
	
    const char * getPlates() const;
    void setPlates(const char * plates);
	
	private:
    char m_plates[256];
};

Car::Car(){
  setPlates(Car_Default_Plates);
}

Car::Car(const char * plates){
  setPlates(plates);
}

const char * Car::getPlates() const {
  return m_plates;
}

void Car::setPlates(const char * plates) {
  strcpy(m_plates, plates);
}


/*
 * Struct Agency - Contains array of Class Car Objects
 */
struct Agency{
  Car list[3];
};

int main()
{
   
   /*
    * One Agency, access its Car(s) array elements through a pointer (p_Car) in order to input / output data
    */
   cout << "Simple Agency case. Input License Plate (Cstrings) for 3 Cars:" << endl;
   // Make single Agency
   Agency simpleAgency;
   // Make Pointer to Class Car Objects, initialize to Agency's array 1st element
   Car * p_Car = simpleAgency.list;
   // Input - Iterate over all Car Object elements by incrementing Car Object Pointer inside for loop
   for (int i=0; i<3; ++i){
       char in_str[255];
       cin >> in_str; 
       p_Car->setPlates(in_str); // call the currently pointed (by p_Car) Car Object's Set Method 
       ++p_Car; // increment pointer to next element in Car Object list
   }
   // Output - Iterate over all Car Object elements by incrementing a Car Object Pointer inside for loop
   cout << "\nSimple Agency case. Output:" << endl;
   // VERY IMPORTANT: Before iteration, RESET your Car Object Pointer to Agency's array 1st element
   p_Car = simpleAgency.list;
   for (int i=0; i<3; ++i){
       cout << p_Car->getPlates() << endl; // call the currently pointed (by p_Car) Car Object's Get Method 
       ++p_Car; // increment pointer to next element in Car Object list
   }
   
   /*
    * Multiple Agency(ies) in an array, access the Agency elements through a pointer (p_Agency), and then access the corresponding
	* Car(s) array elements through a pointer (p_AgencyCar) in order to input / output data
    */
   cout << "\nArray of Agency(ies) case. Input License Plate (Cstrings) for 2 Agencies x 3 Cars each:" << endl;
   // Make array of mutiple Agency(ies)
   Agency arrAgency[2];
   // Make Pointer to Agency Objects, initialize to arrAgency 1st element
   Agency * p_Agency = arrAgency;
   // Make Pointer to Class Car Objects, initialize to Agency's (as pointed by p_Agency) array 1st element
   Car * p_AgencyCar = p_Agency->list;
   // Iterate over all Agency Object elements in arrAgency array by incrementing pointer inside for loop
   for (int j=0; j<2; ++j){
       // Input - Iterate over all Car Object elements by incrementing pointer inside for loop
       for (int i=0; i<3; ++i){
         char in_str[255];
         cin >> in_str; 
         p_AgencyCar->setPlates(in_str); // call the currently pointed (by p_Car) Car Object's Set Method 
         ++p_AgencyCar; // increment pointer to next element in Car Object list
       }
       ++p_Agency; // increment pointer to next element in Agency Object array
   }
   // Output - Iterate over all Agencies and over all Cars by incrementing Agency Pointer and then Car Object Pointer inside for loops
  cout << "\nArray of Agency(ies) case. Output:" << endl;
   // VERY IMPORTANT: Reset Agency Object Pointer to arrAgency array 1st element
   // AND EQUALLY IMPORTANT: Reset Car Object Pointer to Agency's array 1st element
   p_Agency = arrAgency;  
   p_AgencyCar = p_Agency->list;   
   // Iterate over all Agency Object elements by incrementing pointer inside for loop
   for (int j=0; j<2; ++j){
       // Output - Iterate over all Car Object elements by incrementing pointer inside for loop
       for (int i=0; i<3; ++i){
         cout << p_AgencyCar->getPlates() << endl; // call the currently pointed (by p_Car) Car Object's Get Method 
         ++p_AgencyCar; // increment pointer to next element in Car Object list
       }       
       ++p_Agency; // increment pointer to next element in Agency Object array
   }
   
   return 0;
}

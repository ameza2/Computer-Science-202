// header file declaration
#ifndef RENTAL_AGENCY_H
#define RENTAL_AGENCY_H

// custom header files
#include "RentalCar.h"

// defined values that illustrate the qualifications of the class (max length of string / inventory (car data) size)
#define CAR_COUNT 5
#define MAX_CHAR 256

// Constant Integer Variable for multiple function usage (extra credit) //
const int zip = 00000;

class RentalAgency { // class declaration

    // Friend Operator Overload // 
    friend std::istream & operator>>(std::istream& is, RentalAgency &agency); // Friend Method Operator  (stores RentalAgency class information
    friend std::ostream & operator<<(std::ostream & os, RentalAgency &agency); // Friend Method Operator (prints RentalAgency class information

    private:
        char m_name[MAX_CHAR]; // Agency Name
        int zipcode; // zipcode; extra credit (make into const and reformat code) //
        RentalCar inventory[CAR_COUNT]; // an array of Car objects (used to express the car data as an inventory)
    public:
        RentalAgency(); // defualt constructor

        // Getters //
        const char *getName() const;
        const int getZip() const;

        // Setter(s) //
        void setName(const char * name);

        // Overload Operator(s) //
        RentalCar & operator[] (int i); // read/write agency inventory 

        // Menu Functions //
        void readAllData(); // read data from userInput file
        void printAllData(); // print data from userInput file
        void printAvailableCars(); // print all available car data
        void printSensorCounts(); // print total number of sensor counts (how many of each)
        void mostExpensive(); // print most expensive car to screen and ask user for possible rental
};

#endif 
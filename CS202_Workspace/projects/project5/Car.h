// Abraham Meza //
// header file declaration
#ifndef CAR_H
#define CAR_H

// header files
#include <iostream>

// custom header files
#include "Vehicle.h"

// defined values (max string size)
#define MAX_STRING 256 

class Car : public Vehicle { // class declaration with inheritance to Vehicle class

    private: // private class data
        char m_plates[MAX_STRING]; // car license plates
        int m_throttle; // throttle (car motion)

    public: // public class data
        Car(); // default constructor
        Car(const char *license, const int vin, const float *lla); // parameterized construtor
        Car(const Car &car); // copy constructor

        ~Car(); // destructor 

        Car &operator= (const Car &car); // assignment operator overload (assignment operator = (assigns meember values to calaing object based on car values))

        // Getters //
        const char *getPlates() const;
        int getThrottle() const;

        // Setters // 
        void setPlates(const char *plates);
        void setThrottle(const int throttle);

        // Methods //
        void drive(const int throttle); // toggles vehicle to move based on throttle value
        void move(const float *lla); // records a new LLA location by-Address 

    // Friend Operator Overload (Insertion Operator)
    friend std::ostream &operator<<(std::ostream &os, const Car &car);
};

#endif 
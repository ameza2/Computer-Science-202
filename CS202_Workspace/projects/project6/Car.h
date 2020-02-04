// Abraham Meza //
// header file declaration
#ifndef CAR_H
#define CAR_H

// header files
#include <iostream>

// custom header files
#include "Vehicle.h"

using namespace std;

// defined values (defualt throttle is to stay 0)
#define DEF_THROTTLE 0

class Car : public Vehicle { // class declaration with inheritance to Vehicle class
   private: // private class data
        int m_throttle;  // throttle 

        virtual void serialize(ostream& os); // virtual serialize override method
   
    public: // public class data
        Car(); // defualt constructor
        Car(const float *lla); // parameterized constructor
        Car(const Car &car); // copy constructor

        virtual ~Car(); // virtual destructor

        Car &operator=(const Car &car); // assignment operator overload (Car Data)

        // Getters //
        const int GetThrottle() const;

        // Setters //
        void SetThrottle(const int throttle);

        void drive(const int throttle); // drive method (assigns throttle value)
        virtual void Move(const float *lla); // virtual move method (overrriding the Vehicle Pure virtual move) : makes vehicle move to specifc LLA
};

#endif 
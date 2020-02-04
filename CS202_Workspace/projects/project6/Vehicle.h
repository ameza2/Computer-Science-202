// Abraham Meza //
// header file declaration
#ifndef VEHICLE_H
#define VEHICLE_H

// header files
#include <iostream>

using namespace std;

// defined values (LLA is limited to 3 elements for latitude, longitude, and altitude)
#define LLA_LEN 3

class Vehicle { // class declaration (Vehicle)

    protected: // protected class data
        float m_lla[LLA_LEN]; // LLA - Latitude - Longitude - Altitude Array

    private: // private class data
        virtual void serialize(ostream& os); // virtual void method serialize 

    public:
        Vehicle(); // defualt constructor
        Vehicle(const float *lla); // parameterized constructor
        Vehicle(const Vehicle &vehicle); // copy constructor

        virtual ~Vehicle(); // virtual destructor

        Vehicle &operator=(const Vehicle &vehicle); // assignment operator overload (Vehicle Data)

        // Getters // 
        const float *GetLLA() const;

        // Setters //
        void SetLLA(const float *lla);

        virtual void Move(const float *lla) = 0; // pure virtual move method ()
        
        friend ostream &operator<<(ostream &os, Vehicle &vehicle); // insertion operator overload (calls designated serialize method for printing)
};

#endif 
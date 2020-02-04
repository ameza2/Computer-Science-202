// Abraham Meza //
// header file declaration
#ifndef VEHICLE_H
#define VEHICLE_H

// header files
#include <iostream>

// defined values (LLA is limited to 3 elements for latitude, longitude, and altitude)
#define LLA 3

class Vehicle { // Class Declaration (Vehicle)

    protected: // protected class data 
        float m_lla[LLA]; // LLA - Latitude - Longitude - Altitude Array
        const int m_vin; // vin (Vehice Identification Number)

    private: // private class data 
        static int s_idgen; // active object count
        
    public: // public class data
        Vehicle(); // default constructor
        Vehicle(const int vin, const float *lla); // parameterized constructor
        Vehicle(const Vehicle &vehicle); // copy constructor

        ~Vehicle(); // destructor

        Vehicle &operator= (const Vehicle &vehicle); // assignment operator overload (assignment operator = (assigns meember values to calaing object based on vehicle values))

        // Getters //
        const float *getLLA() const;
        int getVIN() const; //
        static int getIdgen();

        // Setters
        void setLLA(const float *lla);
        void setLLA(const int lat, const int lng, const int alt);

        // Methods //
        void move(const float *lla); // records a new LLA location by-Address 
        static bool validateVIN(const int vin); // check VIN validity against s_idgen

    // Friend Operator Overload (Insertion Operator)
    friend std::ostream & operator<<(std::ostream & os, const Vehicle & vehicle);
};

#endif
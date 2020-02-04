// Abraham Meza //
// header files
#include <iostream>
#include <cstring>

// custom header files
#include "Vehicle.h"

using namespace std; 

// initalizing s_idgen (count) for global usage
int Vehicle::s_idgen = 0;

Vehicle::Vehicle() : m_vin(s_idgen++) { // default constructor definition (intitializer list vin count)
    cout << "Vehicle #" << m_vin << ": Default-ctor" << endl; // default constructor debug statement
}

Vehicle::Vehicle(const int vin, const float *lla) : m_vin(validateVIN(vin) ? vin : s_idgen++) { // parameterizd constructor (initializer list vin validity)
    cout << "Vehicle #" << m_vin << ": Parameterized-ctor" << endl; // parameterized constructor debug statement
    setLLA(lla); // assigns different value when needed
}


Vehicle::Vehicle(const Vehicle &vehicle) : m_vin(s_idgen++) { // copy constructor definition (initializer lists vin count)
    cout << "Vehicle #" << m_vin << ": Copy-ctor" << endl; // copy constructor debug statement
    setLLA(vehicle.m_lla); // will copy m_lla value 
}

Vehicle::~Vehicle() { // destructor definition
    cout << "Vehicle #" << m_vin << ": Dtor" << endl; // destructor debug statement
}

Vehicle &Vehicle::operator=(const Vehicle &vehicle) { // assignment operator defintiion
    cout << "Vehicle #" << m_vin << ": Assignment" << endl; // assignment operator debug statement

    if (this != &vehicle) { // assignment loop to compare values 
        setLLA(vehicle.m_lla); // assigns new value
    }

    return *this;
}

// Getter Definitions (private variable access) //
const float *Vehicle::getLLA() const {return m_lla;} //
int Vehicle::getVIN() const {return m_vin;}
int Vehicle::getIdgen() {return s_idgen;}

bool Vehicle::validateVIN(const int vin) { // validateVin Defintion (method to check if vin is allowed)

    if (vin >= s_idgen) { // vin must be bigger than count (no double vins)
        s_idgen = vin; // new vin number
        s_idgen++; // must increment, otherwise we might reuse vin in another vehicle
        return true;
    }

    return false;
}

// Setter Definitions (changing private values through public member variables) //
void Vehicle::setLLA(const float *lla) {
    for (int i = 0; i < LLA; i++) { // bracket indexing (assigning elements)
        m_lla[i] = lla[i];
    }
}

void Vehicle::setLLA(const int lat, const int lng, const int alt) {
    m_lla[0] = lat;
    m_lla[1] = lng;
    m_lla[2] = alt;
}

void Vehicle::move(const float *lla) { // move definition
    cout << "Vehicle #" << m_vin << ": CANNOT MOVE - I DON'T KNOW HOW" << endl; // move debug statement
}

ostream &operator<<(ostream &os, const Vehicle &vehicle) { // insertion operator that prints data
    cout << "Vehicle #" << vehicle.m_vin << " @ [" << vehicle.m_lla[0] << ", " << vehicle.m_lla[1] << ", " << vehicle.m_lla[2] << "]" << endl; // prints recorded data to terminal
    
    return os;
}
// Abraham Meza //
// custom header files
#include "Vehicle.h"

Vehicle::Vehicle() { // default constructor definition
    cout << "Vehicle: Default-ctor" << endl; // default constructor confirmation statement
}

Vehicle::Vehicle(const float *lla) { // parameterized constructor definition
    cout << "Vehicle: Parameterized-ctor" << endl; // parameterized constructor confirmation statement 
    SetLLA(lla); // assigns LLA value from argument
}

Vehicle::Vehicle(const Vehicle &vehicle) { // copy constructor definition (copies vehicle data)
    cout << "Vehicle: Copy-ctor" << endl; // default copy constructor confirmation statement
    SetLLA(vehicle.m_lla); // assigning LLA value to Vehicle LLA value
}

Vehicle::~Vehicle() { // destructor definition
    cout << "Vehicle: Dtor" << endl; // destructor confirmation statement
}

Vehicle &Vehicle::operator=(const Vehicle &vehicle) { // assingment operator overload definition
    cout << "Vehicle: Assignment" << endl; // assignment operator overload confirmation statement
    if (this != &vehicle) { // if loop that looks at comparision (if equal data)
        SetLLA(vehicle.m_lla); // sets new LLA value in accordance to Vehicle LLA
    }
    return *this;
}

// Getter Definitions //
const float *Vehicle::GetLLA() const {return m_lla;}

// Setter Definitions //
void Vehicle::SetLLA(const float *lla) {
    if(!lla){
        return;
    }
    int i ;

    for (i = 0; i < LLA_LEN; i++){
        m_lla[i] = lla[i];
    }
}

void Vehicle::serialize(ostream &os) { // serialize method definition
    // Print Format that is advised within instructions (Vehicle) //

    os << "Vehicle @ [";

    int i;

    for (i = 0; i < LLA_LEN - 1; i++){ // for loop used for array manipulation/scanning
        os << m_lla[i] << ", ";
    }

    os << m_lla[i] << "]";
}

void Vehicle::Move(const float * lla){ // move method definition
    SetLLA(lla); // Updates LLA value (passed through inheritance to Car class)
}

ostream &operator<<(ostream &os, Vehicle &vehicle) { // insertion operator overload definition
    vehicle.serialize(os); // serialize method call (printing)
    return os;
}
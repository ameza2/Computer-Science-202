// Abraham Meza //
// header files 
#include <iostream>
#include <cstring>

// custom header files 
#include "Car.h"

using namespace std;

Car::Car() { // default constructor definition
    cout << "Car #" << m_vin << ": Default-ctor" << endl; // default constructor debug statement
    m_throttle = 0; // initalizing throttle
}

Car::Car(const char *license, const int vin, const float *lla) : Vehicle(vin, lla) { // parameterized constructor definition (initializer list w/ inheritance to vehicle data (VIN) (LLA))
    cout << "Car #" << m_vin << ": Parameterized-ctor" << endl; // parameterized constructor debug statement
    setPlates(license); // assinges plate value with license string
}

Car::Car(const Car &car) : Vehicle(car) { // copy constructor definition (intitalizer list w/ inheritance to vehicle data (CAR))
    cout << "Car #" << m_vin << ": Copy-ctor" << endl;
    setPlates(car.m_plates);
}

Car::~Car() { // destructor definition
    cout << "Car #" << m_vin << ": Dtor" << endl; // destructor debug statement
}

Car &Car::operator= (const Car &car) { // assignment operator defintiion
    cout << "Car #" << m_vin << ": Assignment" << endl; // assignment operator debug statement
    if (this != &car) { // assignment loop to compare values 
        setLLA(car.m_lla); // new assignment to m_LLA
        setPlates(car.m_plates); // new assignment to m_plates
    }
    return *this;
}

// Getter Defintions //
const char *Car::getPlates() const {return m_plates;}
int Car::getThrottle() const {return m_throttle;}

// Setter Definitions //
void Car::setPlates(const char *plates) {strcpy(m_plates, plates);}
void Car::setThrottle(const int throttle) {m_throttle = throttle;}

void Car::drive(const int throttle) { // drive definition
    setThrottle(throttle); // assaigns m_throttle value to throttle value
}

void Car::move(const float *lla) { // move definition
    cout << "Car #" << m_vin << ": DRIVE to destination, with throttle @ 75" << endl; // move statement
    drive(75); // drive value
};

ostream &operator<<(ostream &os, const Car &car) { // insertion operator definition
    cout << "Vehicle #" << car.m_vin << " Plates: " << car.m_plates << ", Throttle: " << car.m_throttle << " @ [" << car.m_lla[0] << ", " << car.m_lla[1] << ", " << car.m_lla[2] << "]" << endl; // prints car/vehicle data to screen
    return os;
}
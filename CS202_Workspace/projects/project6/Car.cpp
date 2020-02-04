// Abraham Meza //
// custom header files
#include "Car.h"

Car::Car() { // default constructor definition
    cout << "Car: Default-ctor" << endl; // default constructor confirmation statement
    SetThrottle(DEF_THROTTLE); // initializes throttle value to default (0)
}

Car::Car(const float *lla) : Vehicle(lla) { // parameterized constructor definition w/ initalizer list passing over LLA data from Vehicle class 
    cout << "Car: Parameterized-ctor" << endl; // parameterized constructor confirmation statement 
    SetThrottle(DEF_THROTTLE); // assigns throttle value to default (0)
}

Car::Car(const Car &car) { // copy constructor definition (copies car data)
    cout << "Car: Copy-ctor" << endl; // default copy constructor confirmation statement
    this -> SetThrottle(car.m_throttle); // referencing individual throttle value (arrow operator)
}

Car::~Car() { // destructor definition
    cout << "Car: Dtor" << endl; // destructor confirmation statement
}

Car &Car::operator=(const Car &car) { // assignment operator overload defintion
    cout << "Car: Assignment" << endl; // assignment operator overload confirmation statement
    if (this != &car) { // if loop that looks at comparision (if equal data)
        SetThrottle(car.m_throttle); // sets new throttle value
        SetLLA(car.GetLLA()); // sets new LLA value in accordance to Car LLA
    }
    return *this;
}

// Getter Definitions //
const int Car::GetThrottle() const {return m_throttle;}

// Setter Definitions //
void Car::SetThrottle(const int throttle) {
    if(throttle < 0){
        m_throttle = DEF_THROTTLE;
    } else{
        m_throttle = throttle;
    }
}

void Car::drive(const int throttle) { // car method definition
     SetThrottle(throttle); // overrides throttle vallue with new throttle
}

void Car::serialize(ostream& os) { // serialize method definition
    // Print Format that is advised within instructions //

    os << "Car: Throttle: " << m_throttle << " " << "@ ["; 

    int i;

    for (i = 0; i < LLA_LEN - 1; i++){ // for loop used for array manipulation/scanning
        os << m_lla[i] << ", ";
    }

    os << m_lla[i] << "]";
}

void Car::Move(const float *lla) { // move method definition
    cout << "Car: DRIVE to destination, with throttle @ 75" << endl; // move method confirmation statement
    drive(75); // drive argument value assignment
}
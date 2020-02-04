// header files
#include <iostream>

// custom header files
#include "RentalCar.h"
#include "RentalAgency.h"
#include "CarSensor.h"
#include "proj4.h"

#define CAR_COUNT 5

using namespace std;

RentalCar::RentalCar(){ // default constructor definition
	for (int i = 0; i < MAX_CHAR; i++){ // for loop that defaults char variables to null
        m_make[i] = '\0';
        m_model[i] = '\0';
        m_owner[i] = '\0';
    }

    m_year = 0; // default declarations
    m_baseprice = 0;
    m_finalprice = 0;
    m_available = false;

    updatePrice(); // updatePrice function

    m_sensorCount = 0;
};

RentalCar::RentalCar(const char* make, const char* model, const int year, const float baseprice, const bool available, CarSensor *sensors){ // parameterized constructor
	CarSensor * sensor = m_sensors; // Class pointer declaration and initialization
    
    myStringCopy(m_make, make); // connecting private variables to setters in public scope
	myStringCopy(m_model, model);
	m_year = year;

	m_baseprice = baseprice;
	m_available = available;

    setOwner("\0"); // keeping owner char null since it will be overwritten by file data

    for (int i = 0; i < MAX_SENSORS; i++) { // sensor loop that tracks counts
        *sensor++ = CarSensor(*sensors++);
        m_sensorCount++;
    }

    updatePrice(); // updatePrice function
};

RentalCar::RentalCar(RentalCar & car){ // copy constructor definition
    CarSensor * input = car.getSensors(); // Sensor class pointer declaration and initalization
    CarSensor * output = m_sensors;

    setMake(car.getMake()); // assigning setters to getters
    setModel(car.getModel());
    setYear(car.getYear());
    setBasePrice(car.getBasePrice());
    setAvailability(car.getAvailability());
    setOwner(car.getOwner());

    for (int i = 0; i < MAX_SENSORS; i++) { // recorded sensors
        *output++ = CarSensor(*input++);
    }

    updatePrice(); //updatePrice function

    m_sensorCount = car.m_sensorCount; // assigning sensorCount value to private count
};

// Getter Definitions (private variable access) //
char * RentalCar::getMake() {return m_make;}
char * RentalCar::getModel() {return m_model;}
int RentalCar::getYear() {return m_year;}

CarSensor * RentalCar::getSensors() {return m_sensors;}
int RentalCar::getSensorCount() {return m_sensorCount;}

float RentalCar::getBasePrice() {return m_baseprice;}
float RentalCar::getFinalPrice() {return m_finalprice;}
bool RentalCar::getAvailability() {return m_available;}
char * RentalCar::getOwner() {return m_owner;}

// Setter Definitions (assigning private variables to public setters) //
void RentalCar::setMake(const char * make) {myStringCopy(m_make, make);}
void RentalCar::setModel(const char * model) {myStringCopy(m_model, model);}
void RentalCar::setYear(const int year) {m_year = year;}
void RentalCar::setBasePrice(const float baseprice) {m_baseprice = baseprice;}
void RentalCar::setAvailability(const bool available) {m_available = available;}
void RentalCar::setOwner(const char * owner) {myStringCopy(m_owner, owner);}

float RentalCar::updatePrice(){ // updatePrice() Function Definition (+= m_baseprice with price increase/decrease from sensors)
    float cost = m_baseprice;
    CarSensor * sensors_ptr = m_sensors;

    for (int i = 0; i < MAX_SENSORS; i++, sensors_ptr++) { // for loop that assigns extracost to a certain value (sensor quantity and price)
        cost += sensors_ptr->getExtraCost();
    }

    return m_finalprice = cost; // finalprice 
};

float RentalCar::estimateCost(const int days){ // estimateCost() Function Defintion (prints estiamted cost (number of days))
	return getFinalPrice() * days; // m_finalprice multiplied by number of rental days
};

void RentalCar::print(){ // print() Function Defintion (prints all car information accordingly that was read from the user's file)
    cout << *this << endl;
};

void RentalCar::promptRent(){ // promptRent() Function Definition (providees the user a renting command after seeing the most expensive car rental)
    char choice[MAX_CHAR]; // char array for user input

    cout << "Would you like to rent this car (Yes / No)? "; // userinput for rent request
    cin >> choice;
    cout << endl;

    if (!myStringCompare(choice, "Yes")){ // executes rent() function (changes leassee) if the user indicates "yes"
        rent(); // rent() function
    } else if(!myStringCompare(choice, "yes")){
        rent(); // rent() function
    }
} 

void RentalCar::rent(){ // rent() Function Defintion (asks user for name and executea leassee method operator to add the user as an owner of the rental car)
    char name[MAX_CHAR];

    cout << "Please enter your name (first name): "; // userinput
    cin >> name;
    cout << endl;

    *this + name;

    cout << "Congratulations! The rental was a success! Enjoy!" << endl << endl;
}

RentalCar& RentalCar::operator+(CarSensor &sensor) { // Sensor Method Operator Defintion
    CarSensor * sensors_ptr = m_sensors; // Sensor class pointer declaration and initialization

    for (int i = 0; i < MAX_SENSORS; i++, sensors_ptr++) { // overides empty sensors and adds a designated sensor while updating m_finalprice 
        if (!myStringCompare(sensors_ptr->getType(), "none")) { // for loop that checks number of sensors
            sensors_ptr->setType(sensor.getType());
            m_sensorCount++;
            updatePrice(); // updatePrice function
            break;
        };
    }
    return *this;
};

RentalCar &RentalCar::operator+(const char * owner) { // Lessee Method Operator Defintion (accesses RentalCar class owner elements)
    setOwner(owner);
    setAvailability(false);
    return *this;
};

std::istream & operator>>(std::istream& is, RentalCar& car) { // Friend Method Operator Definition (file reading)
    char c; // char declarations that will read in file data
    char sensor_str[MAX_CHAR];
    char * start = sensor_str, * ptr = start;
    CarSensor sensor; // Sensor class variable

    is >> car.m_year >> car.m_make >> car.m_model >> car.m_baseprice;

    is.get();   // delete space before curly brace
    is.get();   // delete curly brace

    while (is >> noskipws >> c) { // white space loop

        if (c != ' ' && c != '}') {
            *ptr++ = c;
        } else {
            // Ensure null terminator set
            *ptr++ = '\0';

            // Set sensor type and add to car if sensor read in
            if (myStringLength(sensor_str)) {
                sensor.setType(sensor_str);
                car + sensor;
            }

            // Reset sensor string and pointer
            *start = '\0';
            ptr = start;

            // Stop reading at closing curly
            if (c == '}') {
                break;
            }
        }
    }

    is >> skipws >> car.m_available;

    // Owner is only included if car is unavailable
    if (!car.m_available) {
        is >> car.m_owner;
    }

    // Update to final price in case no sensors were read in
    car.updatePrice();

    return is;
};

// Operator Overload //
ostream & operator<<(ostream & os, const RentalCar & car) { // Friend Method Operator that prints car info to the screen from RentalCar class

    os << car.m_year << " " << car.m_make << " " << car.m_model << ", Base Price = $" << car.m_baseprice << ", Final Price = $" << car.m_finalprice << ", Availability: " << boolalpha << car.m_available;
    if (car.m_available == 1){
        cout << ", Owner(s): None";
    } else{
        cout << ", Owner(s): " << car.m_owner;
    }

    return os;
};
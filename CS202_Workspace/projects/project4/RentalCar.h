// header file declaration
#ifndef RENTALCAR_H
#define RENTALCAR_H

// header files
#include <iostream>

// custom header files
#include "CarSensor.h"

using namespace std;

// defined values that illustrate the qualifications of the class (max length of string / inventory (car data) size)
#define MAX_CHAR 256
#define MAX_SENSORS 3

class RentalCar { // class declaration (RentalCar)

    // Friend Operator Overload // 
    friend std::istream & operator >> (std::istream& is, RentalCar& car); // Friend Method Operator (reads file and detects/deletes unecessary information (whitespace/symbols (curlybraces)))

    private:
        char m_make[MAX_CHAR]; // car make
        char m_model[MAX_CHAR]; // car model
        int m_year; // yaer of production

        CarSensor m_sensors[MAX_SENSORS]; // sensor class type array
        int m_sensorCount; // auxilary memeber variable that counts total number of sensors

        float m_baseprice; // price per day (no sensor)
        float m_finalprice; // pric per day (after sensor)
        bool m_available; // availability flag (true/false)
        char m_owner[MAX_CHAR]; // leassee
    public:
        RentalCar(); // default constructor
        RentalCar(const char *, const char *, const int, const float, const bool, CarSensor *sensors); // paramterized constructor (make, model, year, baseprice, sensors)  - implemented availability
        RentalCar(RentalCar &car); // copy constructor

        // Getters //
        char * getMake();
        char * getModel();
        int getYear();

        CarSensor* getSensors(); 
        int getSensorCount();

        float getBasePrice();
        float getFinalPrice();
        bool getAvailability();
        char * getOwner();

        // Setters //
        void setMake(const char *make);
        void setModel(const char *model);
        void setYear(const int year);
        void setBasePrice(const float baseprice);
        void setAvailability(const bool available);
        void setOwner(const char *owner);

        // Menu Functions that reference RentalCar class //
        float updatePrice(); // updates m_finalprice (baseprice / sensors)
        float estimateCost(const int days); // estimates car's cost (number of days)

        void print(); // prints car data to screen
        void promptRent(); // toggles rent request to user
        void rent(); // changes rent flag depending on user input to promptRent() function

        // Method Operators //
        RentalCar& operator+ (CarSensor & sensor); // sensor addition
        RentalCar& operator+ (const char * owner); // leassee addition

        // Operator Overload //
        friend ostream & operator<<(ostream & os, const RentalCar & car); // Friend Method Operator (prints RentalCar information)
};

#endif 
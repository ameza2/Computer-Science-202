// header files
#include <fstream>

// custom header files
#include "RentalAgency.h"
#include "proj4.h"

using namespace std;

// Friend Operator Overload //
std::istream& operator>>(std::istream& is, RentalAgency& agency) { // Friend Method Operator used to store RentalAgency class information
    is >> agency.m_name >> agency.zipcode;

    for (int i = 0; i < CAR_COUNT; i++) {
        is >> agency[i];
    }
    return is;
}

std::ostream & operator<<(std::ostream & os, RentalAgency & agency) { // Friend Method Operator used to print RentalAgency class information
    os << agency.m_name << " " << agency.zipcode << endl << endl;

    for (int i = 0; i < CAR_COUNT; i++) {
        os << agency[i] << endl;
    }

    return os;
}

RentalAgency::RentalAgency():zipcode(zip){ // default constructor w/ initalization list for const zipcode
    for (int i = 0; i < MAX_CHAR; i++){ // for loop that provides a defualt string for agency name ('\0)
        m_name[i] = '\0';
    }
}

// Getters Defintions //
const char* RentalAgency::getName() const {return m_name;}
const int RentalAgency::getZip() const {return zipcode;}

// Setters Definitions //
void RentalAgency::setName(const char* name) {myStringCopy(m_name, name);}

// Operator Overload //
RentalCar & RentalAgency::operator[](int i) { // method operator that allows the user to read and write into the userInput .txt file
    return inventory[i]; // changed inventory
}

void RentalAgency::readAllData(){ // readAllData() Function Definition (reads all data from userInput file)
    char userInput[100]; // char declaration for userInput

    ifstream inputStream; // file declaration sstatement

    cout << "Enter the name of input file: "; // user input
    cin >> userInput;
    cout << endl;

    inputStream.open(userInput); // opening input text file

    while (!inputStream){  // while loop that asks the user to enter a new input file if it could not find one before
        cout << "Error! Unable to open file. Please try a new input file." << endl << endl;

        cout << "Enter the name of input file: "; // user input
        cin >> userInput;
        cout << endl;

        inputStream.open(userInput); // opening input text file
    }

    inputStream >> *this;

    cout << "Data from " << userInput << " was read successfully." << endl << endl; // confirmation

    inputStream.close(); // closing input text file
}

void RentalAgency::printAllData(){ // printAllData() Function Defintion (prints data from userInput file)
    cout << *this;
    cout << endl;
}

void RentalAgency::printAvailableCars(){ // printAvailableCars() Function Definition (print all available car data)
    RentalCar * inv_ptr = inventory; // RentalCar class pointer declaration and initialization

    cout << "Available cars: " << endl;
    for (int i = 0; i < CAR_COUNT; i++, inv_ptr++) { // for loop scanning through car data inventory
        if (inv_ptr->getAvailability()) {
            cout << *inv_ptr << endl;
        }
    }
}

void RentalAgency::printSensorCounts(){ // printSensorCounts() Function Definition (print total number of sensor counts (how many of each))
    char sensorType[MAX_CHAR]; // sensor-type character array declaration
    int sensorCount = 0, gpsCount = 0, cameraCount = 0, lidarCount = 0, radarCount = 0; // variable declaration and reset
    RentalCar * inv_ptr = inventory; // RentalCar class pointer declaration and initalization
    CarSensor * ss_ptr; // CarSensor class pointer declaration and initialization

    for (int i = 0; i < CAR_COUNT; i++,  inv_ptr++) { // nested for loop used to scan through all car data and sorts sensors accordingly while keeping the overall count // Cars //
        ss_ptr = inv_ptr->getSensors();

        for (int j = 0; j < inv_ptr->getSensorCount(); j++, ss_ptr++) { // Sensors //
            myStringCopy(sensorType, ss_ptr->getType()); // sensorType sorting
            
            if (!myStringCompare(sensorType, "gps")) {
                gpsCount++;
            } else if (!myStringCompare(sensorType, "camera")) {
                cameraCount++;
            } else if (!myStringCompare(sensorType, "lidar")) {
                lidarCount++;
            } else if (!myStringCompare(sensorType, "radar")) {
                radarCount++;
            } else if (!myStringCompare(sensorType, " ")) {
                break;
            }
        }
    }
    sensorCount = gpsCount + cameraCount + lidarCount + radarCount; // total sensorCount is equal to all sensors within the car data 

    cout << "Total Number of Sensors for the Agency's Car Fleet: " << sensorCount << endl << endl;
    cout << "Number of GPS sensors: " << gpsCount << endl << "Number of Camera sensors: " << cameraCount << endl << "Number of Lidar sensors: " << lidarCount << endl << "Number of Radar sensors: " << radarCount << endl; // confirmation
    cout << endl;
}

void RentalAgency::mostExpensive(){ // mostExpensive() Function Definition (print most expensive car to screen and ask user for possible rental)
    RentalCar * mostExpensive; // RentalCar class pointer declaration (mostExpensive placeholder)
    RentalCar * inv_ptr = inventory; // RentalCar class pointer declaration and initialization(inventory scanning)

    for (int i = 0; i < CAR_COUNT; i++, inv_ptr++) { // for loop scanning through car data inventory
        if (inv_ptr->getAvailability()) { // nested for loop that replaces placeholder with expensive between two strings 
            if (!mostExpensive || (inv_ptr->getFinalPrice() > mostExpensive->getFinalPrice())) {
                mostExpensive = inv_ptr; // mostExpensive car being carried through inventory
            }
        }
    }

    if (mostExpensive) { 
        cout << "Most expensive available car: " << endl; // print statement of most expensive car (confirmation)
        cout << *mostExpensive << endl << endl;
        mostExpensive->promptRent();
    } else {
        cout << "Unfortunately, there are no available cars at the moment." << endl;
    }
}
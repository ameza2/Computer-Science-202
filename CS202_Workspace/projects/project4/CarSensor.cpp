// header files
#include <iostream>

// custom header files
#include "CarSensor.h"
#include "proj4.h"

using namespace std;

// Global Integer Initialization for multiple usage between functions (usually would be placede in the defualt constructor) //
int CarSensor::gps_cnt = 0;
int CarSensor::camera_cnt = 0;
int CarSensor::lidar_cnt = 0;
int CarSensor::radar_cnt = 0;

CarSensor::CarSensor(){ // defualt constructor defintion
    setType("none"); // default positon of sensor types
};

CarSensor::CarSensor(const char * type){ // parameterized constructor definition
    setType(type); // connecting private variable to setter for initialization
};

CarSensor::CarSensor(const CarSensor & sensor){ // copy constructor definition
	setType(sensor.m_type); // duplicates sensor object
};

// Getter Definitions (private variable access) //
char * CarSensor::getType() {return m_type;}
float CarSensor::getExtraCost() {return m_extracost;}

// Setter Definitions (assigning private variables to public setters) //
void CarSensor::setType(const char *type){
    // instantiated sensors of each type.
    if (!myStringCompare(type, "gps")) {
        CarSensor::gps_cnt++;
        setExtraCost(GPS_PRICE);
    } else if (!myStringCompare(type, "camera")) {
        CarSensor::camera_cnt++;
        setExtraCost(CAMERA_PRICE);
    } else if (!myStringCompare(type, "lidar")) {
        CarSensor::lidar_cnt++;
        setExtraCost(LIDAR_PRICE);
    } else if (!myStringCompare(type, "radar")) {
       CarSensor::radar_cnt++;
        setExtraCost(RADAR_PRICE);
    } else {
        // "none" type
        setExtraCost(NONE);
    }
    
    myStringCopy(m_type, type);
};

void CarSensor::setExtraCost(const float extracost) {m_extracost = extracost;}

// Static Getters Definitions (private variable access) //
int CarSensor::getGPSCount() {return CarSensor::gps_cnt;}
int CarSensor::getCameraCount() {return CarSensor::camera_cnt;}
int CarSensor::getLidarCount() {return CarSensor::lidar_cnt;}
int CarSensor::getRadarCount() {return CarSensor::radar_cnt;}

// Static Resetters Definitions (resetting the sensor values to '0') //
void CarSensor::resetGPSCount() {CarSensor::gps_cnt = 0;}
void CarSensor::resetCameraCount() {CarSensor::camera_cnt = 0;}
void CarSensor::resetLidarCount() {CarSensor::lidar_cnt = 0;}
void CarSensor::resetRadarCount() {CarSensor::radar_cnt = 0;}

// Operator Overload //
ostream & operator<<(ostream & os, const CarSensor & sensor) { // Friend Method Operator that prints sensor info to the screen from RentalCar class
    os << "CarSensor(m_type=" << sensor.m_type << ", m_extracost=" << sensor.m_extracost << ", gps_cnt="
       << CarSensor::getGPSCount() << ", camera_cnt=" << CarSensor::getCameraCount() << ", lidar_cnt=" << CarSensor::getLidarCount()
       << ", radar_cnt=" << CarSensor::getRadarCount() << ")";

    return os;
};

bool operator ==(CarSensor &sen1, CarSensor &sen2) { // Comparison Method Operator Definition (compares two sensors to see if they're the same)
    return !myStringCompare(sen1.getType(), sen2.getType());
}
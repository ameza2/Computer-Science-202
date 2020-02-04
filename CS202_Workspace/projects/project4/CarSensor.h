// header file declaration 
#ifndef CAR_SENSOR_H
#define CAR_SENSOR_H

// header files
#include <iostream>

// custom header files
#include "proj4.h"

using namespace std;

// defined values that illustrate the qualifications of the class (max length of string)
#define MAX_CHAR 256

// Constant Float Variables (m_extracost prices) //
const float GPS_PRICE = 5.0;
const float CAMERA_PRICE = 10.0;
const float LIDAR_PRICE = 15.0;
const float RADAR_PRICE = 20.0;
const float NONE = 0.0;

class CarSensor { // Class Declaration (CarSensor)
    private:
        char m_type[MAX_CHAR]; // sensor type
        float m_extracost; // sensor additonal cost (per day)
        static int gps_cnt; // gps-type sensor
        static int camera_cnt; // camera-type sensor 
        static int lidar_cnt; // lidar-type sensor
        static int radar_cnt; // radar-type sensor
    public:
        CarSensor(); // default constructor
        CarSensor(const char *); // parameterized constructor (sensor-type being instantiated)
        CarSensor(const CarSensor &sensor); // copy constructor

         // Getters //
        char * getType();
        float getExtraCost();

        static int getGPSCount();
        static int getCameraCount();
        static int getLidarCount();
        static int getRadarCount();

        // Setters //
        void setType(const char *type);
        void setExtraCost(const float extracost);

        // Resetters // 
        static void resetGPSCount();
        static void resetCameraCount();
        static void resetLidarCount();
        static void resetRadarCount();

        // Operator Overload //
        friend ostream & operator << (ostream & os, const CarSensor &sensor); // Friend Method Operator (prints CarSensor information)
};

// Method Operator //
bool operator== (CarSensor &sen1, CarSensor &sen2); // Comparison between Sensor Objects

#endif
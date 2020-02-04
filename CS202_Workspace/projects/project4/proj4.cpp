// Abraham Meza - proj4.cpp - Project 4 //
// This program provides the user a menu that illustrates the different functions they can explore during a car rental. 
// The program takes an external text file, containing agencies and high tech car data, and executes specified functions by utilizing pointer arithmetic and abstract data structure manipulation.

// header files 
#include <iostream>
#include <fstream>

// custom header files
#include "proj4.h"
#include "RentalAgency.h"
#include "RentalCar.h"
#include "CarSensor.h"

using namespace std;

int main(){ // int main() program
    RentalAgency agency; // RentalAgency variable declaration (parameter connection)
    ifstream inputStream; // input file declaration (scanning)

    int menu = 0;

    while (1){ // while loop that executes menu while true
        //  Menu Selections //
        cout << "Rental Car User Menu:" << endl;
        cout << "[1] Read data from an input file." << endl;
        cout << "[2] Print all data for the agency and its corresponding cars." << endl;
        cout << "[3] Print the total number of sensors built for the agency's car fleet." << endl;
        cout << "[4] Find the most expensive available car." << endl;
        cout << "[5] Exit program." << endl;

        cout << endl << "Please enter a menu option: "; // user input that declares menu selection
        cin >> menu;
        cout << endl;
        
        switch(menu){ // switch statement(s) to redirect menu selection to certain functions
            case 1:
            {
                agency.readAllData();
                break;
            }
            case 2:
            {
                agency.printAllData();
                break;
            }
            case 3:
            {
                agency.printSensorCounts();
                break;
            }
            case 4:
            {
                agency.mostExpensive();
                break;
            }
            case 5:
            {
                return 0;
            }
            default: // Prevents user from entering anything else except the menu options.
            {
                cout << "Invalid Option!" << endl << endl;
            }
        }
    }
}

// Function Definitions //

// counts characters in str array until a NULL-character '\0' is found, then it returns that number excluding the '\0' one
// the return type size_t represents an unsigned integral number large enough to contain the maximum possible number of a storage size that can appear on a target architecture
size_t myStringLength(const char str[]){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i - 1;
}

// returns 0 when the C-strings match, i.e. their characters are equal one-by-one until a NULL-character '\0' is found in both strings and at the same position as well
// returns a value <= -1 if the first character that does not match has a lower value in str1 than in str2
// returns a value >= 1 if the first character that does not match has a higher value in str1 than in str2
int myStringCompare(const char str1[],const char str2[]){
    int i = 0,j = 0;

    while(str1[i] != '\0' && str2[i] != '\0'){
        if(str1[i]!=str2[i]){
            break;
        }
        i++;
    }
    if(str1[i] < str2[i]){
        return -1;
    }
    else if(str1[i] > str2[i]){
        return 1;
    }
    else{
        return 0;
    }
}

// copies characters from source to destination array until a NULL-character '\0' is found in source, then it NULL-terminates destination too
// returns a pointer to the destination array
char* myStringCopy(char *destination, const char *source){
    char *beginning = destination;

    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return beginning;
}

// appends then content of source to the destination array
// this means that the NULL-terminator of destination is overwritten by the first character of source and a NULL-character '\0' is appended at the end of the concatenated Cstring in destination
// returns a pointer to the destination array
char* myStringcat(char *destination, const char *source){
    char *beginning = destination;

    while(*destination){
        destination++;
    }

    while(*source){
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
    return beginning;
}
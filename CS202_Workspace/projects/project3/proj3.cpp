// Abraham Meza - proj3.cpp - Project 3 //
// This program provides the user a menu that illustrates the different functions they can explore during a car rental. 
// The program takes an external text file, containing agencies and car data, and executes specified functions by utilizing pointer arithmetic and class/structure manipulation.

// header files
#include <iostream>
#include <fstream>

// defined values that illustrate the qualifications of the class/struture (# of entries / max length of letters / # of agencies /  zipcode)
#define MAX_CHAR 256
#define MAX_NUM_AGENCIES 3
#define CAR_COUNT 5
#define ZIP 5

using namespace std;

// String Function Prototypes //

size_t myStringLength(const char str[]);
int myStringCompare(const char str1[],const char str2[]);
char* myStringCopy(char *destination, const char *source);
char* myStringCat(char *destination, const char *source);

// Class Declaration //

class RentalCar {
    private:
        int m_year; // year of production
        char m_make[MAX_CHAR]; // make of car
        char m_model[MAX_CHAR]; //  model of car
        float m_price; // price per day
        bool m_available; // availability flag
    public:
        RentalCar(); // default constructor
        RentalCar(int, const char*, const char*, float, bool); // parameterized constructor
        
        // getters and setters
        bool getAvailable() {return m_available;} // function return vales are located within the same line to reduce lines (could be written as indivudal functions)
        char *getMake()  {return m_make;}
        char *getModel() {return m_model;}
        float getPrice() {return m_price;}
        int getYear() {return m_year;}

        void setAvailable (bool available) {m_available = available;} // assigns private values to another (allows private class manipulation)
        void setMake (char *make) {myStringCopy(m_make, make);}
        void setModel (char *model) {myStringCopy(m_model, model);}
        void setPrice(float price) {m_price = price;}
        void setYear(int year) {m_year = year;}

        void print(); // prints car data
        float estimateCost(int); // estimates car rental cost
};

// Structure Declaration //

struct RentalAgency{
    char name[MAX_CHAR]; // name of agency
    int zipcode[5]; // zipcode of agency
    RentalCar inventory[5]; // inventory of rental agency i.e. number of cars with rental agency
};

// Default constructor
RentalCar::RentalCar() {
   m_year = 0;
   for (int i = 0; i < MAX_CHAR; i++){
       m_make [i] = '\0';
       m_model [i] = '\0';
   }
   m_price = 0.0;
   m_available = false;
}

// Parameterized constructor
RentalCar::RentalCar(int year, const char* make, const char* model, float price,
       bool available = "false") {
   m_year = year;
   myStringCopy(m_make,make);
   myStringCopy(m_model,model);
   m_price = price;
   m_available = available;
}

// Class Functions //

void RentalCar::print() {
   cout << m_year << " ";
   cout << m_make << " ";
   cout << m_model << "," << " ";
   cout << "$" << m_price << " " << "per day" << "," << " ";
   cout << "Available: " << boolalpha << m_available << endl;
}

float RentalCar::estimateCost(int days) {
   return (m_price*days);
}

// Menu Functions //

void inputFile(RentalAgency *aptr);
void printData(RentalAgency *aptr);
void estimatePrice(RentalAgency *aptr);
void mostExpensive(RentalAgency *aptr);
void allAvailable(RentalAgency *aptr);

int main(){
    // Variable Declaration and Initialization //
    int menu = 0;

    // Array of Agencies/Car Declaration //
    RentalAgency agencies[MAX_NUM_AGENCIES]; 
    RentalCar cars[CAR_COUNT];

    RentalAgency *aptr = agencies; // create pointer to first agency in agencies array

    while (1){
        //  Menu Selections //
        cout << "Rental Car User Menu:" << endl;
        cout << "[1] Read data from an input file." << endl;
        cout << "[2] Print out the data of every agency and their corresponding cars." << endl;
        cout << "[3] Estimate car rental cost." << endl;
        cout << "[4] Find the most expensive car between all agencies." << endl;
        cout << "[5] Find and print available car data into a designated output file." << endl;
        cout << "[6] Exit program." << endl;

        cout << endl << "Please enter a menu option: "; // user input that declares menu selection
        cin >> menu;
        cout << endl;
        
        switch(menu){ // switch statement(s) to redirect menu selection to certain functions
            case 1:
            {
                inputFile(aptr); // reads car data from an input file, indicated by the user, and stores infromation
                break;
            }
            case 2:
            {
                printData(aptr); // prints all car data onto terminal 
                break;
            }
            case 3:
            {
                estimatePrice(aptr); // provides an estimated rental cost based on the user's preference
                break;
            }
            case 4:
            {
                mostExpensive(aptr); // identifies the most expensive car between all agencies (data)
                break;
            }
            case 5:
            {
                allAvailable(aptr); // finds all car data with a "true" flag for availability, and prints available data into an output file indicated by the user.
                break;
            }
            case 6:
            {
                return 0; // ends program
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

// Menu Defintions //

void inputFile(RentalAgency *aptr){
    // Variable Declaration and Initialization //
    char userInput[100];

    int tempyear;
    char tempmake[MAX_CHAR];
    char tempmodel[MAX_CHAR];
    float tempprice;
    bool tempavailable; 

    ifstream inputStream; // file declaration sstatement

    cout << "Enter the name of input file: "; // user input
    cin >> userInput;
    cout << endl; 

    inputStream.open(userInput);   // opening input text file

    while (!inputStream){  // while loop that asks the user to enter a new input file if it could not find one before
        cout << "Error! Unable to open file. Please try a new input file." << endl << endl;

        cout << "Enter the name of input file: "; // user input
        cin >> userInput;
        cout << endl;

        inputStream.open(userInput); // opening input text file
    }

    // nested for loop that allows the pointer value of aptr to be directed to each data entry and stores information into agencies/inventory (cars).
    for (int i = 0; i < MAX_NUM_AGENCIES; i++){
        inputStream >> aptr -> name;
        inputStream >> *aptr -> zipcode;
 
        RentalCar *rptr = aptr -> inventory;
        for (int j = 0; j < CAR_COUNT; j++){
            inputStream >> tempyear;
            rptr -> setYear(tempyear);
            inputStream >> tempmake;
            rptr -> setMake(tempmake);
            inputStream >> tempmodel;
            rptr -> setModel(tempmodel);
            inputStream >> tempprice;
            rptr -> setPrice(tempprice);
            inputStream >> tempavailable;
            rptr -> setAvailable(tempavailable);

            rptr++;
        }
        aptr++;
    }
    cout << "Data from " << userInput << " was read successfully." << endl << endl; // confirmation 
}

void printData(RentalAgency *aptr){
    // nested for loop that goes through stored information within agencies/inventory (cars) and prints out data (indexed for convenience)
    for (int i = 0; i < MAX_NUM_AGENCIES; i++){
        cout << "["<<i<<"] " << aptr -> name << " ";
        cout << *aptr -> zipcode << endl << endl;

        RentalCar *rptr = aptr -> inventory;
        for (int j = 0; j < CAR_COUNT; j++){
            cout << "["<<j<<"] ";
            rptr -> print(); // call print function from public class
            rptr++;
        }
        aptr++;
        cout << endl;
    }
}

void estimatePrice(RentalAgency *aptr){
    // pointer declaration
    RentalCar *rptr;

    // Variable Declaration and Initialization //
    int agent;
    int caro;
    int days;

    cout << "Please choose an Agency [index]: "; // userinput (agency)
    cin >> agent;
    cout << endl;

    cout << "Please choose your Car from the Agency [index]: "; // userinput (car)
    cin >> caro;
    cout << endl;

    cout << "Please enter the number of days: "; // userinput (days)
    cin >> days;
    cout << endl;

    // nested for loop that goes through data until the desired perference is found
    for (int i = 0; i < agent + 1; i++){ // (agent + 1) / (caro + 1) are used to fix indexes (0-2) instead of (1-3)
        rptr = aptr -> inventory;
        for (int j = 0; j < caro + 1; j++){
            rptr++;
        }   
        aptr++;  
    }
    // the nested for loop results in an excess of aptr/rptr by 1, so post - decrement is used as a solution to evaluate the indexes.
    aptr--;
    rptr--;

    cout << "The estimated rental cost of " << aptr -> name << "'s " << rptr -> getYear() << " " << rptr -> getMake() << " " << rptr -> getModel() << " " << "is $" << rptr -> estimateCost(days) << "." << endl << endl; // result
}

void mostExpensive(RentalAgency *aptr){
    // pointer declaration (topPrice)
    RentalCar *top;

    // temporaray placeholder for most expensive
    float expensive = 0.0f;

    // nested for loop that goes through data and compares prices to temp placeholder; if greater, temp is assigned the value and pointer "top" keeps track of which data was scanned when expensive car was found.
    for (int i = 0; i < MAX_NUM_AGENCIES; i++) {
        RentalCar *rptr = aptr -> inventory;
        for (int j = 0; j < CAR_COUNT; j++) {
            if ((rptr -> getPrice()) > expensive) { // if this is the most expensive car
                expensive = rptr -> getPrice();
                top = rptr;
            }
            rptr++;
        }
        aptr++;
    }
    cout << "The most expensive car between all " << MAX_NUM_AGENCIES << " agencies is the " << top -> getYear() << " " << top -> getMake() << " " << top -> getModel() << "," << " " << "at $" << expensive << " per day." << endl << endl; // result
}

void allAvailable(RentalAgency *aptr){
    // pointer declaration
    RentalCar *rptr;

    // Variable Declaration and Initialization //
    char userOutput[100];

    int tempyear;
    char tempmake[MAX_CHAR];
    char tempmodel[MAX_CHAR];
    float tempprice;
    bool tempavailable; 

    ofstream outputStream; // file declaration sstatement

    cout << "Enter the name of output file: "; // user input
    cin >> userOutput;
    cout << endl;

    outputStream.open(userOutput);   // opening output text file

    // nested for looop that scans through data to find "true" flag availability; if found, the data is written to a designated output file
    for (int i = 0; i < MAX_NUM_AGENCIES; i++){
        outputStream << aptr -> name << " ";
        outputStream << *aptr -> zipcode << endl;

        rptr = aptr -> inventory;
        for (int j = 0; j < CAR_COUNT; j++){
            if(rptr -> getAvailable() == 0){
            }
            else{
                outputStream << rptr -> getYear() << " ";
                outputStream << rptr -> getMake() << " ";
                outputStream << rptr -> getModel() << " ";
                outputStream << rptr -> getPrice() << " ";
                outputStream << rptr -> getAvailable() << endl;
            }
            rptr++;
        }
        aptr++;
        outputStream << endl;
    }
    outputStream.close(); // closing output text file

    cout << "All available car data has been copied to " << userOutput << "." << endl << endl; // confirmation
}
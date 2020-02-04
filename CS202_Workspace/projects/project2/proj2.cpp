// Abraham Meza - proj2.cpp - Project 2 //
// This program provides the user a menu that illustrates the different functions they can explore during a car rental. 
// The program takes an external text file, filled with car data, and applies it accordingly to the menu options.

// header files
#include <iostream>
#include <fstream>

// defined values that illustrate the qualifications of a file (# of entries / max length of letters)
#define MAX_SIZE 10
#define MAX_ENTRIES 5

using namespace std;

//  Structure Declaration //

struct RentalCar{
int year;
char make[MAX_SIZE];
char model[MAX_SIZE];
float price;
bool available;
};

// Function  Prototypes //

size_t myStringLength(const char str[]);
int myStringCompare(const char str1[],const char str2[]);
char* myStringCopy(char *destination, const char *source);
char* myStringCat(char *destination, const char *source);

//  Menu Protoypes  //

void inputFile (struct RentalCar data[]);
void printFile (struct RentalCar data[], int n);
void outputFile (struct RentalCar data[], int n);
void sort (struct RentalCar data[], int n);
void options (struct RentalCar data[],int n);
void printEstimate (struct RentalCar data[],int n, int num);
void rent (struct RentalCar data[], int n);


int main(){
    // Variable Declaration and Initialization //
    int menu = 0;

    // Structure Array Declaration //
    struct RentalCar data[5];

    //  while loop for continuouse access to menu until user enters "7"
    while(1){
        //  Menu Selections //
        cout << "Rental Car User Menu:" << endl;
        cout << "[1] Read data from file." << endl;
        cout << "[2] Print out all data for all cars." << endl;
        cout << "[3] Print out all data for all cars in an output file." << endl;
        cout << "[4] Sort data for all cars based on price." << endl;
        cout << "[5] Check which cars are available for rent. Recieve an estimate of rental cost." << endl;
        cout << "[6] Rent a car." << endl;
        cout << "[7] Exit program." << endl;

        cout << endl << "Please enter a menu option: "; // user input that declares menu selection
        cin >> menu;
        cout << endl;
        
        switch(menu){ // switch statement(s) to redirect menu selection to certain functions
            case 1:
            {
                inputFile(data); // reads car data from an input file, indicatted by the user, and stores infromation
                break;
            }
            case 2:
            {
                printFile(data, 5); // prints car data onto terminal 
                break;
            }
            case 3:
            {
                outputFile(data, 5); // prints car data into an output file indicated by the user 
                break;
            }

            case 4:
            {
                sort(data, 5); // sorts data in ascending order based on price
                cout << "Data has been organized in ascending order based on price." << endl << endl;
                break;
            }

            case 5:
            {
                options(data, 5); // displays available car rentals and provides an estimate rental cost
                break;
            }

            case 6:
            {
                rent(data, 5); // rents a car based on the user's input
                break;
            }

            case 7:
            {        
                return 0; // when user enters menu option "7", the program ends.
            }

            default: // Prevents user from entering anything else except the menu options.
            {
                cout << "Invalid Option!" << endl << endl;
                break;
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

// appends the content of source to the destination array
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

// Menu Definitions //

void inputFile (struct RentalCar data[]){
    // Variable Declaration and Initialization //
    char userInput[100];
    char avail[7];
    int count = 0;

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

    // while loop that scans through the array of structures and reads in file information
    while(inputStream >> data[count].year >> data[count].make >> data[count].model >> data[count].price >> avail){
       if (avail[0] == '0'){
          data[count].available = false;
       }
       else{
          data[count].available = true;
       }
       count++;
    }
    cout << "Data from " << userInput << " was read successfully." << endl << endl; // confirmation
}

void printFile (struct RentalCar data[], int n){
    // Variable Declaration and Initialization //
    int str[MAX_ENTRIES];

    for(int i = 0;i < MAX_ENTRIES;i++){
        str[i] = i;
    }

    // for loop that scans through the array of structrures and prints data onto terminal
    for (int i = 0; i < n; i++){
        cout << "["<<str[i]<<"]:" << " " << data[i].year << " " << data[i].make << " " << data[i].model << "," << " " << "$" << data[i].price << " " << "per day" << "," << " " << "Available: " ;
        if (data[i].available == 0){    // replacing 0/1 with their corresponding statememts (false/true)
            cout << "false" << endl;
        }
        else {
            cout << "true" << endl;
        }
    }
   cout << endl;
}

void outputFile (struct RentalCar data[], int n){
    // Variable Declaration //
    char userOutput[100];

    ofstream outputStream; // file declaration statement

    cout << "Enter the name of output file: "; // user input
    cin >> userOutput;

    outputStream.open(userOutput); // opens output file

    // for loop that scans through the array of structures and prints data into output file in the original format.
    for (int i = 0; i < n; i++){
      outputStream << data[i].year << " " << data[i].make << " " << data[i].model << " " << data[i].price << " ";
      if (data[i].available == false){ // replaces false/true with their corresponding symbols (0/1)
          outputStream << "0" << endl;
        }
      else{
          outputStream << "1" << endl;
        }
    }

    cout << endl << "Data has been copied to " << userOutput << "." << endl << endl; // confirmation
    outputStream.close(); // closes output file
}

void sort(struct RentalCar data[],int n){
    
    struct RentalCar temp; // temporary struct variable to hold values during copy functions

    // for loop that sorts car data based on price (ascending); checks correlation between prices
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (data[i].price > data[j].price){ // swap algorithm
                temp.year = data[i].year;
                myStringCopy(temp.make,data[i].make);
                myStringCopy(temp.model,data[i].model);
                temp.price = data[i].price;
                temp.available = data[i].available;
                data[i].year = data[j].year;
                myStringCopy(data[i].make,data[j].make);
                myStringCopy(data[i].model,data[j].model);
                data[i].price = data[j].price;
                data[i].available = data[j].available;
                data[j].year = temp.year;
                myStringCopy(data[j].make,temp.make);
                myStringCopy(data[j].model,temp.model);
                data[j].price = temp.price;
                data[j].available = temp.available;
            }
        }
    }
}

void options(struct RentalCar data[],int n){
    // Variable Declaration //
     int num_days;

     sort(data,5); // calls sort function to organize data based on price (low - high)

     cout << "How many days?: " ; // user input
     cin >> num_days;
     cout << endl;

     printEstimate(data,n,num_days); // calls printEstimate function to print available rental cars
}

void printEstimate(struct RentalCar data[],int n, int num){
    // Variable Declaration and Initialization //
    int str[MAX_ENTRIES];

    for(int i = 0;i < MAX_ENTRIES;i++){
        str[i] = i;
    }
    
    // for loop that prints out (available) car data and provides an estimate of rental cost
    for (int i = 0; i < n; i++){
        if (data[i].available == 1){
            cout << "["<<str[i]<<"]:" << " " << data[i].year << " " << data[i].make << " " << data[i].model << "," << " " << "Total Cost: $" << data[i].price * num << endl;
        }
    }
    cout << endl;
}

void rent(struct RentalCar data[], int n){
    // Variable Declaration//
    int index;
    int num;

    cout << "Enter car and number of days (Index Days): "; // user input
    cin >> index >> num;
    cout << endl;

    // if/else loop that indicates whether the user can rent an indicated car
    if (data[index].available == true){
        data[index].available = false;
        cout << "Car Rental was successsful. The total cost will be $"<< data[index].price * num << ". Enjoy!" << endl << endl;
    }
    else {
        cout << "Car is not avaiable for rent." << endl << endl;
    }
}
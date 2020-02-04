// Abraham Meza - proj1.cpp - Project 1 //
// This program opens an external text file, indicateed by the user, and stores the information into a two dimmensional array. It then sorts the information accordingly (string size / alphabetically) and displays it on the terminal screen.//
// Using the sorted infromation, the program creates and writes the content into a seperate file, indicated by the user. //

// header files
#include <iostream>
#include <fstream>

using namespace std;

// defined values that illustrate the qualifications of a file (# of entries / max length of letters)
#define MAX_NAMES 10
#define MAX_SIZE 9

// Function  Prototypes //

void myStringCopy(char destination[],const char source[]);
int myStringLength(const char str[]);
int myStringCompare(const char str1[],const char str2[]);
int lencompStrings(char str1[], char str2[]);

int main(){
  // Variable Declaration and Initilization //
  char userInput[100], lenfile[100], alphafile[100];
  char name[MAX_NAMES][MAX_SIZE], temp[MAX_SIZE];
  int counts = 0, a = 0, placeholder = 0, comp = 0;

  // File Declaration //
  ifstream inputStream;
  ofstream outputStream;

  // user Input (file names)
  cout<<"Enter the name of input file: ";
  cin>>userInput;

  cout<<"Enter the name of output file for sorted data (length): ";
  cin>>lenfile;

  cout<<"Enter the name of output file for sorted data (alphabetical): ";
  cin>>alphafile;

  inputStream.open(userInput);   // opening input text file

  while(inputStream.getline(name[a],MAX_SIZE)){   // streaming the text file (names)
    a++;
  }

  cout<<"Unsorted Data (Original Input Order and Name)"<<endl<<"============================="<<endl;

  for(int i = 0;i < MAX_NAMES;i++){
    cout<<i<<" "<<name[i]<<endl; // displaying unsorted names on terminal screen
  }
  cout<<endl;

  cout<<"Sorted-by-Length Data (Original Input Order and Name)"<<endl<<"============================="<<endl;

  int str[MAX_NAMES];

  for(int i = 0;i < MAX_NAMES;i++){
    str[i] = i;
  }

  // nested for loop  - sorting file content based on string size (least to greatest)
  for(int i = 0;i < MAX_NAMES;i++){
    for(int j = i + 1;j <  MAX_NAMES;j++){
      comp = lencompStrings(name[i],name[j]);
      if(comp == 2){
        myStringCopy(temp,name[i]);
        myStringCopy(name[i],name[j]);
        myStringCopy(name[j],temp);
        placeholder = str[i];
        str[i] = str[j];
        str[j] = placeholder;
      }
    }
    cout<<str[i]<<" "<<name[i]<<endl; // displaying sorted names on terminal screen
  }

  outputStream.open(lenfile); // opening output text file

  for(int i = 0;i < MAX_NAMES;i++){
    outputStream<<str[i]<<" "<<name[i]<<endl ;  // writing sorted names in output text file
  }

  outputStream.close(); // closing output text file
  cout<<endl;

  cout<<"Alphabetically Sorted Data (Original Input Order and Name)"<<endl<<"============================="<<endl;

  //  nested for loop  - sorting file content in alphabetical order
  for(int i = 0;i < MAX_NAMES;i++){
    for(int j = i+1;j < MAX_NAMES;j++){
      comp = myStringCompare(name[i],name[j]);
      if(comp == 1){
        myStringCopy(temp,name[i]);
        myStringCopy(name[i],name[j]);
        myStringCopy(name[j],temp);
        placeholder = str[i];
        str[i] = str[j];
        str[j] = placeholder;
      }
    }
    cout<<str[i]<<" "<<name[i]<<endl; // displaying sorted names on terminal screen
  }

  outputStream.open(alphafile);  // opening output text file

  for(int i = 0;i < MAX_NAMES;i++){
    outputStream<<str[i]<<" "<<name[i]<<"\n"; // writing sorted names in output text file
  }
  outputStream.close(); // closing output text file
  inputStream.close(); // closing input text file
  return 0;
}

// Function Definitions //

// counts characters in array str until a NULL-character '\0' is found, then it returns that number excluding the '\0' one
int myStringLength(const char str[]){
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  return i - 1;
}

// copies characters from source to destination until a NULL- character '\0' is found in source, then it NULL-terminates destination too, and returns
void myStringCopy(char destination[],const char source[]){
  int i = 0;

  while(source[i] != '\0'){
    destination[i] = source[i];
    i++;
  }
  destination[i] = '\0';
}

// returns 0 when the strings match, i.e. their characters are equal one-by-one until a NULL-character '\0' is found in both strings and at the same position as well
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

// uses integer values from myStringLength function and compares two strings; sorts them from least to greatest
int lencompStrings(char str1[], char str2[]){
  int temp;

  if(myStringLength(str1) < myStringLength(str2)){
    return 1;
  }
  else if(myStringLength(str1) > myStringLength(str2)){
    return 2;
  }
  else{
    return 3;
  }
}
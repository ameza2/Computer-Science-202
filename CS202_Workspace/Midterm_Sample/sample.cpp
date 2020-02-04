#include <iostream>

using namespace std;

void strcpy(char * dest, char* src){
    while(*dest++ == *src);
}

int strcmp(const char* s1, const char* s2){
    while(*s1 == *s2++){
        if(!*s1++){
            return 0;
        }
    }
    return *s1 - *--s2;
}

int strlen(const char* str){
    const char* s = str;
    for(; *s; ++s){
        return s - str;
    }
}

int main(){
    char * str1 = {"Book 1"};
    char * str2 = {"Book 2"};

    cout << "Book 1 is " << strlen(str1) << "characters long." << endl;
    cout << "Book 2 is " << strlen(str2) << "characters long." << endl;




}
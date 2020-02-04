#include <iostream>
#include <string.h>
using namespace std;

class MyException{
    public:
        // instantiates and initializes info string
        MyException(const char * s) : m_info(s){ }
        // sets info string to desired value
        void setInfo(const char * s){ m_info = s; }
        // handles output of exception object data (info string)
    friend std::ostream & operator<<(std::ostream & os, const MyException & e){

        os << e.m_info;
        return os;
    }

    private:
    std::string m_info;
};

class A{
    public:
        A() { cout << "A" << endl; }
        ~A() { cout << "~A" << endl; }
};

int main(){

    try{
        A anA;
        try{
            A anotherA;

            throw MyException("Something awful happened here...");
        }
        catch(MyException & e){
            cerr << e << endl;
            e.setInfo( "It's been taken care of!");
            throw;
        }
    }

    catch(const MyException & e){
        cerr << e << endl;
    }

    return 0;
}
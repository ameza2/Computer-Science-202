#include <iostream>
#include <string.h>
using namespace std;

class Base{

    public:
    Base(){ cout << "B" << ++count << endl; }
    ~Base(){ cout << "~B" << --count << endl; }
    protected:
     static size_t count;
};

size_t Base::count = 0;

class Derived : public Base{
public:
Derived(){ cout << "D" << ++d_count << "," << count << endl; }
~Derived(){ cout << "~D" << --d_count << "," << count << endl; }
private:
static size_t d_count;
};

size_t Derived::d_count = 0;

void fB(){
    Base b;
}

void fD(){
    Derived d;
}

int main() {
    fB();
    fD();
    return 0; 
}
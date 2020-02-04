#include <iostream>
#include <string.h>

using namespace std;

int rec (int n) {
    cout << n << " ";
    if (n > 1){
        return rec (n-1) + rec (n-2);
    }
    else{
        return n;
    }
}

int main(){
    int r = rec(4);
    

    cout << endl << r;
    
    return 0;
}
#include <iostream>

#include "MultiArray.h"

using namespace std;

int main(){
  
  size_t size = 0;
  float value = 0.0;
  cout << "Please input the size and the initial element values for the MultiArray object:" << endl;
  cin >> size >> value;

  MultiArray multi_array_0(size, value);
  
  cout << endl << "MultiArray of size " << size << ":" << endl;
  cout << multi_array_0 << endl;

  return 0;
}

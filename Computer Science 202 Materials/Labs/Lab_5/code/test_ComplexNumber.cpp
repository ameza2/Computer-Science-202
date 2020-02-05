#include <iostream>

#include "ComplexNumber.h"

using namespace std;

int main(){
  
  ComplexNumber cn_A(1, 2);
  ComplexNumber cn_B(3, 4);
  cout << "cn_A(1, 2):\t" << cn_A << endl;
  cout << "cn_B(3, 4):\t" << cn_B << endl;

  ComplexNumber cn_C = cn_A + cn_B;
  cout << "cn_C = (cn_A+cn_B):\t" << cn_C << endl;

  return 0;
}


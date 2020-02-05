#include <iostream>

#include "Matrix.h"

using namespace std;

int main(){
  
  // 1. Creation of a Matrix object with all its elements being set to 0 (using the Matrix parametrized ctor)
  Matrix matrix( 0 );
  
  // 2. Inputting values taken by the user (from terminal input) to populate the elements the Matrix object (using the extraction operator>> overload)
  cout<<"Enter elements of 3x3 matrix :"<<endl;
  cin >> matrix;

  // 3. Outputting the elements of the Matrix object to the terminal (using the insertion operator<< overload)
  cout<<"Matrix :"<<endl;
  cout << matrix;

  // 4. Creating another Matrix object that is the transpose of the original Matrix (using a special method named transpose()) - When a matrix is transposed, the elements of each column become the elements of each row
  Matrix transposeMatrix = matrix.transpose();
  // We are also outputting the elements of the transpose matrix here.
  cout << "Matrix Transpose :" << endl;
  cout << transposeMatrix;

  // 5. Checking if the original Matrix is symmetric by checking if it is equal to its transpose Matrix (using the equality-checking operator== overload)
  cout << "The matrix is"<< (matrix==transposeMatrix?" ":" not ") << "symmetric" << endl;
  	
  return 0;
}

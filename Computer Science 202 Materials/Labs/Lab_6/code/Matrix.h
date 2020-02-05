#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

const int MATRIXROWS = 3;
const int MATRIXCOLS = 3;

class Matrix {
 public:
 
  /*
   * parametrized ctor, sets all elements of m_matrix to the same as the argument initialValue
   */
  Matrix(int initialValue);
  
  Matrix transpose() const;
  
  /*
   * equality checking operator overload (class member function)
   */
  bool operator==(const Matrix & rhs) const;
  
  /* 
  * insertion / extraction operator overloads (non-member functions of the class)
  */
  friend std::ostream & operator<<(std::ostream & os, const Matrix & matrix);
  friend std::istream & operator>>(std::istream & is, Matrix & matrix);
  
 private:
  int m_matrix[MATRIXROWS][MATRIXCOLS];
};

#endif //MATRIX_H_

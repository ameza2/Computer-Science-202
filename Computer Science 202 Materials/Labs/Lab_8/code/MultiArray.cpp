#include <iostream>

#include "MultiArray.h"

MultiArray::MultiArray(size_t size, float val)
{ 
  /* your code here */
}

MultiArray::~MultiArray()
{
  /* your code here */
}

std::ostream & operator<<(std::ostream & os, const MultiArray & m){ 
  for (size_t i=0; i<m.m_size; ++i){
    os << m.m_array[i] << " ";  
  }
  os << std::endl;
  return os; 
}


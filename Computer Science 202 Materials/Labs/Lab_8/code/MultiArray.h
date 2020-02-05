#ifndef MULTIARRAY_H_
#define MULTIARRAY_H_

#include <iostream>

class MultiArray {
 public:
  MultiArray(size_t size, float val);
  
  ~MultiArray();

  friend std::ostream & operator<<(std::ostream & os, const MultiArray & m);
  
 private:
  size_t m_size;
  float * m_array;
};

#endif //MULTIARRAY_H_

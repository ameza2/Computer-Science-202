/**
 * @brief  CS-202 DynamicVector class Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   April, 2019
 *
 * This file shows a sample declaration for a class that wraps dynamic memory management through its constructors / destructor / remaining methods for the purposes of CS-202.
 * To be further discussed within the context of the Lab sections. 
 */
 
#ifndef DYNAMICVECTOR_H_
#define DYNAMICVECTOR_H_

#include <iostream>

class DynamicVector {
 public:
  DynamicVector();
  DynamicVector(size_t size, int value=0);
  DynamicVector(const DynamicVector & other);
  ~DynamicVector();

  DynamicVector & operator=(const DynamicVector & rhs);
 
  const DynamicVector operator+(const DynamicVector & rhs) const;
  
  DynamicVector expanded() const;
  
  friend std::ostream & operator<<(std::ostream & os, const DynamicVector & dv);
  
 private:
  size_t m_size;
  int * m_data;
};

#endif //DYNAMICVECTOR_H_

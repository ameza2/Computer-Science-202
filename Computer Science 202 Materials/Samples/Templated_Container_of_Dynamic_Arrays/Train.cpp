/**
 * @brief  CS-202 Structs Sample
 * @author Christos Papachristos (cpapachristos@unr.edu)
 * @date   May, 2019
 *
 * This file shows a sample implementation of a class Template Container that holds a template parameter-defined Array of Dynamically allocated the purposes of CS-202
 */
 
#include <iostream>

using namespace std;

template <class T, size_t N_CART> class Train;
template <class T, size_t N_CART> std::ostream & operator<<(std::ostream & os, const Train<T,N_CART> & car);

template <class T, size_t N_CART = 1>
class Train {
  public:
	Train();
	Train(size_t capacity, const T & item_value = T());
	Train(const Train<T,N_CART> & other);
	~Train();
	
	Train<T,N_CART> & operator=(const Train<T,N_CART> & other);
	
    const T * getCart(size_t i) const;
    T * getCart(size_t i);
  
  // friend function declared as specialization of templated operator
  friend std::ostream & operator<< <> (std::ostream & os, const Train<T,N_CART> & car);
  
  private:
	T * m_carts[N_CART];  // an array of N_CART subarrays containing T objects
	size_t m_capacities[N_CART];  // an array of number of elements per cart
};

template <class T, size_t N_CART>
Train<T,N_CART>::Train(){
    for (size_t i = 0; i < N_CART; ++i){
        m_carts[i] = NULL; // initialize pointers
        m_capacities[i] = 0; // defensive
    }
}

template <class T, size_t N_CART>
Train<T,N_CART>::Train(size_t n_per_cart, const T & item_value){
    for (size_t i = 0; i < N_CART; ++i){ // iterative new needs exception handling
       	// for each pointer allocate a new subarray
		m_carts[i] = new T [ n_per_cart ]; 
		m_capacities[i] = n_per_cart;
		for (size_t j = 0; j < n_per_cart; ++j){
			m_carts[i][j] = item_value;
		}
	}
}

template <class T, size_t N_CART>
Train<T,N_CART>::Train(const Train<T,N_CART> & other){
    for (size_t i = 0; i < N_CART; ++i){ // iterative new needs exception handling
        m_capacities[i] = other.m_capacities[i];
        if (!m_capacities[i])
          continue;
        m_carts[i] = new T [ other.m_capacities[i] ]; // allocate subarray
        for (size_t j = 0; j < m_capacities[i]; ++j){
            m_carts[i][j] = other.m_carts[i][j];
        }
    }
}

template <class T, size_t N_CART>
Train<T,N_CART>::~Train(){
    for (size_t i = 0; i < N_CART; ++i){
		//deleting a pointer to an allocated array, needs delete [] variant
        delete [] m_carts[i]; 
    }
}

template <class T, size_t N_CART>
Train<T,N_CART> & Train<T,N_CART>::operator=(const Train<T,N_CART >& other){
  if (this != &other){ // check for self-assignment
    for (size_t i = 0; i < N_CART; ++i){ // iterative new needs exception handling
		delete m_carts[i]; // deallocate previous memory (if necessary)
		m_carts[i] = NULL; // set pointers to NULL, exception might be thrown later
		m_capacities[i] = other.m_capacities[i];
		if (!m_capacities[i])
          continue;
		// for each pointer allocate a new subarray, sizes are stores in m_capacities
		m_carts[i] = new T [ other.m_capacities[i] ];
		for (size_t j = 0; j < m_capacities[i]; ++j){
			m_carts[i][j] = other.m_carts[i][j];
		}
    }
  }
  // return calling object 
  return *this;
}

template <class T, size_t N_CART>
const T * Train<T,N_CART>::getCart(size_t i) const{
    return m_carts[i];
}

template <class T, size_t N_CART>
T * Train<T,N_CART>::getCart(size_t i){
    return m_carts[i];
}
   
template <class T, size_t N_CART>
std::ostream & operator<<(std::ostream & os, const Train<T,N_CART> & train){
    for (size_t i = 0; i < N_CART; ++i){
        if (train.m_carts[i]){
            for (size_t j = 0; j < train.m_capacities[i]; ++j){
                os << train.m_carts[i][j] << " ";
            }
            os << endl;
        }
    }
    return os;
}

int main()
{
   Train<int,20> train(10,-5); 
   cout << train;
   
   return 0;
}
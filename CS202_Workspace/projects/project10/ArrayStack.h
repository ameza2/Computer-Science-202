// Abraham Meza //

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

// header file(s) //

#include <iostream>

template <class T, size_t MAX_STACKSIZE = 1000> // Template Class Parameters
class ArrayStack; // creation of class

template <class T, size_t MAX_STACKSIZE> // Template Class Parameters
std::ostream & operator << (std::ostream & os, const ArrayStack<T, MAX_STACKSIZE> & stack); // friend operator used for printing class data (insertion)

template <class T, size_t MAX_STACKSIZE> // Template Class Parameters
class ArrayStack { // class skeleton 
    friend std::ostream & operator << <> (std::ostream & os, const ArrayStack<T, MAX_STACKSIZE> & stack); // friend operator used to read and print class data

    public: // public members
        ArrayStack() { // default constructor definition
            m_top = 0; // initalizing m_top to default value (0)
        }

        ArrayStack(size_t count, const T & value) { // parameterized constructor definition
            m_top = 0; // re-assigning m_top to default value (0)
            for (int i = 0; i < count; i++) { // for loop used for arrray indexing to push() predetermined value to front of stack
                push(value); // push() function
            }
        }

        ArrayStack(const ArrayStack & other) { // copy constructor definition
            size_t size = other.size(); // assigning original size of stack to parameterized stack

            m_top = 0; // re-asssigning m-top to default value (0)
            for (int i = 0; i < size; i++) { // for loop used for array indexing to push() parameterized array data
                push(other.m_container[i]); // push() function
            }
        }

        ~ArrayStack() { // destructor definition
            // No implementation required (dynamic memory is not needed)
        }

        ArrayStack &operator=(const ArrayStack & rhs) { // assignment operator definition
            if (this != &rhs) { // if statement: checking to see if arrays have idenitcal information
                clear(); // clear() data for new data transfer

                size_t size = rhs.size(); // assigning original size of stack to parameterized stack
                for (int i = 0; i < size; i++) { // for loop ussed for array indexing
                    push(rhs.m_container[i]); // push() function
                }
            }

            return *this; // returning new Array data
        }

        T & top() { // top() method defintiton
            return m_container[m_top-1]; // returns the top value of the stack
        }

        const T & top() const { // top() methtod definition const
            return m_container[m_top-1]; // returns the top value of the stack
        }

        void push(const T & value) { // push() method definition
            if (!full()) { // if statement: checking if full() not true; if adding value will not exceed the max size allowed for the stack
                m_container[m_top++] = value; // implementing paramterized value to to the top of the stack
            }
        }

        void pop() { // pop() method definition
            if (!empty()) { // if statement: checking if empty() false; if values are within the stack
                m_top--; // new top becomes the value of the one before (elimiantes top value)
            }
        }

        size_t size() const { // size() method definition const
            return m_top; // checking the size of the stack by referencing m_top tracking value
        }

        bool empty() const { // empty() method definition const
            return m_top == 0; // returns comparison statement to check if there is any value within the array (only empty if m_top == 0)
        }

        bool full() const { // full() method definition const
            return size() >= MAX_STACKSIZE; // returns comparison statement to check if size() (m_top val) is equal to or greater than indicated max (if so, stack is full)
        }

        void clear() { // clear() method definition 
            m_top = 0; // m_top reassigned to default value (0); erases all data
        }

        void serialize(std::ostream & os) const { // seriaalize() method defintion const
            size_t containerSize = size(); // creating temp size to carry size() value

            for (int i = containerSize - 1; i >= 0; i--) { // for loop used for array indexing
                os << i << ": " << m_container[i]; // printing stack information

                if (i > 0) { // endl for organization (after each element)
                    os << std::endl;
                }
            }
        }

    private: // private members
        T m_container[MAX_STACKSIZE];
        size_t m_top;
};

template <class T, size_t MAX_STACKSIZE> // Template Class Parameters
std::ostream & operator<<(std::ostream & os, const ArrayStack<T, MAX_STACKSIZE> & stack) { // friend operator (insertion) definition/implementation
    stack.serialize(os); // referencing serialize() format
    return os;
}

#endif
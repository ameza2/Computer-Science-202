// Abraham Meza//

// custom header file(s) //
#include "ArrayQueue.h"

ArrayQueue::ArrayQueue() { // defualt constructor definition        // (1)
    // initalizing all private members to default (0)

    m_front = 0;
    m_back = 0;
    m_size = 0;
}

ArrayQueue::ArrayQueue(size_t count, const DataType &value) { // parameterized constructor definition       // (2)
   // assigning all members to default (0) 
    
    clear();

    /*m_front = 0;
    m_back = 0;
    m_size = 0;*/

    for (int i = 0; i < count; i++) { // for loop (push)        // (3)
        push(value);
    }
}

ArrayQueue::ArrayQueue(const ArrayQueue &other) { // copy constructor defintion     // (4)
    // assigning all variables to parameterized data 

    m_front = other.m_front; 
    m_back = other.m_front;
    m_size = 0;

    for (int i = 0; i < other.m_size; i++) { // for loop (push); after pushes have been enacted, both arrays will be identical      // (5)
        push(other.m_array[i + other.m_front]); // pushing array elementds
    }
}

ArrayQueue::~ArrayQueue() { // destructor definiton (none since dynamic memory is not required in scenario)     // (4)
}

ArrayQueue &ArrayQueue::operator=(const ArrayQueue &rhs) { // assignment operator defintion     // (5)
    if (this != &rhs) { // if statement checking to see if array data is identical

        clear(); // clearing old/un-needed data

        // assigning all variables to parameterized data 

        m_front = rhs.m_front;
        m_back = rhs.m_front;
        m_size = 0;

        for (int i = 0; i < rhs.m_size; i++) { // for loop (push); after pushes have been enacted, both arrays will be identical
            push(rhs.m_array[i + rhs.m_front]); // pushing array elements
        }
    }

    return *this; // returning new array data
}

DataType &ArrayQueue::front() { // front method definition      // (6a)
    return m_array[m_front]; // retrieving and returning first element of array 
}

const DataType &ArrayQueue::front() const { // front method definition const        // (6b)
    return m_array[m_front]; // retrieving and returning first element of array 
}

DataType &ArrayQueue::back() { // back method definition        // (7a)
    return m_array[m_back]; // retreiving and retunring last element of array
}

const DataType &ArrayQueue::back() const { // back method const     // (7b)
    return m_array[m_back]; // retreiving and returning last element of array
}

void ArrayQueue::push(const DataType &value) { // push method defintion (adds element to back of queue)     // (8)
    if (m_size != ARRAY_MAX) { // if statement; checking if element can fit (does not exceed max space)

        if (!empty()) { // if statement to check if array is not empty
            m_back = (m_back + 1) % ARRAY_MAX;
        }

        m_array[m_back] = value; // adding passed valuee to back of array queue
        m_size++; // incrementing size
    }
}

void ArrayQueue::pop() { // pop() method definition (removes element from front of queue)     // (9)
    if (!empty()) { // if statement to check if array if not empty
        m_front = (m_front + 1) % ARRAY_MAX; 
        m_size--; // decrementing size
    }
}

size_t ArrayQueue::size() const { // size() method defintion      // (10)
    return 0; // size() provides size of array
}

bool ArrayQueue::empty() const { // empty() method definiton      // (11)
    return m_size == 0; // checking m_size to see size of array (bool; 0 is empty, anything else means its not empty)
}

bool ArrayQueue::full() const { // full() method definiton        // (12)
    return m_size == ARRAY_MAX; // checks if m_size is the same size as the max int of elements allowed (bool; is yes, full, if not, not full)
}

void ArrayQueue::clear() { // clear() method definiton        // (13)
    // reassigns all values to 0; resetting array elements

    m_front = 0;
    m_back = 0;
    m_size = 0;
}

void ArrayQueue::serialize(std::ostream &os) const { // serialize method definition (insertion ostream)     // (14)
    for (int i = 0; i < m_size; i++) { // for loop (array indexing)
        os << i << ": " << m_array[i + m_front]; // printing queue data

        if (i != m_size - 1) {
            os << std::endl; // spacing
        }
    }
}

std::ostream &operator<<(std::ostream &os, const ArrayQueue &arrayQueue) { // insertion operator overload (links infromation to serialize for printing)     // (i)
    arrayQueue.serialize(os);
    return os;
}
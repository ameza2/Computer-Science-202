// Abraham Meza //

// custom header file(s) //

#include "ArrayList.h"

using namespace std;

/* Your implementation here */

ArrayList::ArrayList() { // default constructor definition
    m_array = NULL; // assinging defualt value (NULL)
    m_size = 0; // assinging defualt value (0)
    m_maxsize = 0; // assinging defualt value (0)
}

ArrayList::ArrayList(size_t count, const DataType &value) { // parameterized constructor defintion
    m_array = new DataType[count];
    for (int i = 0; i < count; i++) { // for loop [array indexing (institating)]
        m_array[i] = value;
    }
    m_size = count; // institating list object to private member
    m_maxsize = count; // institating list object to private member
}

ArrayList::ArrayList(const ArrayList &other) { // copy constructor definition
    m_array = new DataType[other.m_size];
    for (int i = 0; i < other.m_size; i++) { // for loop [array indexing (assinging other value)]
        m_array[i] = other.m_array[i];
    }
    m_size = other.m_size; // assigning private member new data from other
    m_maxsize = other.m_maxsize; // assigning private member new data from other
}

ArrayList::~ArrayList() { // destructor definition
    delete [] m_array; // deleteing array memory
}

ArrayList &ArrayList::operator=(const ArrayList &rhs) { // assignment operator overload definition
    if (this != &rhs) { // if statement checking for identical data
        delete [] m_array; // deleting array memory

        // assigning new data from passed object //

        m_array = rhs.m_array;
        m_size = rhs.m_size;
        m_maxsize = rhs.m_maxsize;
    }

    return *this; // returning new/old data
}

DataType *ArrayList::front() { // front method definition
    for (int i = 0; i < m_size; i++) { // for loop [array indexing]
        if (m_array[i].getIntVal() && m_array[i].getDoubleVal()) { // if data present, returns to first valid element
            return &m_array[i];
        }
    }

    return NULL; // if none found, return NULL (empty)
}

DataType *ArrayList::back() { // back method definition
    for (int i = m_size; i > 0; i--) { // for loop [array indexing]
        if (m_array[i].getIntVal() && m_array[i].getDoubleVal()) { // if data present, returns to last valid element
            return &m_array[i];
        }
    }

    return NULL; // if none found, return NULL (empty)
}

DataType *ArrayList::find(const DataType &target, DataType *&previous, const DataType *start) { // find method definition
    previous = NULL; // resets previous (NULL)

    for (int i = 0; i < m_size; i++) { // for loop [array indexing]
        if (m_array[i].getIntVal() && m_array[i].getDoubleVal() && m_array[i] == target) { // if statement that checks for targetted value within array

            if (i != 0) { // nothing before head
                previous = &m_array[i-1];
            }

            return &m_array[i]; // return pointer element that matched data
        }
    }

    return NULL; // if none found, return NULL (empty)
}

DataType *ArrayList::insertAfter(const DataType &target, const DataType &value) { // insertAfter method definition
    DataType *previous = NULL; // pointer previous declaration/initalization
    DataType *found = find(target, previous); // pointer found declaration/initalization
    DataType *newElement = NULL; // pointer newElement declaration/initalization
    int OffSet = 0; // integer declaration/initalization

    if (found != NULL) { // if statement executes when found is not NULL

        if (m_size + 1 > m_maxsize) { // if statement that executes if list is full
            DataType *newList = new DataType[m_size + 1];

            for (int i = 0; i < m_size + 1; i++) { // for loop [array indexing]

                if (&m_array[i] == found) { // if statement for found DataType element
                    OffSet = 1;
                    newList[i] = value;
                } else { // if not found
                    newList[i] = m_array[i + OffSet];
                }

            }
        }
    }

    return newElement; // return new element for insertion
}

/* DataType * insertBefore(const DataType & target, const DataType & value){

    *Could not figure out how to create DataType method for insertBefore; was able to implement within NodeList implementation
} 
*/

/* DataType * erase(const DataType & target){

    *Could not figure out how to create DataType method for erasing data; was able to implement within Nodelist implementation
}
*/

DataType &ArrayList::operator[](size_t position) { // bracket operator overload definition
    return m_array[position]; // return accessede element of the array
}

size_t ArrayList::size() const { // size method definition
    return m_size; // returns current size
}

/* bool ArrayList::empty() const{

    *Could not figure out how to create ArrayList method to find if list was empty; was able to impleement within NodeList Implementation
}
*/

/* void ArrayList::clear() const{

    *Could not figure out how to create ArrayList method to clear current list; was able to impleement within NodeList Implementation
}
*/

ostream &operator<<(ostream &os, const ArrayList &arrayList) { // insertion operator overload (prints data to terminal)
    size_t size = arrayList.size();

    for (int i = 0; i < size; i++) { // for loop [array indexing]
        os << i << ": " << arrayList.m_array[i]; // prints data

        if (i != arrayList.size() - 1) {
            os << endl;
        }
    }

    return os;
}
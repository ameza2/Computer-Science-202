// Abraham Meza //

// custom header files
#include "DataType.h"
#include "SmartPtr.h"

using namespace std; 

SmartPtr::SmartPtr() { // default constructor definition
    try { // try/catch statement that allocates new DataType/size_t
        m_ptr = new DataType;
        m_refcount = new size_t;
        *m_refcount = 1;
    } catch (bad_alloc &e) {
        e.what(); // error in memory allocation
    }

    cout << "SmartPtr Default Constructor for new allocation, RefCount = " << *m_refcount << endl; // print statement that displays the actual value pointere-to by m_refcount
}

SmartPtr::SmartPtr(DataType *data) { // parameterized constructor definition: will always create a new m_refcount
    try { // try/catch statement that allocates size_t
        m_refcount = new size_t;
    } catch (bad_alloc &e) {
        e.what(); // error in memory allocation 
    }

    m_ptr = data; // variable assignment to track count of data

    if (data) { // if/else checeking if pointer is valid (1/0)
        *m_refcount = 1;
    } else {
        *m_refcount = 0;
    }

    cout << "SmartPtr Parametrized Constructor from data pointer, RefCount = " << *m_refcount << endl; // print stsatement that displays the actual value pointed-to by m_refcount
}

SmartPtr::SmartPtr(const SmartPtr &other) { // copy constructor definition 
    if (other.m_ptr) { // checking copy object for NULL
        m_refcount = other.m_refcount; // bounded to m_refcount
        (*m_refcount)++; // incrementation to denote that there is an additonal SmartPtr
    } else {
        try { // try/catch statement that reallocates refcount memory
            m_refcount = new size_t;
            *m_refcount = 0;
        } catch (bad_alloc &e) {
            e.what(); // error in memory allocation 
        }
    }

    m_ptr = other.m_ptr; // tracking

    cout << "SmartPtr Copy Constructor, RefCount = " << *m_refcount << endl; // print stsatement that displays the actual value pointed-to by m_refcount
}

SmartPtr::~SmartPtr() { // destructor definition w/ inheritance to refcount: decrements m_refcount in orderr to keep accurate count 
    (*m_refcount)--; // decrementation to denote value pointed behind m_ptr

    if (*m_refcount <= 0) { // if statement that checks if pointed is below 0 count; if so, delete memory
        delete m_ptr; // deletion of memory
        delete m_refcount; // deletion of memory
    }

    cout << "SmartPtr Destructor, RefCount = " << *m_refcount << endl; // print stsatement that displays the actual value pointed-to by m_refcount
}

SmartPtr &SmartPtr::operator=(const SmartPtr &rhs) { // assignment operator definition
    if (this != &rhs) { // if statement that compares object content
        if (--(*m_refcount) <= 0) { // decrement value to point to current object for reassigning (if less than 0: delete memory)
            delete m_ptr; // deletion of memory
            delete m_refcount; // deletion of memory
        }

        if (rhs.m_ptr) {
            m_refcount = rhs.m_refcount; // m_refcount repointed
            (*m_refcount)++; // existing count (increment)
        } else {
            try { // try/catch statement to reallocate new string 
                m_refcount = new size_t;
                *m_refcount = 0;
            } catch (bad_alloc &e) {
                e.what(); // error in memory allocation
            }
        }

        m_ptr = rhs.m_ptr; // m_ptr repointed
    }

    cout << "SmartPtr Copy Assignment, RefCount = " << *m_refcount << endl; // print stsatement that displays the actual value pointed-to by m_refcounts

    return *this;
}

DataType &SmartPtr::operator*() {  // operator overload definition
    return *m_ptr; // return dereferenced dynamic memory object
}

DataType *SmartPtr::operator->() { // operatoe overload definition
    return m_ptr; // return dynamic memory object (access)
}
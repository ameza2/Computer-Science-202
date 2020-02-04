// Abraham Meza //

// custom header file(s) //
#include "NodeQueue.h"

NodeQueue::NodeQueue() { // default constructor definition      // (1)
    // initalizing Node private members to default (NULL) 

    m_front = NULL;
    m_back = NULL;
}

NodeQueue::NodeQueue(size_t size, const DataType &value) { // parameterized constructor definition      // (2)
    // assigning all  members to default (NULL) 

    m_front = NULL;
    m_back = NULL;

    for (int i = 0; i < size; i++) { // for loop (push)
        push(value);
    }
}

NodeQueue::NodeQueue(const NodeQueue &other) { // copy constructor definition       // (3)
    // asasigning all variables to pararmeterized data 
    
    Node * current = other.m_front;

    m_front = NULL;
    m_back = NULL;

    while (current) { // while loop; while current node is available, access and extract data
        push(current->getData()); // retrieving current data
        current = current->m_next; // toggling next data 
    }
}

NodeQueue::~NodeQueue() { // destructor definition      // (4)
    Node *current = m_front; // Node object declaration and initialization (current)
    Node *next = NULL; // Node object declaration and initialization (next)

    while (current) { // while loop; while current node is available; access
        next = current->m_next; // temping next data
        delete current; // deleting current data/memory
        current = next; // moving onto next node 
    }
}

NodeQueue &NodeQueue::operator=(const NodeQueue &rhs) { // assignment operator definition       // (5)
    if (this != &rhs) { // if statement checking if Node data is identical

        clear(); // clearing old/un-needed data

        Node * current = rhs.m_front; // beginning from first element of Node

        m_front = NULL;
        m_back = NULL;

        while (current) { // while loop; while current node is available, access and extract data
            push(current->getData()); // retrieving current data
            current = current->m_next; // toggling next datta
        }
    }

    return *this; // returning new node data
}

DataType &NodeQueue::front() { // front method definition       // (6a)
    return m_front->getData(); // retrieving and returning first element data of node 
}

const DataType &NodeQueue::front() const { // front method definition const     // (6b)
    return m_front->getData(); // retrieving and returning first element data of node 
}

DataType &NodeQueue::back() { // back method definition     // (7a)
    return m_back->getData(); // retreiving and retunring last element data of node
}

const DataType &NodeQueue::back() const { // back method definition const       // (7b)
    return m_back->getData(); // retreiving and retunring last element data of node
}

void NodeQueue::push(const DataType &value) { // push method definition (adds element to back of queue)     // (8)
    Node * newNode = new Node(value); // Node object declaration and initialization

    if (empty()) { // if statement checking if node is empty
        m_front = newNode; // passed value
        m_back = newNode; // passed value
        return;
    }

    m_back->m_next = newNode; // checking if new node element was inserted to back of node
    m_back = newNode; // assigning back of node to new last element
}

void NodeQueue::pop() { // pop() method definition (removes node element from front of queue)       // (9)
    if (size() == 1) { // if statement checking if node is only 1 element
        clear(); // leaves queue empty
    } else if (!empty()) { // else if statement for multiple node elements
        Node * tempFront = m_front; // Node object declaration and initialization (temp front)

        m_front = m_front->m_next; // next element
        delete tempFront; // deleting front data (removing from queue)
    }
}

size_t NodeQueue::size() const { // size() method definition        // (10)
    Node * current = m_front; // Node object declaration and initialization (current)

    size_t i = 0;

    while (current) { // while loop; while current node is available; access 
        i++; // increments size tracking variable
        current = current->m_next; // goes onto next node element
    }

    return i; // returns size of node (i; tracking)
}

bool NodeQueue::empty() const { // empty() method definiton     // (11)
    return m_front == NULL; // checks if front node element is NULL (if yes, node is empty, if no, node has elements)
}

bool NodeQueue::full() const { // full() method definition      // (12)
    return false; // node-based queues have no member limit (can never be full); return false
}

void NodeQueue::clear() { // clear() method definition      // (13)
    Node * current = m_front; // Node object declaration and initialization (current)

    while (current) { // while loop; while current node is available; access 
        pop();
    }

    m_front = NULL; // resetting front element to NULL
    m_back = NULL; // resetting back element to NULL
}

void NodeQueue::serialize(std::ostream &os) const { // serialize method definition (insertion ostream)      // (14)
    Node *current = m_front; // Node object declaration and initialization (current)

    int i = 0; // tracking variable

    while (current) { // while loop; while current node is available; access 
        os << i << ": " << current->getData(); // printing node data

        if (current->m_next) {
            os << std::endl; // spacing
        }

        current = current->m_next;
        i++; // incrementing tracking variable (i)
    } // while loop structured as a for loop
}

std::ostream &operator<<(std::ostream &os, const NodeQueue &nodeQueue) { // insertion operator overload (links infromation to serialize for printing)     // (i)
    nodeQueue.serialize(os);
    return os;
}
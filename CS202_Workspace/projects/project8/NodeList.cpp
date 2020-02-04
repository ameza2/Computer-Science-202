// Abraham Meza //

// custom header file(s) //

#include "NodeList.h"

using namespace std; 

/* Your implementation here */

NodeList::NodeList() { // default constructor definition
    m_head = NULL; // initializing object to default value (NULL)
}

NodeList::NodeList(size_t count, const DataType &value) { // parameterized constructor definition
    Node *next = NULL; // initalizing node next to NULL
    Node *current = NULL; // initalizing node current to NULL

    while (count--) { // while loop 
        if (!next) {
            next = new Node(value); // assigning new node value
        } else {
            current = new Node(value, next); // assigning new node value
            next = current; // next initalized to current value
        }
    }

    m_head = current; // head initalized to current value
}

NodeList::NodeList(const NodeList &other) { // copy constructor definition
    Node *thatCurrent = other.m_head; // copying other.m_head data to "other" current
    Node *thisCurrent = NULL; // initializing current current to NULL
    Node *newNode; // newNode pointer declaration

    while (thatCurrent) { //while loop (checking for other current value)
        newNode = new Node(*thatCurrent); // assigning newNode with current data

        if (!thisCurrent) { // if statement checking if current data is not identical
            // assinging other values to head and current

            m_head = newNode; 
            thisCurrent = m_head;
        } else { // if current is identical
            thisCurrent->m_next = newNode;
            thisCurrent = newNode;
        }

        thatCurrent = thatCurrent->m_next;
    }
}

NodeList::~NodeList() { // destructor definition
    Node *current = m_head;
    Node *next;

    if (m_head) { // if statement checking if m_head is not NULL
        do { // do while loop [going throihg each node]
            next = current->m_next; // next node
            delete current; // deleting node
        } while ((current = next)); // until no more nodes
    }
}

NodeList &NodeList::operator=(const NodeList &rhs) { // assignment operator overload definition
    if (this != &rhs) { // if statement checking if data not identical
        m_head = rhs.m_head; // assigning new head data 
    }

    return *this; // returning new/old data
}

Node *NodeList::front() { // front method definition
    return m_head; // returning head (first element) node of the list
}

Node *NodeList::back() { // back method definition
    Node *current = m_head; // assigning pointer current to m_head data to avoid returning first element

    if (!m_head) { // if statement checking for empty list
        return NULL; // return NULL if empty
    }

    while (current->m_next) { // while loop (goes through nodes until no more)
        current = current->m_next; // current value becomes next value
    }

    return current; // return last (last element) node of the list
}

Node *NodeList::find(const DataType &target, Node *&previous, const Node *start) { // find method definition
    Node *foundNode = NULL; // declaring foundNode pointer (assigning to NULL)
    Node *current = m_head; // declaring current pointer (assigning to current head data)
    Node *pre = NULL; // declaring previous pointer (assinging to NULL)

    previous = NULL; // assigning previous to NULL

    while (current) { // while loop (while nodes are present)

        if (current->data() == target) { // if statement that executes when targetted node data is found
            foundNode = current; // retrieving data
            previous = pre; // retrieving data
            break;
        }

        pre = current; // assigning previous data to (if) found current data
        current = current->m_next; // assinging current to next data 
    }

    return foundNode; // returning found data
}

Node *NodeList::insertAfter(const DataType &target, const DataType &value) { // insertAfter method definition
    // declaring pointer objects that will be used to track target and allign data accoridngly (all assigned to NULL)
  
    Node *previous = NULL;
    Node *found = NULL;
    Node *newNode = NULL;

    found = find(target, previous); // calls find function to look for targeted data

    if (found != NULL) { // if statement that checks if target data was found

        if (found->m_next == NULL) { // if found data is the last element
            newNode = new Node(value);
            found->m_next = newNode;
        } else { // if found anywhere else
            newNode = new Node(value, found->m_next);
            found->m_next = newNode;
        }
    }

    return newNode; // returning newNode order
}

Node *NodeList::insertBefore(const DataType &target, const DataType &value) { // insertBefore method definition
    // declaring pointer objects that will be used to track target and allign data accoridngly (all assigned to NULL)
    
    Node *previous = NULL;
    Node *found = NULL;
    Node *newNode = NULL;

    found = find(target, previous); // calls find function to look for targeted data

    if (found != NULL) { // if statement that checks if target data was found

        if (previous == NULL) { // if previous data is the last element
            newNode = new Node(value, found);
            m_head = newNode;
        } else { // if found anywhere else
            newNode = new Node(value, found);
            previous->m_next = newNode;
        }
    }

    return newNode; // returning newNode order
}

Node *NodeList::erase(const DataType &target) { // erase method definition
    // declaring pointer objects that will be used to track target and allign data accoridngly (all assigned to NULL)
   
    Node *previous = NULL;
    Node *found = NULL;
    Node *next = NULL;
    Node *temp = NULL;

    found = find(target, previous); // calls find function to look for targeted data

    if (found != NULL) { // if statement that checks if target data was found

        if (previous == NULL) { // if previous data is the last element
            temp = m_head;
            next = m_head->m_next;
            m_head = next;
        } else { //if found anywhere else
            temp = found;
            next = found->m_next;
            previous->m_next = next;
        }

        delete temp; // deleting current Node element data
    }

    return next; // returning next Node data (skips old and replaces its position)
}

DataType &NodeList::operator[](size_t position) { // bracket operator overload definition (a)
    Node *current = m_head; // declaring object current pointer to be assigned the value of current head value

    while (position--) { // while loop (decrementing passed position value)
        current = current->m_next; // assigning current to next value
        if (!current) { // if current finds NULL
            break;
        }
    }

    return current->data(); // returning specified element data
}

const DataType &NodeList::operator[](size_t position) const { // bracket operator overload definition (b)
    Node *current = m_head; // declaring object current pointer to be assigned the value of current head value

    while (position--) { // while loop (decrementing passed position value)
        current = current->m_next; // assigning current to next value
        if (!current) { // if current finds NULL
            break;
        }
    }

    return current->data(); // returning specified const element data
}

size_t NodeList::size() const { // size method definition
    Node *current = m_head; // declaring object current pointer to be assigned the value of currrent head value
    size_t size = 0; // declaring/initalizing size int (0)

    while (current) { // while current/element present 
        size++; // size count increments
        current = current->m_next; // current is assinged next element data
    }

    return size; // returning size count value
}

bool NodeList::empty() const { // empty method definition
    return !m_head; // returns bool of state of current head value
}

void NodeList::clear() { // clear method definition
    Node *current = m_head; // declaraing/initializing object current pointer to the value of current head
    Node *next = NULL; // declaring/initializing object next pointer to NULL

    m_head = NULL; // current head value assigned to NULL

    while (current != NULL) { // if statement checking if current data is not NULL
        next = current->m_next; // next pointing to next element data
        delete current; // deleting current data
        current = next; // current assigned to new data from next
    } // deletes data until there is no more data left
}

ostream &operator<<(ostream &os, const NodeList &nodeList) { // insertion operator overload definition
    size_t size = nodeList.size();

    for (int i = 0; i < size; i++) { // for loop [array indexing]
        os << i << ": " << nodeList[i]; // printing data

        if (i != size - 1) {
            os << endl;
        }
    }

    return os;
}
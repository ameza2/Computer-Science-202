// Abraham Meza //

#ifndef NODESTACK_H
#define NODESTACK_H

// header file(s) //

#include <iostream>

template <class T> // Template Class 
class NodeStack; // class creation 

template <class T> // Template Class
std::ostream & operator << (std::ostream & os, const NodeStack<T> & stack); // friend operator used for printing data (insertion)

template <class T> // Template Class
class Node { // class skeleton
    friend class NodeStack<T>; // friend class declaration

    public: // public members
        Node() { // default constructor definition
            m_next = NULL; // initalizing m_next to default value (NULL)
            m_data = T(); // initalizing m_data to defualt value (T() EMPTY)
        };

        Node(const T & data, Node * next = NULL) { // paramterized constructor definition 
            // connecting private members to public values //

            m_next = next;
            m_data = data;
        };

        T & data() { // data() method definition
            return m_data; // returning m_data
        };

        const T & data() const { // data() method definition const 
            return m_data; // returning m_data
        };

    private: // private members
        Node * m_next;
        T m_data;
};

template <class T> // Template Class
class NodeStack { // class skeleton
    friend std::ostream & operator << <> (std::ostream & os, const NodeStack<T> & stack); // friend operator used to read and print class data

    public: // public members
        NodeStack() { // default constructor definition
            m_top = NULL; // initializing m_top to default value (NULL)
        }

        NodeStack(size_t count, const T & value) { // parameterized constructor definition
            m_top = NULL; // re-assigning m_top to default value (NULL)

            for (int i = 0; i < count; i++) { // for loop used for Node indexing/access to push() predetermined data to front of stack
                push(value); // push() function
            }
        }

        NodeStack(const NodeStack & other) { // copy constructor definition
            Node<T> * current; // object pointer declaration (current)
            
            size_t size = other.size(); // assigning original size of stack to parameterized stack

            m_top = NULL; // re-assinging m_top to default value (NULL)

            while (size) { // while loop: execute while size is positive
                current = other.m_top; // current pointer pointing to m_top element of parameterized Node

                for (int i = 0; i < size - 1; i++) { // for loop used for Node indexing/access
                    current = current->m_next; // current pointer pointing to m_next element of parameterized Node
                }

                push(current->data()); // push() pointed data into data()
                size--; // decrementing size (top to bottom)
            }
        }

        ~NodeStack() { // destructor definition
            clear(); // clear() all data/memory (destructor necessary due to Node capability to use infinite data)
        }

        NodeStack & operator=(const NodeStack & rhs) { // assignment operator definition
            if (this != &rhs) { // if statement: checking to see if arrays have idenitcal information
                clear(); // clear() data for new data transfer

                Node<T> * current; // object pointer declaration (current)

                size_t size = rhs.size(); // assigning original size of stack to parameterized stack

                m_top = NULL; // re-assigning m_top to default value (NULL)

                while (size) { // while loop: execute while size is positive
                    current = rhs.m_top; // current pointer pointing to m_top element of parameterized Node

                    for (int i = 0; i < size - 1; i++) { // for loop used for Node indexing/access
                        current = current->m_next; // current pointer pointing to m_next element of parameterized Node
                    }

                    push(current->data()); // push() pointed data into data()
                    size--; // decrementing size (top to bottom)
                }
            }

            return *this; // returning new Node data
        }

        T & top() { // top() method definition
            return m_top->data(); // returning top element of data()
        }

        const T & top() const { // top() method definition const
            return m_top->data(); // returning top element of data()
        }

        void push(const T & value) { // push() method definition
            if (empty()) { // if statement: checking if empty() true; if there are no values within Node 
                m_top = new Node<T>(value); // implements new passed value into Node
            } else {
                m_top = new Node<T>(value, m_top); // implements new passed value into Node and puts it at the top of the stack (m_top)
            }
        }

        void pop() { // pop() method definition
            if (!empty()) { // if statement: checking if empty() false; if there are values within the Node
                Node<T> * tmp = m_top; // object pointer declaration and initalization (pointing to m_top)

                m_top = m_top->m_next; // m_top becomes m_next element of the Node
                delete tmp; // erases pointed data (old m_top)
            }
        }

        size_t size() const { // size() method definition
            Node<T> * current = m_top; // object pointer declaration and initalization (pointing to m_top)

            size_t size = 0; // size assigned to value (0) for tracking purposes

            while (current) { // while loop: checks if element can be accessed in Node
                size++; // size increments (TRACKING)
                current = current->m_next; // object points to m_next element of Node
            }

            return size; // returns size (tracked value)
        };

        bool empty() const { // emtpy() method definition
            return m_top == NULL; // returns comparison statement to check if there is any value within the Node (only empty if m_top == NULL)
        }

        bool full() const { // full() method definition
            return false; // will always return false (Nodes can have infinite data)
        }

        void clear() { // clear() method definition
            Node<T> * current = m_top; // object pointer declaration and initalization (pointing to m_top)

            while(current) { // while loop: checks if element can be accessed in Node
                pop(); // pop() top element of stack (removes/deletes)
                current = current->m_next; // object points to m_next element of Node
            }
        }

        void serialize(std::ostream & os) const { // serialize() method definition const
            Node<T> * current = m_top; // object pointer declaration and initalization (pointing to m_top)

            size_t i = size() - 1; // assinging variable to size of Node

            while (current) { // while loop: checks if element can be accessed in Node
                os << i << ": " << current->data(); // printing stack information

                if (current->m_next) { // endl for organization (after each element)
                    os << std::endl;
                }

                current = current->m_next; // object points to m_next element of Node
                i--; // size decrements (top to bottom)
            }
        }

    private: // private members
        Node<T> * m_top;

};

template <class T> // Template Class
std::ostream & operator<<(std::ostream & os, const NodeStack<T> & stack) { // friend operator (insertion) definition/implementation
    stack.serialize(os); // referencing serialize() format
    return os;
}

#endif 
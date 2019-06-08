/***********************************************************************
* Summary: 
*   Implementation of std::list
************************************************************************/

#ifndef LIST_H
#define LIST_H

#include "node.h"
#include <new>

namespace custom {

/******************************************************************
 * Lists are sequence containers that allow constant time insert and 
 * erase operations anywhere within the sequence, and iteration in 
 * both directions.
 * ****************************************************************/
template<typename T>
class list {
    private:
        Node<T> *pHead;
        Node<T> *pTail;
        int numElements;

    public:
        // constructors
        list() : pHead(nullptr), pTail(nullptr), numElements(0) {}
        list(const list<T> &rhs) : pHead(nullptr), pTail(nullptr), numElements(0){
            *this = rhs;
        }
        ~list() {clear();}
        list<T> &operator=(const list<T> &rhs);
        
        // standard container interfaces
        void clear();
        bool empty() const { return size() == 0; }
        int size() const { return numElements; }

        // iterators
        class iterator;
        class const_iterator;
        class reverse_iterator;
        class const_reverse_iterator;
        iterator begin() { return iterator (pHead); }
        reverse_iterator rbegin() { return reverse_iterator (pTail); }
        const_iterator cbegin() const { return const_iterator (pHead); }
        iterator end() { return iterator (nullptr); }
        reverse_iterator rend() { return reverse_iterator (nullptr); }
        const_iterator cend() const { return const_iterator (nullptr); }
        const_reverse_iterator crbegin() const
        { return const_reverse_iterator (pTail); }
        const_reverse_iterator crend() const
        { return const_reverse_iterator (nullptr); }

        // list-specific interfaces
        void push_front(const T & data);
        void push_back (const T & data);
        T & front() throw (const char *);
        T & back() throw (const char *);
        iterator insert(iterator & it, const T & data);
        iterator erase(iterator it);
        iterator find(const T & t);

        private:
        // nested linked list class
        class Node;

        // member variables
        int numElements; // though we could count, it is faster to keep a variable
        Node * pHead; // pointer to the beginning of the list
        Node * pTail; // pointer to the ending of the list

};




/*************************************************
* LIST REVERSE ITERATOR
* Iterate through a List backwards, non-constant version
************************************************/
template <class T>
class list <T> :: reverse_iterator
{
public:
// constructors, destructors, and assignment operator
reverse_iterator( ) : p(nullptr) { }
reverse_iterator(Node * p ) : p(p) { }
reverse_iterator(const reverse_iterator & rhs) { *this = rhs; }
reverse_iterator & operator = (const reverse_iterator & rhs)
{
p = rhs.p;
return *this;
}

// equals, not equals operator
bool operator == (const reverse_iterator & rhs) const
{ return rhs.p == this->p; }
bool operator != (const reverse_iterator & rhs) const
{ return rhs.p != this->p; }

// dereference operator, fetch a node
T & operator * () throw (const char *)
{
if (p)
return p->data;
else
throw "ERROR: Trying to dereference a nullptr pointer";
}

// postfix increment
reverse_iterator operator ++ (int postfix)
{
reverse_iterator old(*this);
if (p)
p = p->pPrev;
return old;
}

// prefix increment
reverse_iterator & operator ++ ()
{
if (p)
p = p->pPrev;
return *this;
}

// postfix decrement
reverse_iterator operator -- (int postfix)
{
reverse_iterator old(*this);
if (p)
p = p->pNext;
return old;
}

// prefix decrement
reverse_iterator & operator -- ()
{
if (p)
p = p->pNext;
return *this;
}

private:
list <T> :: Node * p;
};

/*************************************************
 * CLEAR
 * Empties the list of all elements There are no parameters
 * and no return values
************************************************/
template<typename T>
void list<T>::clear() {
    while(pHead != pTail) {
        head = head->next;
        delete head -> prev;
    }
    delete head;
    numElements = 0;
}

/*************************************************
 * PUSH FRONT
 * adds an element to the front of a list
************************************************/
template<typename T>
void list<T>::push_front(const T & data) {

}

/*************************************************
 * PUSH BACK
 * adds an element to the back of a list
************************************************/
template<typename T>
void list<T>::push_back (const T & data) {

}

/*************************************************
 * BACK
 * returns element from the front of a list
************************************************/
template<typename T>
T & list<T>::front() {

}

/*************************************************
 * BACK
 * returns element from the back of a list
************************************************/
template<typename T>
T & list<T>::back() {

}






} // end custom namespace

#endif

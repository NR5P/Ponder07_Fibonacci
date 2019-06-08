/***********************************************************************
* Summary: 
*   Implementation of std::list
************************************************************************/

#ifndef LIST_H
#define LIST_H

#include "node.h"

namespace custom {

/******************************************************************
 * Lists are sequence containers that allow constant time insert and 
 * erase operations anywhere within the sequence, and iteration in 
 * both directions.
 * ****************************************************************/
template<typename T>
class List {
    private:
        Node<T> *pHead;
        Node<T> *pTail;
        int numElements;

    public:


};
}

#endif

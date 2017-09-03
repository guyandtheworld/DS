#include "intqueue.h"

BOOL intqueue::Empty() const
{
    return Head == Tail ? TRUE : FALSE;
}

BOOL intqueue::Full() const
{
    return (Tail + 1) % QSize == Head ? TRUE : FALSE;
}

intqueue::intqueue(int queuesize) : 
    QSize(queuesize),
    Element(new int[queuesize]),
    Head(0), Tail(0)
    {}

intqueue::~intqueue()
{
    delete [] Element;
}

BOOL intqueue::Remove(int& TopElem)
{
    if (!Empty()) {
        TopElem = Element[Head];
        Head = (Head + 1) % QSize;
        return TRUE;
    }
    else {
        std::cout << "Queue empty: Remove failed. \n";
        return FALSE;
    }
    
}

BOOL intqueue::Add(const int& NewElem)
{
    if (!Full())
    {
        Element[Tail] = NewElem;
        Tail = (Tail+1) % QSize;
        return TRUE;
    } else {
        std::cout << "Queue full: Add failed. \n";
        return FALSE;
    }
}
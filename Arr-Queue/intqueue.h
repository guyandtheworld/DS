#ifndef INTQUEUE_H
#define INTQUEUE_H
#include <iostream>
typedef int BOOL;

enum {FALSE, TRUE};

class intqueue
{
    protected:
        int QSize;
        int *Element;
        int Head, Tail;
    public:
        BOOL Empty() const;
        BOOL Full() const;
        intqueue(int queuesize = 10);
        virtual ~intqueue();
        virtual BOOL Remove(int& TopElem);
        virtual BOOL Add(const int& NewElem);
};

#endif

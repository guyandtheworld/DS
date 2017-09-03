#ifndef TESTQ_H
#define TESTQ_H
#include "intqueue.h"

class testqueue :: public intqueue
{
    public:
        testqueue(int queuesize = 10);
        void Print() const;
        void Menu() const;
};

#endif
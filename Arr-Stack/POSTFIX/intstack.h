#ifndef INTSTACK_H
#define INTSTACK_H
#include <iostream>

typedef int BOOL;

enum {FALSE, TRUE};

class intstack{
  protected:
	int StackSize;
	int *Element;
	int StackPointer;
  public:
	BOOL Empty() const;
	BOOL Full() const;
	intstack(int stacksize = 10); //Default size for the stack
	virtual ~intstack();                    //Cannot
	virtual BOOL Pop(int& TopElem);         // be
	virtual BOOL Push(const int& NewElem);  // Inherited
};

#endif
                                                                         
#ifndef CHARSTACK_H
#define CHARSTACK_H
#include <iostream>

typedef int BOOL;

enum {FALSE, TRUE};

class charstack{
  protected:
	int StackSize;
	char *Element;
	int StackPointer;
  public:
	BOOL Empty() const;
	BOOL Full() const;
	charstack(int stacksize = 10); //Default size for the stack
	virtual ~charstack();                    //Cannot
	virtual BOOL Pop(char& TopElem);         // be
	virtual BOOL Push(const char& NewElem);  // Inherited
};

#endif

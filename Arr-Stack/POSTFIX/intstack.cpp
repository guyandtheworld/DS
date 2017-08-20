#include "intstack.h"    


BOOL intstack::Empty() const
{
    return StackPointer == -1 ? TRUE : FALSE;
}

BOOL intstack::Full() const
{
    return StackPointer == StackSize+1 ? TRUE : FALSE;
}

intstack::intstack(int stacksize) :
	StackSize(stacksize),
	Element(new int[stacksize]),
	StackPointer(-1)
	{}

intstack::~intstack()
{
	delete [] Element;
}

BOOL intstack::Pop(int& TopElem)
{
    if (!Empty()) {
	TopElem = Element[StackPointer--];
	return TRUE;
    }
    else
    {
	std::cout << "Stack is empty: pop failed.\n";
	return FALSE;
    }
}

BOOL intstack::Push(const int& NewElem)
{
    if (!Full()) {
	Element[++StackPointer] = NewElem;
	return TRUE;
    }
    else
    {
	std::cout<<"Stack full: push failed. \n";
	return FALSE;
    }
}

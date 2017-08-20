#include "charstack.h"

charstack::charstack(int stacksize) :
	StackSize(stacksize),
	Element(new char[stacksize]),
	StackPointer(-1)
	{}

charstack::~charstack()
{
	delete [] Element;
}

BOOL charstack::Empty() const
{
    return StackPointer == -1 ? TRUE : FALSE;
}

BOOL charstack::Full() const
{
    return StackPointer == StackSize+1 ? TRUE : FALSE;
}

BOOL charstack::Pop(char& TopElem)
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

BOOL charstack::Push(const char& NewElem)
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

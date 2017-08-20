#include "intpost.h"
#include "intpost.cpp"

int main()
{
    intpost Postfix;
    Postfix.Read();
    if (Postfix.Evaluate())
        Postfix.PrintAnswer();
    return 0;
}
#ifndef INTPOST_H
#define INTPOST_H
#include "intstack.h"

class intpost
{
    private:
        int answer;
        intstack NumStack;
        char *PostfixExpr;
        int PostfixExprSize; 

        BOOL Operator(const char token) const;
        BOOL ApplyOperator(const char Operator);
    public:
        intpost(int StackSize = 10, int postfixexprsize = 50);
        ~intpost();
        void Read();
        BOOL Evaluate();
        void PrintAnswer() const;
};
#endif

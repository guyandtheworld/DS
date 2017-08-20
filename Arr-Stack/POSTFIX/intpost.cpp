#include "intpost.h"
#include "iostream"

intpost::intpost(int StackSize, int postfixexprsize) : 
    NumStack(StackSize),
    PostfixExpr(new char[postfixexprsize]),
    PostfixExprSize(postfixexprsize)
    {}

intpost::~intpost()
{
    delete [] PostfixExpr;
}

void intpost::Read()
{
    cout << "Enter postfix expression: ";
    cin.getline(PostfixExpr, PostfixExprSize);
}

BOOL intpost::Operator(const char token) const
{
    if (token=='*' || token=='+'||
        token=='-' || token=='/')
        return TRUE;
    return FALSE;
}

BOOL intpost::ApplyOperator(const char Operator)
{
    int operand1, operand2;

    if (!NumStack.Pop(operand1)) return FALSE;
    if (!NumStack.Pop(operand2)) return FALSE;

    switch (Operator) {
        case '*': 
            NumStack.Push(operand2 * operand1);
            break;
        case '+': 
            NumStack.Push(operand2 + operand1);
            break;
        case '-': 
            NumStack.Push(operand2 - operand1);
            break;
        case '/': 
            NumStack.Push(operand2 / operand1);
            break;
        default:
            return FALSE;
    }
    return TRUE
}

BOOL intpost::Evaluate()
{
    int token = 0;

    while (PostfixExpr[token]) {
        if (Operator(PostfixExpr[token])) {
            if (!ApplyOperator(PostfixExpr[token])) {
                cout << "Error: too few operators \n";
                return FALSE;
            }
        }
        else if (int(PostfixExpr[token]) >= int('0')
            && int(PostfixExpr[token]) <= int('9'))
            NumStack.Push(int(PostfixExpr[token]) - int('0'));
        token++;
    }
    if (!NumStack.Pop(Answer)) {
        cout << "Error popping answer.\n";
        return FALSE;
    }
    else if (!NumStack.Empty()) {
        cout << "Error: too many operands.\n";
        return FALSE;
    }
    return TRUE;
}

void intpost::PrintAnswer() const
{
    cout << "Answer = " << Answer << endl;
}
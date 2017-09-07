#include <iostream>
#include <vector>

using namespace std;

class StackX
{
    private:
        int maxSize;
        vector<double> stackVect;
        int top;
    public:
        
        StackX(int size) : maxSize(size), top(-1)
        {
            stackVect.resize(size);
        }

        void push(double i)
        {
            stackVect[++top] = i;
        }

        double pop()
        {
            return stackVect[top--];
        }

        double peek()
        {
            return stackVect[top];
        }

        bool isFull()
        {
            return (top == maxSize-1);
        }

        bool isEmpty()
        {
            return (top == -1);
        }
};


int main() 
{ 
    StackX theStack(10);             //make new stack, size 10 
    theStack.push(20);               //push items onto stack 
    theStack.push(40); 
    theStack.push(60);
    theStack.push(80); 
    while( !theStack.isEmpty() )     //until it’s empty, 
    {                             //delete item from stack 
        double value = theStack.pop();
        cout << value << " ";         //display it 
    }  //end while 
    cout << endl;
    return 0;
}  //end main() 
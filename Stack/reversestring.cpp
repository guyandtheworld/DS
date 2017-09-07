#include <iostream>
#include <vector>
#include <string>

using namespace std;

class StackX
{
    private:
        int maxSize;
        vector<char> stackVect;
        int top;
    public:
        
        StackX(int size) : maxSize(size), top(-1)
        {
            stackVect.resize(size);
        }

        void push(char i)
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

class Reverser
{
    private:
        string in;
        string out;
    public:
        Reverser(string str) : in(str)
        {}

        string doRev()
        {
            int stackSize = in.length();
            StackX stackRev(stackSize);

            for (int i = 0; i < stackSize; i++)
            {
                stackRev.push(in[i]);
            }

            out = "";

            while(!stackRev.isEmpty())
            {
                char ch = stackRev.pop();
                out = out + ch;
            }

            return out;

        }
};

int main() { 
    string input, output;
    while(true) 
    { 
        cout << "Enter a word: ";
        cin >> input;                //read a word from kbd 
        if( input.length() < 2 )     //quit if one character 
        break; //make a Reverser 
        Reverser theReverser(input); 
        output = theReverser.doRev(); //use it 
        cout << "Reversed: " << output << endl; 
    }  //end while 
    return 0; 
}  //end main() 
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
        
        StackX(char size) : maxSize(size), top(-1)
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

class BracketChecker
{
    private:
        string input;
    public:
        BracketChecker(string in) : input(in)
        {}

        void check()
        {
            int size = input.length();
            StackX stack(size);
            bool isError=false;
            for (int i=0; i<size; i++)
            {
                char ch = input[i];
                switch(ch)
                {
                    case '{':
                    case '(':
                    case '[':
                        stack.push(ch);
                        break;
                    case '}':
                    case ')':
                    case ']':
                        if (!stack.isEmpty())
                        {
                            char chx = stack.pop();
                            if ((ch=='}' && chx!='{') ||
                                (ch==')' && chx!='(') ||
                                (ch==']' && chx!='['))
                            {
                                isError = true;
                                cout<<"Mismatch delimiter: "<<ch<<" at "<<i<<endl;
                            }
                        }
                        else
                        {
                            isError = true;
                            cout<<"Mismatch delimiter: "<<ch<<" at "<<i<<endl;
                        }
                        break;
                    default:
                        break;
                }
            }

            if (!stack.isEmpty())
                cout<<"Missing right delimiter."<<endl;
            else if (!isError)
                cout<<"OK"<<endl;
        }
};

int main() 
{ 
    string input;
    while(true)
    {
        cout << "Enter string containing delimiters " << "(no whitespace): ";
        cin >> input;            //read a string from kbd 
        if( input.length() == 1 )   //quit if ‘q’, etc. 
            break; //make a BracketChecker 
        BracketChecker theChecker(input);
            theChecker.check();      //check brackets 
    }  //end while
    return 0; 
}  //end main() 
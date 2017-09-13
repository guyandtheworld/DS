#include <iostream>
#include <vector>
using namespace std;

class Queue
{
    private:
        int maxSize;
        vector <double> queVect;
        int front;
        int rear;
    public:
        Queue(int s) : maxSize(s+1), front(0), rear(-1)
        {
            queVect.resize(s);
        }

        void insert(int j)
        {
            if (rear == maxSize-1)
                rear = -1;
            queVect[++rear] = j;
        }

        int remove()
        {
            int temp = queVect[front++];
            if (front == maxSize)
                front = 0;
            return temp;
        }

        int peekFront()
        {
            return queVect[front];
        }        

        bool isEmpty()
        {
            return (rear+1==front || (front+maxSize-1==rear));
        }

        bool isFull()
        {
            return (rear+2 == front || (front+maxSize-2==rear));
        }

        int size()
        {
            if (rear>=front)
                return rear-front+1;
            else
                return (rear+1) + (maxSize-front);
        }

};

int main() 
{ 
    Queue theQueue(5);              //queue holds 5 items 
    theQueue.insert(10);            //insert 4 items 
    theQueue.insert(20); 
    theQueue.insert(30); 
    theQueue.insert(40); 
    theQueue.remove();              //remove 3 items 
    theQueue.remove();              //   (10, 20, 30) 
    theQueue.remove(); 
    theQueue.insert(50);            //insert 4 more items 
    theQueue.insert(60);            //   (wraps around) 
    theQueue.insert(70); 
    theQueue.insert(80); 
    while( !theQueue.isEmpty() )    //remove and display 
    {                            //   all items 
        int n = theQueue.remove();   //(40, 50, 60, 70, 80) 
        cout << n << " "; 
    } 
    cout << endl; 
    return 0; 
} 
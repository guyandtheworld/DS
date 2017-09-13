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
        int nItems;
    public:
        Queue(int s) : maxSize(s), front(0), rear(-1), nItems(-1)
        {
            queVect.resize(s);
        }

        void insert(int j)
        {
            if (rear == maxSize-1)
                rear = -1;
            queVecy[++rear] = j;
            nItems++;
        }

        int remove()
        {
            int temp = queVect[front++];
            if (front == maxSize)
                front = 0;
            nItems--;
            return temp;
        }

        int peekFront()
        {
            return queVect[front];
        }        

        bool isEmpty()
        {
            return (nItems==0);
        }

        bool isFull()
        {
            return (nItems==maxSize);
        }

        int size()
        {
            return nItems;
        }

};

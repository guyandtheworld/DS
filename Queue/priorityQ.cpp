#include <iostream>
#include <vector>
using namespace std;

class PriorityQ
{
    private:
        int maxSize;
        vector <double> queVect;
        int nItems;
    public:
        PriorityQ(int s) : maxSize(s), nItems(0)
        {
            queVect.resize(s);
        }

        void insert(double item)
        {
            int j;
            if (nItems==0)
                queVect[nItems++] = item;
            else
            {
                for (j = nItems-1; j>=0; j--)
                {
                    if (item > queVect[j])
                    {
                        queVect[j+1] = queVect[j];
                    }
                    else
                    {
                        break;
                    }
                }
                queVect[j+1] = item;
                nItems++;
            }
        }

        double remove()
        {
            return queVect[--nItems];
        }

        double peekMin()
        {
            return queVect[nItems-1];
        }

        bool isEmpty()
        {
            return (nItems==0);
        }

        bool isFull()
        {
            return (nItems==maxSize);
        }
};

int main()
{
    PriorityQ thePQ(5);             //priority queue, size 5 
    thePQ.insert(30);               //unsorted insertions 
    thePQ.insert(50); 
    thePQ.insert(10); 
    thePQ.insert(40); 
    thePQ.insert(20); 
    while( !thePQ.isEmpty() ) 
    {                            //sorted removals 
        double item = thePQ.remove(); 
        cout << item << " ";         //10, 20, 30, 40, 50 
    }  //end while 
    cout << endl; 
    return 0; 
}
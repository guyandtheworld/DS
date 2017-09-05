#include <iostream>
#include <vector>

using namespace std;

class ArrayBub
{
    private:
        vector<double>v;
        int nElems;
        void swap(int pos1, int pos2)
        {
            double temp = v[pos1];
            v[pos1] = v[pos2];
            v[pos2] = temp;
        }

    public:
        ArrayBub(int max) : nElems(0)
        {
            v.resize(max);
        }

        void insert(double value)
        {
            v[nElems] = value;
            nElems++;
        }

        void display()
        {
            for (int i = 0; i < nElems; i++)
            {
                cout<<v[i]<< " ";
                cout<<endl;
            }
        }

        void bubbleSort()
        {
            for (int i = nElems; i > 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    if (v[j]>v[j+1])
                        swap(j, j+1);
                }
            }
        }
};

int main() { 
        int maxSize = 100;
        ArrayBub arr(maxSize);
        arr.insert(77);
        arr.insert(99);
        arr.insert(44);
        arr.insert(55);
        arr.insert(22);
        arr.insert(88);
        arr.insert(11);
        arr.insert(00);
        arr.insert(66);
        arr.insert(33);
        arr.display();
        arr.bubbleSort();              
        arr.display();
    return 0; }  
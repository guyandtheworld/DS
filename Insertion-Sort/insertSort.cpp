#include <iostream>
#include <vector>

using namespace std;

class ArrayIns
{
    private:
        vector<double> v;
        int nElems;

    public:
        ArrayIns(int max);
        void insert(double key);
        void display();
        void insertionSort();
};

ArrayIns :: ArrayIns(int max) : nElems(0)
{
    v.resize(max);
}

void ArrayIns :: insert(double value)
{
    v[nElems] = value;
    nElems++;
}

void ArrayIns :: display()
{
    for(int i = 0; i < nElems; i++)
    {
        cout<<v[i]<< " ";
        cout<<endl;
    }
}

void ArrayIns :: insertionSort()
{   int i, j;
    for (i = 1; i<nElems; i++)
    {
        double temp = v[i];
        j = i;
        while (j>0 && v[j-1]>=temp)
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }    
}


int main() 
{ 
    int maxSize = 100;
    ArrayIns arr(maxSize);       
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
    arr.insertionSort();
    arr.display();
    return 0; 
}
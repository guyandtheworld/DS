#include <iostream>
#include <vector>

using namespace std;

class OrdArray
{
    private:
        vector<double>v;
        int nElems;
    public:
        OrdArray(int max);
        int getSize();
        int find(double key);
        void insert(double key);
        bool remove(double key);
        void display();
};

OrdArray :: OrdArray(int max) : nElems(0)
{
    v.resize(max);
}

int OrdArray :: getSize()
{
    return v.size();
}

int OrdArray :: find(double key)
{   int beg = 0, end = nElems-1, mid;
    mid = (beg+end)/2;
    while (beg<=end)
    {   
        if (v[mid] == key)
            return mid;
        else if (v[mid] < key)
            beg = mid+1;
        else
            end = mid-1;
        mid = (beg+end)/2;
    }
    return nElems;
}

void OrdArray :: insert(double key)
{
    int pos = 0;
    for (pos = 0;pos<nElems; pos++)
        if(key < v[pos])
            break;
    for (int k = nElems; k>pos; k--)
    {
        v[k] = v[k-1];
    }
    v[pos] = key;
    nElems++;
}

bool OrdArray :: remove(double key)
{
    int pos = find(key);
    if (pos == nElems)
        return false;
    else
    {
        for (int i = pos; i<nElems; i++)
        {
            v[i] = v[i+1];
        }

        nElems--;
        return true;
    }
}

void OrdArray :: display()
{
    for (int i = 0; i < nElems; i++){
        cout << v[i]<<endl;
    }
}

int main()
{
    int maxSize = 100;
    OrdArray arr(maxSize);
    arr.insert(77); arr.insert(99); arr.insert(44); arr.insert(55); arr.insert(22); arr.insert(88); arr.insert(11); arr.insert(00); arr.insert(66);
    arr.insert(33); 
    arr.display();
    int searchKey = 55;
    if( arr.find(searchKey) != arr.getSize() )
        cout << "Found "<< searchKey << endl;
    else 
        cout << "Cant find " << searchKey << endl;
    arr.display(); 
    cout << "Deleting 0, 55, and 99" << endl;
    arr.remove(00);
    arr.remove(55);
    arr.remove(99);
    arr.display();
    return 0; 
}
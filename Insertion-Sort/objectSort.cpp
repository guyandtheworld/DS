#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person
{
    private:
        string lastName;
        string firstName;
        int age;
    public:
        Person(string last, string first, int a) :
                lastName(last), firstName(first), age(a)
                {}

        string getLast()
        {
            return lastName;
        }

        void displayPerson()
        {
            cout << lastName <<endl;
            cout << firstName <<endl;
            cout << age <<endl;

        }
};

class ArrayInOb
{
    private:
        vector<Person*> v;
        int nElems;

    public:
        ArrayInOb(int max) : nElems(0)
        {
            v.resize(max);
        }

        void insert(string last, string first, int age)
        {
            v[nElems] = new Person(last, first, age);
            nElems++;
        }

        void display()
        {
            for(int i = 0; i < nElems; i++)
            {
                v[i]->displayPerson();
            }
        }

        void insertionSort()
        {   int i, j;
            for (i = 1; i<nElems; i++)
            {
                Person* temp = v[i];
                j = i;
                while (j>0 && v[j-1]->getLast() >= temp->getLast())
                {
                    v[j] = v[j-1];
                    j--;
                }
                v[j] = temp;
            }    
        }
};

int main() 
{ 
    int maxSize = 100;             //array size 
    ArrayInOb arr(maxSize);        //create array 
    arr.insert("“Evans”", "“Patty”", 24);   
    arr.insert("“Smith”", "“Lorraine”", 37); 
    arr.insert("“Yee”", "“Tom”", 43); 
    arr.insert("“Adams”", "“Henry”", 63); 
    arr.insert("“Hashimoto”", "“Sato”", 21); 
    arr.insert("“Stimson”", "“Henry”", 29); 
    arr.insert("“Velasquez”", "“Jose”", 72);
    arr.insert("“Lamarque”", "“Henry”", 54);
    arr.insert("“Vang”", "“Minh”", 22); 
    arr.insert("“Creswell”", "“Lucinda”", 18);
    cout << "Before sorting:" << endl; 
    arr.display();                 //display items 
    arr.insertionSort();           //insertion-sort them 
    cout << "After sorting:" << endl; 
    arr.display();                 //display them again return 0; 
} 
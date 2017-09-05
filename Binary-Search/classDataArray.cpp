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

class ClassDataArray
{
    private:
        vector <Person*> v;
        int nElems;
    public:
        ClassDataArray(int max) : nElems(0)
            {
                v.resize(max);
            }

        ~ClassDataArray()
            {
                for (int j=0; j<nElems; j++)
                    delete v[j];
            }
        Person* find(string name)
        {
            int j;
            for (j=0; j<nElems; j++)
                if (v[j]->getLast() == name)
                    break;
            if(j == nElems)
                return NULL;
            else
                return v[j];
        }

        void insert(string first, string last, int age)
        {
            v[nElems] = new Person(first, last, age);
            nElems++;
        }

        bool remove(string last)
        {
            int j;
            for (j=0; j<nElems; j++)
                if (v[j]->getLast() == last)
                    break;
            if (j == nElems)
                return false;
            else 
            {
                delete v[j];
                for (int k = j; k<nElems; k++)
                {
                    v[k] = v[k+1];
                }
                nElems--;
                return true;
            }
        }

        void DisplayA()
        {
            for (int j=0; j<nElems; j++)
                v[j]->displayPerson();
        }
};

int main() 
{ 
    int maxSize = 100;                  
    ClassDataArray arr(maxSize);        
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
    arr.DisplayA();  
    return 0;
}
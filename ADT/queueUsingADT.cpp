#include <iostream>
using namespace std; 

class Link { 	
	public: 
		double dData;
		Link* pNext;
		Link(double d) : dData(d), pNext(NULL) {}
		void displayLink() { cout << dData << " "; }
}; 

class FirstLastList 
{ 
	private: 
		Link* pFirst;
		Link* pLast;
	public:
		FirstLastList() : pFirst(NULL), pLast(NULL) {}
		~FirstLastList()
		{
			Link* pCurrent = pFirst;
			while(pCurrent != NULL)
			{
				Link* pOldCur = pCurrent;
				pCurrent = pCurrent -> pNext;
				delete pOldCur;
			}
		}

		bool isEmpty()                 
		{ 
			return (pFirst==NULL); 
		} 

		void insertLast(double dd)
		{ 
			Link* pNewLink = new Link(dd); 
			if( isEmpty()) 
				pFirst = pNewLink;          //first --> newLink 
			else 
				pLast->pNext = pNewLink;    //old last --> newLink 
			pLast = pNewLink;              //newLink <-- last 
		}

		void removeFirst()
		{
			Link* pTemp = pFirst;          
			if(pFirst->pNext == NULL)
				pLast = NULL;
			pFirst = pFirst->pNext;
			delete pTemp;
		}

		void displayList() { 
			cout << "List (first-->last): "; 
			Link* pCurrent = pFirst; 
			while(pCurrent != NULL)
			{ 
				pCurrent->displayLink();
				pCurrent = pCurrent->pNext; 
			} 
			cout << endl; 
		}
};

class LinkQueue
{
	private:
		FirstLastList theList;
	public:
		bool isEmpty(0)
		{ return theList.isEmpty();}

		void insert(double j)
		{
			theList.insertLast(j);
		}

		double remove()
		{
			return theList.removeFirst();
		}

		void displayQueue()
		{
			cout << "Queue (front-->rear): ";
			theList.displayList();
		}
};
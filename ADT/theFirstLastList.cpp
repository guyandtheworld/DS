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

		void insertLast(double dd)        //insert at end of list 
		{ 
			Link* pNewLink = new Link(dd); //make new link 
			if( isEmpty())                //if empty list, 
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

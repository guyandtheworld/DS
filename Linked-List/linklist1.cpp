#include <iostream>
using namespace std;

class Link
{
	public:
		int iData;
		double dData;
		Link* pNext;
	Link(int id, double dd) : iData(id), dData(dd), pNext(NULL)
	{}

	void displayLink()
	{
		cout << "{" <<iData<<", "<<dData << "} ";
	}
};


class LinkList
{
	private:
		Link* pFirst;
	public:
		LinkList() : pFirst(NULL)
		{}

	bool isEmpty()
	{
		return pFirst==NULL;
	}

	void insertFirst(int id, double dd)
	{
		Link* pNewLink = new Link(id, dd);
		pNewLink->pNext = pFirst;
		pFirst = pNewLink;
	}

	Link* getFirst()
	{
		return pFirst;	
	}

	void removeFirst()
	{
		Link* temp = pFirst;
		pFirst = pFirst->pNext;
		delete temp;
	}
	void displayList()
	{
		cout << "List (first-->last): "; 
		Link* pCurrent = pFirst;
		while (pCurrent!=NULL)
		{
			pCurrent->displayLink();
			pCurrent = pCurrent->pNext;
		}
		cout<< endl;
	}

	bool remove(int key)
	{
		Link* prev = pFirst;
		Link* cur = pFirst;
		while (cur->dData!=key)
		{
			if(cur->pNext==NULL){
				return false;
			}
			else{
				prev=cur;
				cur=cur->pNext;
			}
		}

		prev->pNext = cur->pNext;
		delete cur;
	}

};

int main ()
{ 
	LinkList theList;                      //make new list 
	theList.insertFirst(22, 2.99);         //insert four items 
	theList.insertFirst(44, 4.99); 
	theList.insertFirst(66, 6.99); 
	theList.insertFirst(88, 8.99); 
	theList.displayList();                 //display list 
	while( !theList.isEmpty() )            //until it’s empty, 
	{ 
		Link* pTemp = theList.getFirst();  //get first link //display its key 
		cout << "Removing link with key " << pTemp->iData << endl; theList.removeFirst();             //remove it 
	} 
	theList.displayList();                //display empty list 
	return 0; 
}  //end main() 

#include <iostream>

using namespace std;

class Link
{
	public:
		double dData;
		Link* pNext;

		Link(double dd) : dData(dd), pNext(NULL) {}

		void displayLink()
		{
			cout<< dData << " ";
		}
};

class LinkList
{
	private:
		Link* pFirst;
	public:
		LinkList() : pFirst(NULL)
		{}
		~LinkList()
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

		void insertFirst(double dd)
		{
			Link* pNewLink = new Link(dd);
			pNewLink->pNext = pFirst;
			pFirst = pNewLink;
		}

		double deleteFirst()
		{
			Link* pTemp = pFirst;
			pFirst = pFirst -> pNext;
			double key = pTemp->dData;
			delete pTemp;
			return key;
		}

		void displayList()
		{
			Link* pCurrent = pFirst;
			while(pCurrent != NULL)
			{
				pCurrent -> displayLink();
				pCurrent = pCurrent->pNext;
			}
			cout << endl;
		}
};

class LinkStack
{
private:
	LinkList* pList;
public:
	LinkStack()
	{pList = 	new LinkList;}
	~LinkStack()
	{delete pList;};

	void push(double j)
	{
		pList->insertFirst(j);
	}

	double pop()
	{
		return pList->deleteFirst();
	}

	bool isEmpty()
	{
		return (pList->isEmpty());
	}

	void displayStack()
	{
		cout << "Stack (top - -> bottom: ";
		pList -> displayList();
	}
};


int main() { 
	LinkStack theStack;            //make stack 
	theStack.push(20);             //push items 
	theStack.push(40); 
	theStack.displayStack();       //display stack (40, 20) 
	theStack.push(60);             //push items 
	theStack.push(80); 
	theStack.displayStack();       //display (80, 60, 40, 20,) 
	theStack.pop();                //pop items (80, 60) 
	theStack.pop(); 
	theStack.displayStack();       
	return 0; } 
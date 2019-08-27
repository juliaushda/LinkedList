#include <iostream>
#include <vector>

struct Node
{
	int iData;

	Node* pNext = nullptr; 
};


namespace local
{
	class List
	{
	public:
		~List();

		void Push_Back(int);
		void Push_front(int);
		bool Insert(int, unsigned int);

		bool Delete(unsigned int);

		void Clear();

		void Show();

		int Size() const;

	private:
		Node* pHead = nullptr;
		int iSize = 0;
	};

}


int local::List::Size() const
{

	return iSize;
}


void local::List::Push_Back(int value)
{
	Node* tmp = new Node;
	tmp->iData = value;

	++iSize;

	if (pHead == nullptr)
	{
		pHead = tmp;
		return;
	}

	Node* tmpNode = pHead;

	while (tmpNode->pNext != nullptr)
	{
		tmpNode = tmpNode->pNext;
	}

	tmpNode->pNext = tmp;
}


void local::List::Show()
{
	if (iSize == 0)
	{
		return;
	}

	Node* tmpNode = pHead;

	while (tmpNode != nullptr)
	{
		std::cout << "Node&: " << tmpNode << "| Data: " << tmpNode->iData << "|Next:" << tmpNode->pNext << std::endl;
		tmpNode = tmpNode->pNext;
	}
}


local::List::~List()
{
	Clear();
}


void local::List::Clear()
{
	if (pHead == nullptr)
	{
		return;
	}

	Node* tmp(pHead);
	Node* tmpNext(nullptr);
	do
	{
		tmpNext = tmp->pNext;
		delete tmp;
		tmp = tmpNext;

	} while (tmpNext != nullptr);

	pHead = nullptr;
	iSize = 0;
}


void local::List::Push_front(int value)
{
	Node* tmp = new Node;
	tmp->iData = value;

	++iSize;

	if (pHead == nullptr)
	{
		pHead = tmp;
	}
	else
	{
		tmp->pNext = pHead;
		pHead = tmp;
	}
}


bool local::List::Insert(int value, unsigned int pos)
{
	if (pos > iSize)
		return false;

	Node* tmp_New = new Node;
	tmp_New->iData = value;

	++iSize;

	if (pHead == nullptr || pos == 0)
	{
		tmp_New->pNext = pHead;
		pHead = tmp_New;
		return true;
	}
	Node* tmp(pHead);
	Node* tmpPrev(nullptr);

	for (int i(0); i < pos; ++i)
	{
		tmpPrev = tmp;
		tmp = tmp->pNext;
	}

	tmpPrev->pNext = tmp_New;
	tmp->pNext = tmp;


	return true;
}


bool local::List::Delete(unsigned int pos)
{
	if (pHead == nullptr || pos >= iSize)
		return false;

	Node* tmp(pHead);
	Node* tmpPrev(nullptr);
	Node* tmpNext(nullptr);


	for (int i(0); i < pos; ++i)
	{
		tmpPrev = tmp;
		tmp = tmp->pNext;
	}
	if (tmpPrev == nullptr) {
		pHead = pHead->pNext;
		delete tmp;
		return true;
	}
	tmpPrev->pNext = tmp->pNext;
	delete tmp;
	--iSize;

	return true;
}


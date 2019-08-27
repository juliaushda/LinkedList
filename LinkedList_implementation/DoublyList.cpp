#include <iostream>
using namespace std;

struct Node {
	int iData;
	Node* pNext = nullptr;
	Node* pPrev = nullptr;
};

namespace local {
	class List2 {
		Node* pHead = nullptr;
		Node* pTail = nullptr;
		unsigned int iSize = 0;

	public:
		~List2();

		void push_back(int);
		unsigned int Size() const;
		void push_front(int);
		void show() const;
		void clear();
		bool Delete(unsigned int);
		bool insert(int, unsigned int);
	};
}

unsigned int local::List2::Size() const {
	return iSize;
}


void::local::List2::push_back(int value) {
	Node* tmp = new Node;
	tmp->iData = value;
	++iSize;

	if (pHead == nullptr) {
		pHead = pTail = tmp;
		return;
	}
	pTail->pNext = tmp;
	tmp->pPrev = pTail;
	pTail = tmp;
}


void::local::List2::push_front(int value) {
	Node* tmp = new Node;
	tmp->iData = value;
	++iSize;

	if (pHead == nullptr) {
		pHead = pTail = tmp;
		return;
	}

	tmp->pNext = pHead;
	pHead->pPrev = tmp;
	pHead = tmp;
}

void::local::List2::show() const {
	if (pHead == nullptr)
		return;

	Node* tmp = pHead;
	do {
		cout << "Node " << tmp << " | Prev " << tmp->pPrev << " | Next " << tmp->pNext << " | Data " << tmp->iData << endl;
		tmp = tmp->pNext;
	} while (tmp != pTail);

	cout << "Node " << tmp << " | Prev " << tmp->pPrev << " | Next " << tmp->pNext << " | Data " << tmp->iData << endl;
}


void local::List2::clear()
{
	if (pHead == nullptr)
		return;

	Node* tmp = pHead;
	Node* tmpNext = nullptr;

	do
	{
		tmpNext = tmp->pNext;
		delete tmp;
		tmp = tmpNext;

	} while (tmpNext != nullptr);

	pHead = nullptr;
	pTail = nullptr;
	iSize = 0;
}

local::List2::~List2() {
	clear();
}


bool local::List2::Delete(unsigned int pos) {
	if (pHead == nullptr || pos >= iSize)
		return false;

	Node* tmp = pHead;
	Node* tmpPrev = nullptr;
	Node* tmpNext = nullptr;


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

}



bool local::List2::insert(int value, unsigned int pos) {
	if (pos > iSize)
		return false;

	Node* tmp = new Node;
	tmp->iData = value;
	++iSize;

	if (pHead == nullptr) {
		pHead = pTail = tmp;
		return true;
	}

	if (pos == 0)
	{
		tmp->pNext = pHead;
		pHead->pPrev = tmp;
		pHead = tmp;
		return true;
	}

	Node* tmpNew = pHead;
	Node* tmpPrev = nullptr;

	for (int i(0); i < pos; ++i) {
		tmpPrev = tmpNew;
		tmpNew = tmpNew->pNext;
	}

	tmp->pNext = tmpNew;
	tmp->pPrev = tmpNew->pPrev;
	tmpNew->pPrev = tmp;
	tmp->pPrev->pNext = tmp;

	return true;
}



int main() {
	local::List2 ls;
	ls.push_back(5);
	ls.push_back(10);
	ls.push_front(55);
	ls.show();
	cout << "----------------------------" << endl;
	ls.insert(100, 1);
	ls.show();
	cout << "----------------------------" << endl;
	ls.Delete(0);
	ls.show();

	system("pause");
	return 0;
}


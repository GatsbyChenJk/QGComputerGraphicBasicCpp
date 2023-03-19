#include "LinkedList.h"
#include "ForwardLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	LinkedList<int> testList;
	testList.PushFront(new Node<int>(123));
	testList.PushFront(new Node<int>(456));
	testList.PushFront(new Node<int>(789));
	testList.PushBack(new Node<int>(11));
	testList.PushBack(new Node<int>(45));
	testList.PushBack(new Node<int>(14));
	cout <<"the list length is: " << testList.Count() << endl;
	cout << "is the list is empty?" << testList.Empty() << endl;
	testList.Print();
	testList.Insert();
	testList.Print();
	testList.Erase();
	testList.Print();
}


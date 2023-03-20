#include "ForwardLinkedList.h"
#include<iostream>
using namespace std;

int main3()
{
	ForwardLinkedList<int> list;
	list.PushFront(new FNode<int>(123));
	list.PushFront(new FNode<int>(456));
	list.PushBack(new FNode<int>(789));
	list.PushBack(new FNode<int>(159));
	cout << "is it a empty list? " << list.Empty()<< endl;
	cout << "the length of the list is: " << list.Count() << endl;

	return 0;
}
#include "LinkedList.h"
#include "ForwardLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "LinkedList test" << endl;//测试单向链表adt功能
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
	testList.Insert(4,66);//在第四个结点后插入数据66
	testList.Print();
	testList.Erase(3);//删除第三个结点
	testList.Print();

	cout << endl;

	cout << "ForwardLinkedList test" << endl;//测试双向链表adt功能
	ForwardLinkedList<int> list;
	list.PushFront(new FNode<int>(123));
	list.PushFront(new FNode<int>(456));
	list.PushBack(new FNode<int>(789));
	list.PushBack(new FNode<int>(159));
	cout << "is it a empty list? " << list.Empty() << endl;
	cout << "the length of the list is: " << list.Count() << endl;
	list.Print();
	//list.ReversePrint();
	list.Insert(2, 114);
	list.Print();
	list.Erase(3);
	list.Print();

	cout << endl;
	cout << "test is over" << endl;
}


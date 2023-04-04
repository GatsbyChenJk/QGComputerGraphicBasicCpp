#include "LinkedStack.h"
#include <iostream>

StackNode::StackNode() {};

StackNode::StackNode(int data)
{
	this->data = data;
}

LinkedStack::LinkedStack()
{
    head = new StackNode();
	head->data = 0;
	head->next = nullptr;
}

LinkedStack::~LinkedStack()
{
	StackNode *tempNode = head->next;

	while (tempNode != nullptr)
	{
		StackNode* delNode = tempNode;
		tempNode = tempNode->next;
		delete delNode;
	}

	delete head;
}

void LinkedStack::Push(StackNode* StNode)
{
	StNode->next = head->next;
	head->next = StNode;
	size++;
}

void LinkedStack::Pop()
{
	StackNode* tempNode = head->next;//要删除的栈顶结点

	head->next = tempNode->next;//头结点指向栈顶结点的前一个结点

	delete tempNode;

	size--;
}

void LinkedStack::Print()//输出链栈元素
{
	using namespace std;

	if (!IsEmpty())
	{

		StackNode* tempNode = head->next;

       // cout << "there are all the data in the linked stack" << endl;

			cout << "---" << endl;;

		for (int i = 0;i < size;i++)
		{

			cout << " " << tempNode->data << endl;
			tempNode = tempNode->next;
            cout << "---" << endl;
			/*if (tempNode->next == nullptr)
			{
				break;
			}*/

		}
		
			

	}

	else
	{
		cout << "test stack is empty" << endl;
		return;
	}
}


void LinkedStack::GetTop()//获取栈顶数据
{
	using namespace std;

	if (head->next == nullptr)
	{
		cout << "test list is empty" << endl;

		return;
	}

	cout << "---" << endl;
	cout <<head->next->data<< endl;
	cout << "---" << endl;

}

int LinkedStack::GetSize()
{
	return size;
}

bool LinkedStack::IsEmpty()
{
	return (size == 0) ? true : false;
}



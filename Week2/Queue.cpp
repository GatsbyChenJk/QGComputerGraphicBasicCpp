#include "Queue.h"
#include <iostream>

QueueNode::QueueNode(){};

QueueNode::QueueNode(int data)
{
	this->data = data;
}

ListQueue::ListQueue()
{
	head = new QueueNode();
	tail = head;
	head->next = nullptr;
}

ListQueue::~ListQueue()
{
	QueueNode* tempNode = head->next;

	while (tempNode != nullptr)
	{
		QueueNode* delNode = tempNode;
		tempNode = tempNode->next;
		delete delNode;
	}

	delete head;

	delete tail;
}

void ListQueue::Push(QueueNode* PushNode)
{

	QueueNode* tempNode = head;
	//�ƶ�ָ�뵽��β
	while (tempNode->next != nullptr)
	{
		tempNode = tempNode->next;
	}

	tempNode->next= PushNode;

	//PushNode->next = nullptr;

	//tempNode->data = PushNode->data;

	tail = PushNode;//���¶�βָ��

	size++;
}

void ListQueue::Pop()
{
	if (IsEmpty()) 
	{ 
		std::cout << "test Queue is empty" << std::endl;
		return;
	}

	QueueNode* PopNode = head->next;

	head->next = PopNode->next;//�ƶ���ͷָ�뵽�µĶ�ͷ

	delete PopNode;

	size--;
}

bool ListQueue::IsEmpty()
{
	return (size == 0) ? true : false;
}

int ListQueue::GetSize()
{
	return size;
}

int ListQueue::GetFirst()
{
	using namespace std;

	return head->next->data;
}

int ListQueue::GetLast()
{
	using namespace std;

	QueueNode* tempNode = head->next;
	//��ȡ��β���ָ��
	while (tempNode->next != nullptr)
	{
		tempNode = tempNode->next;
	}

	return tempNode->data ;
}

void ListQueue::Print()
{
	using namespace std;

	if (IsEmpty())
	{
		cout << "test queue is empty" << endl;
		return;
	}

	QueueNode* tempNode = head->next;

	
	
		for (int j = 0;j < size;j++)
		{
			cout << "----" ;
		}
		cout << endl;

		for (int i = 0;i < size;i++)
		{
			cout <<"|" << tempNode->data << "| ";
			tempNode = tempNode->next;
		}
		cout << endl;

		for (int k = 0;k < size;k++)
		{
			cout << "----" ;
		}
		cout << endl;

}

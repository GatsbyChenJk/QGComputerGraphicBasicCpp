#pragma once
#include <iostream>
//这里我选择用链表来实现一个顺序队列

class QueueNode
{
public:
	int data;
	QueueNode* next;
	QueueNode();
	QueueNode(int data);
};

class ListQueue
{
private:
	int size = 0;
	QueueNode* head;//队头指针
	QueueNode* tail;//队尾指针
public:
	ListQueue();

	~ListQueue();

	void Push(QueueNode* PushNode);//入队操作

	void Pop();//出队操作

	bool IsEmpty();//判断队列是否为空

	int GetSize();//获取队列长度

	int GetFirst();//获取队列首元素

	int GetLast();//获取队列末尾元素
    
	void Print();//输出队列元素
};
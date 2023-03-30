#pragma once
#include <iostream>
//������ѡ����������ʵ��һ��˳�����

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
	QueueNode* head;//��ͷָ��
	QueueNode* tail;//��βָ��
public:
	ListQueue();

	~ListQueue();

	void Push(QueueNode* PushNode);//��Ӳ���

	void Pop();//���Ӳ���

	bool IsEmpty();//�ж϶����Ƿ�Ϊ��

	int GetSize();//��ȡ���г���

	int GetFirst();//��ȡ������Ԫ��

	int GetLast();//��ȡ����ĩβԪ��
    
	void Print();//�������Ԫ��
};
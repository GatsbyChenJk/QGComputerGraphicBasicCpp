#pragma once
#include <iostream>

class StackNode//链栈结点类
{
public:
	int data;
	StackNode* next;
	StackNode();
	StackNode(int data);
};

class LinkedStack//链栈类
{
private:
	int size=0;

	StackNode* head;

public:
	 LinkedStack();//初始化链栈

	 ~LinkedStack();//程序运行结束销毁链栈

	 void Push(StackNode *StNode);//入栈操作

	 void Pop();//出栈操作

	 int GetSize();//获取长度

	 void GetTop();//获取栈顶

	 bool IsEmpty();//判断是否为空

	 void Print();//输出链栈各结点数据
};

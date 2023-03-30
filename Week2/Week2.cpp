#include "LinkedStack.h"
#include "Queue.h"
#include <iostream>

//用于测试功能的程序

void Menu()
{
	using namespace std;

	cout << "|-------------------command list------------------|" << endl;
	cout << "     (01)StackPush" << endl;
	cout << "     (02)StackPop" << endl;
	cout << "     (03)StackGetSize" << endl;
	cout << "     (04)StackGetTop" << endl;
	cout << "     (05)StackPrint" << endl;
	cout << "     (06)Help" << endl;
	cout << "     (11)QueuePush" << endl;
	cout << "     (12)QueuePop" << endl;
	cout << "     (13)QueueGetSize" << endl;
	cout << "     (14)QueueGetFirst" << endl;
	cout << "     (15)QueueGetLast" << endl;
	cout << "     (16)QueuePrint" << endl;
	cout << "command guide:" << endl;
	cout << "     Press 05 to use command (05)" << endl;
	cout << "     Press 02 to use command (02)" << endl;
	cout << "|---press number 1-6 to use command" << endl;
	cout << "[tip:use command (06) to call command list again]" << endl;
	cout << endl;
}

int main()
{
	using namespace std;

	int commandNum,data;

	LinkedStack testLinkedStack;

	ListQueue testQueue;
	
	Menu();

	while (1)
	{
		cout << "|---Please enter your command number: " ;
		cin >> commandNum;
		switch (commandNum)
		{
		case 01:
			cout << "enter the data you want to push:";
			cin >> data;			
			testLinkedStack.Push(new StackNode(data));
			cout << "now the data in list are:" << endl;;
			testLinkedStack.Print();
			cout << endl;
			break;
		case 02:
			testLinkedStack.Pop();
			cout << "top deleted successfully,you can confirm below" << endl;
			testLinkedStack.Print();
			break;
		case 03:
			cout << "the size of linked stack is: " << testLinkedStack.GetSize() << endl;
			break;
		case 04:
			cout << "the top data is:" << endl;
			testLinkedStack.GetTop();
			break;
		case 05:
			cout << "the data in stack are:" << endl;
			testLinkedStack.Print();
			break;
		case 06:
			Menu();
			break;
		case 11:
			cout << "enter the data you want to push:";
			cin >> data;
			testQueue.Push(new QueueNode(data));
			cout << "now the data in Queue are:" << endl;;
			testQueue.Print();
			cout << endl;
			break;
		case 12:
			testQueue.Pop();
			cout << "top deleted successfully,you can confirm below" << endl;
			testQueue.Print();
			break;
		case 13:
			cout << "the size of queue is: " << testQueue.GetSize() << endl;
			break;
		case 14:
			cout << "the first data is: " << testQueue.GetFirst() << endl;
			break;
		case 15:
			cout << "the last data is: " << testQueue.GetLast() << endl;
		case 16:
			cout << "the data in queue are" << endl;
			testQueue.Print();
			break;
		default:
			cout << "wrong command" << endl;
			break;
		}
	}
}


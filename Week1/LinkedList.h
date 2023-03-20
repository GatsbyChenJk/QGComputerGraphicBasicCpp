#pragma once
#include <iterator>
#include<iostream>
using namespace std;
//可以考虑让这个类的使用更优雅一点
//不想折腾的删除这个定义
//#define LL_ITERATOR_FEATURE ///可选 [迭代器]
template<class T>

class Node//链表节点类
{

public:
	T data;
	Node<T>* next;
	Node();
	Node(T data);
};

template<class T>

Node<T>::Node() {};//无参数构造函数

template<class T>

Node<T>::Node(T data)
{
	this->data = data;//有参数构造函数
}

template<class T>

class LinkedList
{
private:

	Node<T>* head;

	int size = 0;

public:
#ifdef LL_ITERATOR_FEATURE
	class iterator
	{
	private:
		//...
	public:
		using iterator_concept = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		reference operator*() const;
		pointer operator->() const;
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;
		reference operator[](difference_type  i) const;
		auto operator<=>(const iterator&) const = default;
	};

	iterator begin();
	iterator end();
	iterator rbegin();
	iterator rend();
#endif

public:
	LinkedList();
	~LinkedList();

	T& operator[](int i);
#ifdef LL_ITERATOR_FEATURE
	//default insert after iter
	void Insert(const T& val, const iterator& iter, bool insert_prev = false);
	iterator Erase(const iterator& iter);
#else
	//default insert after node
	//void Insert(const T& val, T* node, bool insert_prev = false);
	void Erase();
#endif

	T& Front();
	T& Back();
	//void PushFront(const T& val);
	//void PushBack(const T& val);
	void PopFront();
	void PopBack();

	size_t Count();

	bool Empty();

	void PushFront(Node<T>* node);

	void PushBack(Node<T>* node);

	void Print();

	void Insert();
	
	void Clear();

	//... other methods
};

template<class T>

LinkedList<T>::LinkedList() //链表的构造函数
{
	head = new Node<T>();
	head->next = NULL;
	head->data = 0;
};

template<class T>

LinkedList<T>::~LinkedList() //链表的析构函数
{
	Node<T>* tempNode = head->next;

	while (tempNode != NULL)
	{
		Node<T>* deleteNode = tempNode;
		tempNode = tempNode->next;
		delete deleteNode;//释放每个结点内存
	}

	delete head;//释放头结点内存
};

template<class T>

bool LinkedList<T>::Empty()//判断是否为空链表
{	 
	return (size == 0) ? true : false;
}

template<class T>

void LinkedList<T>::PushFront(Node<T>* node)//头插
{
	node->next = head->next;
	head->next = node;
	size++;
}

template<class T>

void LinkedList<T>::PushBack(Node<T> *node)//尾插
{
	Node<T>* tempNode = head;
	
	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;
	}

	tempNode->next = node;
	size++;
}

template<class T>

void LinkedList<T>::Print()//顺序输出链表所有元素
{
	Node<T>* tempNode = head;

    cout << "the data in list:" << endl;

	for (int i = 0;i < size;i++)
	{
		
		cout << tempNode->next->data << endl;
		tempNode = tempNode->next;

		if (tempNode->next == nullptr)
		{
			return;
		}

	}

}

template<class T>

size_t LinkedList<T>::Count() //获取链表结点数（长度）
{
	return size;
}

template<class T>

void LinkedList<T>::Insert()
{
	int pos,InsertData;

	Node<T>* tempNode;

	cout << "enter the position you want to insert" << endl;
	cin >> pos;

	if (pos<0 || (pos + 1)>size) 
	{ 
		cout << "error" << endl;

		return;
	}

	cout << "enter the data" << endl;
	cin >> InsertData;

	Node<T>* InsertNode = new Node<T>(InsertData);
	Node<T>* FindPosNode = head;

	for (int i = 0;i < pos-1;i++)
	{
		FindPosNode = FindPosNode->next;//将指针移动到要插入的位置
	}
	tempNode = FindPosNode->next;
	FindPosNode->next = InsertNode;//将要插入结点的前一个结点的指针指向要插入的结点
	InsertNode->next = tempNode;//将插入的结点的指针指向原位置的下一个结点
	
	size++;
}

template<class T>

void LinkedList<T>::Erase()//删除指定位置的结点
{
	int pos;

	Node<T>* EraseNode=head;

	Node<T>* tempNode;

	cout << "please enter the position of the node you want to erase" << endl;
	cin >> pos;

	if (pos == 1)
	{
		head = head->next;
		free(EraseNode);
		return;
	}

	for (int i = 0;i < pos-1;i++)
	{
		EraseNode = EraseNode->next;//获取要删除位置的前一个位置的指针
	}

	tempNode = EraseNode->next;//获取要删除的结点的指针
	EraseNode->next = tempNode->next;//将要删除的结点的前一个位置的指针指向被删除结点的下一结点
	free(tempNode);

	size--;
}







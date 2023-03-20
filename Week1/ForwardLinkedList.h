#pragma once
#include <iterator>
#include <iostream>
using namespace std;
//可以考虑让这个类的使用更优雅一点
//不想折腾的删除这个定义
//#define FLL_ITERATOR_FEATURE ///可选	[迭代器]

#ifdef FLL_ITERATOR_FEATURE
//这个特性要求在插入和移除时 "在形式上" 无需前一个节点，只使用当前节点即可
//这可以让调用更加优雅
#define FLL_OPTERATE_ON_THIS_FEATURE ///可选 [直接操作]
#endif
template<class T>

class FNode//双向链表结点类
{
public:
	FNode<T>* prev;//前指针
	T data;
	FNode<T>* next;//后指针
	FNode();
	FNode(T data);
};

template<class T>

FNode<T>::FNode(){}; //无参数构造函数

template<class T>

FNode<T>::FNode(T data)
{
		this->data = data;//有参数构造函数
}

template<class T>

class ForwardLinkedList
{
private:

	int size = 0;

	FNode<T>* Head;

public:
#ifdef FLL_ITERATOR_FEATURE
	class iterator
	{
	private:
		//...
	public:
		using iterator_concept = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		reference operator*() const;
		pointer operator->() const;
		iterator& operator++();
		iterator operator++(int);
		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;
		reference operator[](difference_type  i) const;
		auto operator<=>(const iterator&) const = default;
	};

	iterator begin();
	iterator end();
#endif
public:
	ForwardLinkedList();
	~ForwardLinkedList();

	T& operator[](int i);

#ifdef FLL_ITERATOR_FEATURE
#ifdef FLL_OPTERATE_ON_THIS_FEATURE
	//default insert to the end of the list
	void Insert(const T& val, const iterator& iter = nullptr);
	void Erase(const iterator& iter);
#else
	//default insert to the end of the list
	void Insert(const T& val, const iterator& prev_iter = nullptr);
	void Erase(const iterator& prev_iter);
#endif
#else
	//default insert to the end of the list
	//void Insert(const T& val, T* prev_node = nullptr);
	//default insert to the head of the list
	//void Erase(T* prev_node = nullptr);
#endif

	T& Front();
	T& Back();
	//void PushFront(const T& val);
	
	//void PushBack(const T& val);

	void PopFront();

	size_t Count();

	bool Empty();

	void PushFront(FNode<T>* node);

	void PushBack(FNode<T>* node);

	void Insert(int pos,int InsertData);

	void Erase(int pos);

	void Clear();

	void Reverse();

	void Print();

	void ReversePrint();

	//... other methods
};

template<class T>

ForwardLinkedList<T>::ForwardLinkedList()
{
	Head = new FNode<T>();
	Head->prev = NULL;
	Head->next = NULL;
}


template<class T>

ForwardLinkedList<T>::~ForwardLinkedList()
{
	FNode<T>* tempNode = Head->next;

	if (tempNode != NULL)
	{
		FNode<T>* deleteNode = tempNode;
		tempNode = tempNode->next;
		delete deleteNode;
	}
		
	delete Head;

}

template <class T>

bool ForwardLinkedList<T>::Empty()//判断链表是否为空
{
	return (size == 0) ? true : false;
}

template<class T>

size_t ForwardLinkedList<T>::Count()//获取链表长度
{
	return size;
}

template<class T>

void ForwardLinkedList<T>::PushFront(FNode<T>* node)//双向链表头插
{
	node->next = Head->next;
	Head->next = node;
	node->prev = Head;
	size++;
}

template<class T>

void ForwardLinkedList<T>::PushBack(FNode<T>* node)//双向链表尾插
{
	FNode<T> *tempNode = Head;

	while (tempNode->next != NULL)
	{
		tempNode = tempNode->next;//获取链表尾结点指针
	}
	
	tempNode->next = node;//将原来的尾结点的尾指针指向node结点
	node->prev = tempNode;//将node结点指针指向原来的尾结点
	size++;

}

template<class T>

void ForwardLinkedList<T>::Print()
{
	FNode<T>* tempNode = Head;

	cout << "the data in list:" << endl;

	for (int i = 0;i < size;i++)
	{

		cout << tempNode->next->data << endl;
		tempNode = tempNode->next;

		if (tempNode->next == NULL)
		{
			return;
		}
	}

}

template<class T>

void ForwardLinkedList<T>::ReversePrint()
{
	FNode<T>* tempNode = Head;

	for(int i=0;i<size;i++)
	{
		tempNode = tempNode->next;
	}

	cout << "the reverse sequence of the list are:" << endl;

	for (int i = 0;i < size;i++)
	{
		cout << tempNode->data << endl;

		tempNode = tempNode->prev;
	    
		if (i == 0)
		{
			cout << Head->data << endl;
		}
	}

}

template<class T>

void ForwardLinkedList<T>::Insert(int pos, int InsertData)
{
	
		FNode<T>* tempNode;

		cout << "insert position: " << pos << " insert data: " << InsertData << endl;

		if (pos<0 || (pos + 1)>size)
		{
			cout << "error" << endl;

			return;
		}

		FNode<T>* InsertNode = new FNode<T>(InsertData);
		FNode<T>* FindPosNode = Head;

		for (int i = 0;i < pos - 1;i++)
		{
			FindPosNode = FindPosNode->next;//将指针移动到要插入的位置
		}

		tempNode = FindPosNode->next;
		FindPosNode->next = InsertNode;//将要插入结点的前一个结点的指针指向要插入的结点
		InsertNode->next = tempNode;//将插入的结点的指针指向原位置的下一个结点

		size++;
	
}

template<class T>

void ForwardLinkedList<T>::Erase(int pos)
{
	FNode<T>* EraseNode = Head;

	FNode<T>* tempNode;

	cout << "delete data position: " << pos << endl;

	if (pos == 1)
	{
		Head = Head->next;
		free(EraseNode);
		return;
	}

	for (int i = 0;i < pos - 1;i++)
	{
		EraseNode = EraseNode->next;//获取要删除位置的前一个位置的指针
	}

	tempNode = EraseNode->next;//获取要删除的结点的指针
	EraseNode->next = tempNode->next;//将要删除的结点的前一个位置的指针指向被删除结点的下一结点
	free(tempNode);

	size--;

}

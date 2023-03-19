#pragma once
#include <iterator>

//可以考虑让这个类的使用更优雅一点
//不想折腾的删除这个定义
//#define FLL_ITERATOR_FEATURE ///可选	[迭代器]

#ifdef FLL_ITERATOR_FEATURE
//这个特性要求在插入和移除时 "在形式上" 无需前一个节点，只使用当前节点即可
//这可以让调用更加优雅
#define FLL_OPTERATE_ON_THIS_FEATURE ///可选 [直接操作]
#endif



template<class T>

class ForwardLinkedList
{
	//...
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
	void Insert(const T& val, T* prev_node = nullptr);
	//default insert to the head of the list
	void Erase(T* prev_node = nullptr);
#endif

	T& Front();
	T& Back();
	void PushFront(const T& val);
	void PushBack(const T& val);
	void PopFront();

	size_t Count();
	bool Empty();

	void Clear();
	void Reverse();

	//... other methods
};
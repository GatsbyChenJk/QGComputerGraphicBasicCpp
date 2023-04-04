#include "Sort.h"
#include <iostream>

void insertSort(int* a, int n)
{
	int tempNum;

	for (int i = 1;i < n;i++)
	{
		tempNum = a[i];//要插入的元素
		for (int j = i - 1;j < i;j--)
		{
			if (tempNum < a[j])
			{
				a[j + 1] = a[j];//满足条件j位置的数后移一位
				a[j] = tempNum;//将j位置元素赋值为tempNum
			}
		}
	}
}

void MergeArray(int* a, int begin, int mid, int end, int* temp)//合并
{

}

void MergeSort(int* a, int begin, int end, int* temp)
{
	if (end > begin)
	{
		int len = end - begin;//获取长度
		int mid = len / 2;//获取中间位置索引
		temp = a;//temp不知道赋值为什么，暂时这样处理
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid + 1, end,temp);
	}
	
    
};
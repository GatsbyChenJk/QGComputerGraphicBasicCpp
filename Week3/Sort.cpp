#include "Sort.h"
#include <iostream>

void insertSort(int* a, int n)
{
	int tempNum;

	for (int i = 1;i < n;i++)
	{
		tempNum = a[i];//Ҫ�����Ԫ��
		for (int j = i - 1;j < i;j--)
		{
			if (tempNum < a[j])
			{
				a[j + 1] = a[j];//��������jλ�õ�������һλ
				a[j] = tempNum;//��jλ��Ԫ�ظ�ֵΪtempNum
			}
		}
	}
}

void MergeArray(int* a, int begin, int mid, int end, int* temp)//�ϲ�
{

}

void MergeSort(int* a, int begin, int end, int* temp)
{
	if (end > begin)
	{
		int len = end - begin;//��ȡ����
		int mid = len / 2;//��ȡ�м�λ������
		temp = a;//temp��֪����ֵΪʲô����ʱ��������
		MergeSort(a, begin, mid, temp);
		MergeSort(a, mid + 1, end,temp);
	}
	
    
};
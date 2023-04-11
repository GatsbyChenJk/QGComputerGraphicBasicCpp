#include "Sort.h"
#include <iostream>
#include <algorithm>

void insertSort(int* a, int n)
{
	int tempNum;

	for (int i = 1;i < n;i++)
	{
		tempNum = a[i];//要插入的元素
		for(int j = i - 1;j >= 0;j--)
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
	if (begin >= end) return;
	int tempIndex = begin;
	int Icounter,Jcounter;//计数变量，用于确认左右两边是否完全合并
	Icounter = Jcounter = 0;
	//i初始值标记为左半边数组起始元素，j初始值标记为右半边数组起始元素
	for (int i = begin, j = mid + 1;i <= mid && j <= end;i++, j++)
	{
		if (a[i] < a[j])
		{
			temp[tempIndex++] = a[i];
			Icounter++;
		}
		else
		{
			temp[tempIndex++] = a[j];
			Jcounter++;
		}	
	}

	while (Icounter <= mid)
	{
		temp[Icounter++] = a[Icounter++];//如果左半边未完全合并，则将左半边剩余的元素合并
	}

	while (Jcounter <= mid)
	{
		temp[Jcounter++] = a[Jcounter++];//如果右半边未完全合并，则将右半边剩余的元素合并
	}
	int m = 0;
	//将排序好的元素赋值回原数组
	for (int k = begin;k < end;k++)
	{
		a[k] = temp[m++];
	}

	

}

void MergeSort(int* a, int begin, int end, int* temp)
{
	if (begin >= end) return;
	if (end > begin)
	{
		//int* temp2 = new int[end - begin + 1];//新分配数组
		int mid = begin + (end - begin) / 2;//获取中间位置索引
		MergeSort(a, begin, mid, temp);//分割右半部分
		MergeSort(a, mid + 1, end, temp);//分割左半部分
		MergeArray(a, begin, mid, end, temp);//合并数组
		//std::copy(temp2, temp2 + end - begin + 1,  temp);//将排序好的元素复制到temp中
		//delete[] temp2;//释放内存
	}

	return;
    
}

void QuickSort_Recursion(int* a, int begin, int end)
{
	if (begin >= end) return;
	int pivot = a[begin];//选择第一个数为基准数
	int leftIndex = begin + 1;
	int rightIndex = end;
	int temp;
	if (begin < end)
	{
		while (1)
		{
			//从左边开始扫描找到比基准数大的数
			while (leftIndex < rightIndex && a[leftIndex] < pivot)
			{
				leftIndex++;
			}
			//从右边开始扫描找到比基准数小的数
			while (rightIndex > leftIndex && a[rightIndex] >= pivot)
			{
				rightIndex--;
			}
			//交换:把小的放左边，大的放右边
			if (leftIndex < rightIndex)
			{
				temp = a[leftIndex];
				a[leftIndex] = a[rightIndex];
				a[rightIndex] = temp;
			}
			else
			{
				return; // 左右指针相遇，退出循环
			}
		}
	}
	//将基准数“放中间”
	int mid = (leftIndex + rightIndex) / 2;
	temp = a[begin];
	a[begin] = a[mid];
	a[mid] = temp;

	QuickSort_Recursion(a, begin, mid);
	QuickSort_Recursion(a, mid + 1, end);
}

void CountSort(int* a, int size, int max)
{
	//获取数组最大值
	for (int i = 0;i < size;i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	
	int* CollectArray = new int[max+1];
	int* DistributeArray = new int[size];
	//构造收集数组
	for (int i = 0;i <= max;i++)
	{
		CollectArray[i] = 0;
	}
	for (int i = 0;i <size;i++)
	{
		CollectArray[a[i]]++;
	}
	//根据收集数组构造分配数组
	int index = 0;
	for (int j = 0;j <= max;j++)
	{
		while (CollectArray[j]!=0)
		{
			DistributeArray[index++] = j;
			CollectArray[j]--;
		}
	}
	//将分配数组赋值给原数组
	for (int k = 0;k <size;k++)
	{
		a[k] = DistributeArray[k];
	}

	delete[] CollectArray;
	delete[] DistributeArray;
}

/*void RadixCountSort(int* a, int size)
{
	//求出数组最大数
	int maxNum = a[0];
	for (int i=0;i<size;i++)
	{
		if (maxNum < a[i])
		{
			maxNum = a[i];
		}
	}
	//获取数组元素最大位数
	int MaxFigure = 1;
	while (maxNum >= 10)
	{
		maxNum /= 10;
		MaxFigure++;
	}
	//先从个位开始计数
	int* CollectArray = new int[11];
	int* DistributeArray = new int[size];
	int Radix = 1;
	int Count;
	for (int j = 0;j < MaxFigure;j++)
	{
		// 每次计数前清空计数数组
		for (int i = 0;i < 10;i++)
		{
			CollectArray[i] = 0;
		}
		//从个位开始计数
		for (int i = 0;i <= 10;i++)
		{
			Count = (a[i] / Radix) % 10;
			CollectArray[Count]++;
		}
		// 计数数组转换为统计数组
		for (int i = 1;i < 10;i++)
		{
			CollectArray[i] += CollectArray[i - 1];
		}
		//构造分配数组
		for (int i = size - 1;i >= 0;i--)
		{
			Count = (a[i] / Radix) % 10;
			DistributeArray[--CollectArray[Count]] = a[i];
			//DistributeArray[CollectArray[Count] - 1] = a[i];
		    //CollectArray[Count]--;
		}
		//将分配数组元素赋值给原数组
		for (int  i= 0;i < size;i++)
		{
			a[i] = DistributeArray[i];
		}

		Radix *= 10;//使计数的位置进一位
	}

	delete[] CollectArray;
	delete[] DistributeArray;

}
*/
// 获取num的第d位数字，从右往左数（个位为第1位）
int getDigit(int num, int d, int maxNum) {
	if (maxNum < pow(10, d - 1)) {
		return 0;
	}
	int pow10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000 };
	return (num / pow10[d - 1]) % 10;
}


void RadixCountSort(int* a, int size) 
{
	using namespace std;

	int maxNum = *max_element(a, a + size);

	// 对每个数位进行计数排序
	for (int d = 1; maxNum / d > 0; d *= 10) 
	{
		int count[10] = { 0 };    // 计数数组
		int* output = new int[size];   // 输出数组

		// 统计每个桶中的个数
		for (int i = 0; i < size; i++) 
		{
			int digit = getDigit(a[i], d, maxNum);
			count[digit]++;
		}

		// 计算每个桶的结束位置
		for (int i = 1; i < 10; i++) 
		{
			count[i] += count[i - 1];
		}

		// 将元素放入对应的桶中，并更新桶的结束位置
		for (int i = size - 1; i >= 0; i--) 
		{
			int digit = getDigit(a[i], d, maxNum);
			output[count[digit] - 1] = a[i];
			count[digit]--;
		}

		// 将输出数组复制到原数组中
		for (int i = 0; i < size; i++) 
		{
			a[i] = output[i];
		}

		delete[] output;
	}
}

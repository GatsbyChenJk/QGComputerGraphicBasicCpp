#include "Sort.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
//生成一个指定数组元素取值范围和长度的数组
void SummonRandomNum(int* a, int size, int min, int max)
{
	srand(time(0));  //设置时间种子
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % (max - min + 1) + min;//生成区间[min,max)的随机数 
	}
}

void Menu()
{
	using namespace std;
	cout << "Command List:" << endl;
}
//计时器函数
void Timer(bool bl)
{
	using namespace std;
	static clock_t start, end;
	if (bl)
	{
		start = clock();
	}
	else
	{
		end = clock();
		cout << "time spend: " << double(end - start) / CLOCKS_PER_SEC <<"s" << endl;
	}
}
//测试指定排序函数在指定数据量的排序用时
void TestForLargeData(int *a,int SortMethod,int size)
{
	using namespace std;

	if (SortMethod == 1)
	{
		cout << "using insert sort " << "size: " << size << " ";
		SummonRandomNum(a, size, 0, 10);
		Timer(true);
		insertSort(a, size);
		Timer(false);
	}
	else if(SortMethod == 2)
	{
		int* temp=new int[size];
		cout << "using merge sort "<< "size: " << size << " ";
		SummonRandomNum(a, size, 0, 10);
		Timer(true);
		MergeSort(a, 0, size-1, temp);
		Timer(false);
		delete[] temp;
	}
	else if (SortMethod == 3)
	{
		cout << "using quick sort " << "size: " << size << " ";
		SummonRandomNum(a, size, 0, 10);
		Timer(true);
		QuickSort_Recursion(a, 0, size-1);
		Timer(false);
	}
	else if (SortMethod == 4)
	{
		int max=0;
		cout << "using count sort " << "size: " << size << " ";
		SummonRandomNum(a, size, 0, 10);
		Timer(true);
		CountSort(a, size, max);
		Timer(false);
	}
	else if (SortMethod == 5)
	{
		cout << "using RadixCount sort " << "size: " << size << " ";
		SummonRandomNum(a, size, 0, 500);
		Timer(true);
		RadixCountSort(a, size);
		Timer(false);
	}
	else
	{
		cout << "wrong number" << endl;
	}
}

//大数据量测试
void LargeDataTest()
{
	using namespace std;

	int* testArray1 = new int[10000];
	int* testArray2 = new int[50000];
	int* testArray3 = new int[200000];

	cout << "test begin..." << endl;
	cout << endl;

	TestForLargeData(testArray1, 1, 10000);
	TestForLargeData(testArray2, 1, 50000);
	TestForLargeData(testArray3, 1, 200000);
	cout << endl;
	
	TestForLargeData(testArray1, 2, 10000);
	TestForLargeData(testArray2, 2, 50000);
	TestForLargeData(testArray3, 2, 200000);
	cout << endl;
	
	TestForLargeData(testArray1, 3, 10000);
	TestForLargeData(testArray2, 3, 50000);
	TestForLargeData(testArray3, 3, 200000);
	cout << endl;
	
	TestForLargeData(testArray1, 4, 10000);
	TestForLargeData(testArray2, 4, 50000);
	TestForLargeData(testArray3, 4, 200000);
	cout << endl;
	
	TestForLargeData(testArray1, 5, 10000);
	TestForLargeData(testArray2, 5, 50000);
	TestForLargeData(testArray3, 5, 200000);
	cout << endl;
}
//指定数据量和循环次数，进行大量小数据量测试
void SmallDataTest(int dataNum,int loopIndex)
{
	using namespace std;

	int* testArray01 = new int[dataNum];
	int* testArray02 = new int[dataNum];//专门用于测试基数排序

	SummonRandomNum(testArray01, dataNum, 0, 10);
	SummonRandomNum(testArray02, dataNum, 0, 500);
	//执行排序
	cout << "test begin..." << endl;

	cout << endl;
	cout << "using insert sort " << loopIndex << " times ";
	Timer(true);
	for (int i = 0;i < loopIndex;i++)
	{
		insertSort(testArray01, dataNum);
	}
	Timer(false);

	cout << endl;
	cout << "using merge sort " << loopIndex << " times ";
	Timer(true);
	for (int i = 0;i < loopIndex;i++)
	{
		int* temp = new int[dataNum];
		MergeSort(testArray01, 0, dataNum-1,temp);
		delete[] temp;
	}
	Timer(false);

	cout << endl;
	cout << "using quick sort " << loopIndex << " times ";
	Timer(true);
	for (int i = 0;i < loopIndex;i++)
	{
		QuickSort_Recursion(testArray01, 0, dataNum - 1);
	}
	Timer(false);

	cout << endl;
	cout << "using count sort "<< loopIndex <<" times ";
	Timer(true);
	for (int i = 0;i < loopIndex;i++)
	{
		int max = 0;
		CountSort(testArray01,dataNum,max);
	}
	Timer(false);

	cout << endl;
	cout << "using radix count sort "<<loopIndex<<" times ";
	Timer(true);
	for (int i = 0;i < loopIndex;i++)
	{
		RadixCountSort(testArray02,dataNum);
	}
	Timer(false);
}
//创建写入数据的文件
void CreatFileForTest()
{
	using namespace std;
	int size, min, max;
	cout << "|-enter the size of test array: ";
	cin >> size;
	cout << endl;

	cout << "|-enter the maxium number of test array: ";
	cin >> max;
	cout << endl;

	cout << "|-enter the minium number of test array: ";
	cin >> min;
	cout << endl;

	int* testArray = new int[size];
	SummonRandomNum(testArray, size, min, max);//生成测试数据

	ofstream testFile;
	testFile.open("TestData.txt");//打开或新建文件

	if (testFile.is_open())//检测文件是否被打开
	{
		for (int i = 0;i < size;i++)
		{
			testFile << testArray[i] << endl;
		}
		testFile.close();
		cout << "|-test file close successfully" << endl;
	}
	else
	{
		cout << "|-unable to open test file" << endl;
	}
}

void ReadDataFromFile()
{
	using namespace std;
	vector<int> ReadArray;
	ifstream ReadFile;
	ReadFile.open("TestData.txt");

	if (ReadFile.is_open())
	{
		cout << "|-test file open successfully" << endl;
	}

	int value;
	while (ReadFile >> value)
	{
		ReadArray.push_back(value);
		if (ReadFile.eof())
		{
			break;
		}
	}

	cout << "|-the data read in file are:" << endl;
	for (auto item : ReadArray)
	{
		cout << item<<" ";
	}
	cout << endl;

	int* sortArray = ReadArray.data();
	cout << "choose a sort method:" << endl;
	cout << "1.insert sort" << endl;
	cout << "2.merge sort" << endl;
	cout << "3.quick sort" << endl;
	cout << "4.count sort" << endl;
	cout << "5.radix count sort" << endl;
	cout << "|-enter your command: ";
	int commandNum;
	cin >> commandNum;
	switch (commandNum)
	{
	case 1:
		TestForLargeData(sortArray, 1, ReadArray.size());
		break;
	case 2:
		TestForLargeData(sortArray, 2, ReadArray.size());
		break;
	case 3:
		TestForLargeData(sortArray, 3, ReadArray.size());
		break;
	case 4:
		TestForLargeData(sortArray, 4, ReadArray.size());
		break;
	case 5:
		TestForLargeData(sortArray, 5, ReadArray.size());
		break;
	default:
		cout << "|-wrong command" << endl;
		break;
	}

	cout << "|-the sort data are:" << endl;
	for (int i = 0;i < ReadArray.size();i++)
	{
		cout << sortArray[i] << " ";
	}
	cout << endl;
}

void menu()
{
	using namespace std;
	cout << "|---------------command list---------------|" << endl;
	cout << "(1)large amount data test" << endl;
	cout << "(2)small amount large loops data test" << endl;
	cout << "(3)file creat,read and sort data test" << endl;
	cout << "(4)help" << endl;
	cout << endl;
	cout << "|-using example:press 1 to use command (1)" << endl;

}

int main()
{
	using namespace std;

	menu();
	int commandNum;
	while (1)
	{
		cout << "|--enter your command: ";
		cin >> commandNum;
		switch (commandNum)
		{
		case 1:
			LargeDataTest();
			break;
		case 2:
			SmallDataTest(100, 1000);
			break;
		case 3:
			CreatFileForTest();
			ReadDataFromFile();
			break;
		case 4:
			menu();
			break;
		default:
			cout << "wrong command" << endl;
			break;
		}
	}
}
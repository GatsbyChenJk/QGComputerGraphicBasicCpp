#include "BinaryTree.h"
#include <iostream>

void TestList()
{
	using namespace std;

	cout << "|-----------------Command List-----------------|" << endl;
	cout << "(0)initialize" << endl;
	cout << "(1)insert" << endl;
	cout << "(2)delete" << endl;
	cout << "(3)search" << endl;
	cout << "(41)pre-order traversal without recursion" << endl;
	cout << "(42)pre-order traversal with recursion" << endl;
	cout << "(51)in-order traversal without recursion" << endl;
	cout << "(52)in-order traversal with recursion" << endl;
	cout << "(61)post-order traversal without recursion" << endl;
	cout << "(62)post-order traversal with recursion" << endl;
	cout << "(7)level-order traversal" << endl;
	cout << "(8)help" << endl;
	cout << "[test example]press 3 to use command \"search\"" << endl;
	cout << "[test tip]press 8 to call command list again" << endl;
}

void Console()
{

	using namespace std;
	int commandNum=0;

	BinarySortTree<int> testTree;
	treeNode<int>* visit = nullptr;
	while (1)
	{
		cout << "|-please enter your command: ";
		cin >> commandNum;
		switch (commandNum)
		{
		case 0:
			int rootData;
			cout << "|-enter a root data you want: ";
			cin >> rootData;
			testTree.BST_init(rootData);
			if (testTree.BST_init(rootData))
			{
				cout << "init successfully!" << endl;
			}
			break;
		case 1:
			int insertData;
			cout << "|-enter your insert data: ";
			cin >> insertData;
			testTree.BST_insert(testTree.root, insertData);
			if (testTree.BST_insert(testTree.root, insertData))
			{
				cout << "insert successfully!" << endl;
			}
			break;
		case 2:
			int deleteData;
			cout << "|-enter your delete data: ";
			cin >> deleteData;
			testTree.BST_delete(testTree.root, deleteData);
			if (testTree.BST_delete(testTree.root, deleteData))
			{
				cout << "delete successfully!"<<endl;
			}
			else
			{
				cout << "data not found" << endl;
			}
			break;
		case 3:
			int searchData;
			cout << "|-enter your search data: ";
			cin >> searchData;
			testTree.BST_search(testTree.root, searchData);
			if (testTree.BST_search(testTree.root, searchData))
			{
				cout << "data exist!" << endl;
			}
			else
			{
				cout << "data not found" << endl;
			}
			break;
		case 41:
			cout << "here are the data in pre-order:" << endl;
			//treeNode<int>* visit = nullptr;
			testTree.BST_preorderI(testTree.root,visit);
			break;
		case 42:
			cout << "here are the data in pre-order(recursion version):" << endl;
			testTree.BST_preorderR(testTree.root);
			cout << endl;
			break;
		case 51:
			cout << "here are the data in in-order:" << endl;
			//treeNode<int>* visit = nullptr;
			testTree.BST_inorderI(testTree.root, visit);
			break;
		case 52:
			cout << "here are the data in in-order(recursion version):" << endl;
			testTree.BST_inorderR(testTree.root);
			cout << endl;
			break;
		case 61:
			cout << "here are the data in post-order:" << endl;
			//treeNode<int>* visit = nullptr;
			testTree.BST_postorderI(testTree.root, visit);
			break;
		case 62:
			cout << "here are the data in post-order(recursion version):" << endl;
			testTree.BST_postorderR(testTree.root);
			cout << endl;
			break;
		case 7:
			cout << "here are the data in level-order : " << endl;
			testTree.BST_levelOrder(testTree.root);
			cout << endl;
			break;
		case 8:
			TestList();
			break;
		default:
			cout << "wrong command" << endl;
			break;
		}
	}
}

int main()
{
	using namespace std;
	TestList();
	Console();

	return 0;
}
#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <utility>

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

template<class T>
class treeNode
{
public:
    T value;
    treeNode<T>* left, * right;
    treeNode();
    treeNode(T value);
    bool visited;
};
template<class T>
treeNode<T>::treeNode()
    :left(nullptr),right(nullptr),visited(false)
{}

template<class T>
treeNode<T>::treeNode(T value)
    :left(nullptr), right(nullptr),visited(false)
{
    this->value = value;
}

template<class T>
class BinarySortTree
{
private:
    int size = 0;
public:
    treeNode<T>* root = nullptr;//�����

    treeNode<T>* lastVisitedNode = nullptr;

    void resetVisited(treeNode<T>* trNode);

    int BST_init(T rootData);

    int BST_insert(treeNode<T>* trNode, T data);

    int BST_delete(treeNode<T>* trNode, T data);

    int BST_search(treeNode<T>* trNode, T data);

    void BST_preorderI(treeNode<T>* trNode, treeNode<T>* visit);

    void BST_preorderR(treeNode<T>* trNode);

    void BST_inorderI(treeNode<T>* trNode, treeNode<T>* visit);

    void BST_inorderR(treeNode<T>* trNode);

    void BST_postorderI(treeNode<T>* trNode, treeNode<T>* visit);

    void BST_postorderR(treeNode<T>* trNode);

    void BST_levelOrder(treeNode<T>* trNode);
};

template<class T>
void BinarySortTree<T>::resetVisited(treeNode<T>* trNode)
{
    if (trNode == nullptr)
    {
        return;
    }

    trNode->visited = false;
    resetVisited(trNode->left);
    resetVisited(trNode->right);
}


/**
 * BST initialize
 * @param trNode BST
 * @return is complete
 */
template<class T>
int BinarySortTree<T>::BST_init(T rootData)
{
    using namespace std;
    root = new treeNode<T>(rootData);
    return 1;
}

/**
 * BST insert
 * @param trNode BST
 * @param data value to insert
 * @return is successful
 */
template<class T>
int BinarySortTree<T>::BST_insert(treeNode<T>* trNode, T data)
{

    using namespace std;
    if (trNode == nullptr)
    {
        cout << "tree is empty,you need to init first" << endl;
        return 0;
    }

    treeNode<T>* temp = trNode;
    //ȷ�����ݲ���λ�ã�С���󣬴�����
    while (temp->left != nullptr || temp->right != nullptr)
    {
        if (data == temp->value)
        {
            return 0;   // �����Ѿ����ڣ�����Ҫ����
        }

        if (data < temp->value)
        {
            if (temp->left != nullptr)
            {
                temp = temp->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (temp->right != nullptr)
            {
                temp = temp->right;
            }
            else
            {
                break;
            }
        }
    }
    //��������
    if (temp->left == nullptr || temp->right == nullptr)
    {
        if (temp->left == nullptr)
        {
            temp->left = new treeNode<T>(data);
        }
        else if (temp->right == nullptr)
        {
            temp->right = new treeNode<T>(data);
        }
    }
    else
    {
        if (temp->left)
        {
            temp->left->value = data;
        }
        else if(temp->right)
        {
            temp->right->value = data;
        }
    }

    return 1;
}

/**
 * BST delete
 * @param trNode BST
 * @param data the value for Node which will be deleted
 * @return 1 is successful
 */
template<class T>
int BinarySortTree<T>::BST_delete(treeNode<T>* trNode, T data)
{
   using namespace std;
    if (trNode == nullptr)
    {
        cout << "tree is empty,you need to init first" << endl;
        return 0;
    }

    //treeNode<T>* tempNode=nullptr;
    treeNode<T>* delNode = trNode;
    treeNode<T>* parent = nullptr;
    //Ѱ�Ҵ�ɾ���Ľڵ�
    while (delNode != nullptr)
    {
        if (data < delNode->value)
        {
            parent = delNode;
            delNode = delNode->left;
        }
        else if(data>delNode->value)
        {
            parent = delNode;
            delNode = delNode->right;
        }
        else
        {
            break;
        }
    }
    //��û���ҵ�ָ���ڵ�ʱ
    if (delNode == nullptr)
    {
        cout << data << " did not found" << endl;
        return 0;
    }
    //�����ɾ���Ľڵ���Ҷ�ӽڵ�
    if (delNode->left == nullptr && delNode->right == nullptr)
    {
        if (parent == nullptr)//�����ɾ���ڵ�Ϊ���ڵ�
        {
            trNode = nullptr;
        }
        else if (parent->left == delNode)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }

        delete delNode;
        return 1;
    }
    //��ָ���ڵ����һ���ӽڵ�
    else if (delNode->left == nullptr || delNode->right == nullptr)
    {
        treeNode<T>* child = (delNode->left != nullptr) ? delNode->left : delNode->right;
        if (parent == nullptr)//�����ɾ���ڵ�Ϊ���ڵ�
        {
            trNode = child;
        }
        else if (parent->left == delNode)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }

        delete delNode;
        return 1;
    }
    //��ָ���ڵ�����������ڵ㶼����
    if (delNode->left != nullptr && delNode->right != nullptr)
    {
        //Ѱ�Ҵ�ɾ���ڵ�ĺ�̽ڵ�
        treeNode<T>* successor = delNode->right;
        parent = delNode;
        while (successor->left != nullptr)
        {
            parent = successor;
            successor = successor->left;
        }

        //����̽ڵ��ֵ������ɾ���ڵ�
        delNode->value = successor->value;

        //ɾ����̽ڵ�
        if (parent->left == successor)
        {
            parent->left = successor->right;
        }
        else
        {
            parent->right = successor->right;
        }

        delete successor;
        return 1;
    }
}

/**
 * BST search
 * @param trNode BST
 * @param data the value to search
 * @return 1 is exist
 */
template<class T>
int BinarySortTree<T>::BST_search(treeNode<T>* trNode, T data)
{
    using namespace std;
    if (trNode == nullptr)
    {
        cout << "tree is empty,you need to init first" << endl;
        return 0;
    }
    treeNode<T>* searchPtr = trNode;
    while (searchPtr != nullptr)
    {
        if (data < searchPtr->value)
        {
            searchPtr = searchPtr->left;
        }
        else if (data > searchPtr->value)
        {
            searchPtr = searchPtr->right;
        }
        else
        {
            //cout <<data<< " data exist" << endl;
            return 1;
        }
    }
    if (searchPtr == nullptr)
    {
        //cout << data << " data not found" << endl;
        return 0;
    }
}

/**
 * BST preorder traversal without recursion
 * @param trNode BST
 * @param visit callback
 */
template<class T>
void BinarySortTree<T>::BST_preorderI(treeNode<T>* trNode, treeNode<T>* visit)
{
    using namespace std;
    if (trNode == nullptr)
    {
        cout << "tree is empty,you need to init first" << endl;
        return;
    }

    stack<treeNode<T>*> PrintStack;//�洢�ڵ�ָ��

    //�Ӹ��ڵ㿪ʼ�Ƚ����ӽڵ���ջ�ٽ����ӽڵ���ջ
    PrintStack.push(trNode);
    while (!PrintStack.empty())
    {
        visit = PrintStack.top();
        if (visit->visited == false) // ����ýڵ㻹δ�����ʹ������������ֵ
        {
            cout << visit->value << " ";
            visit->visited = true; // ������״̬��Ϊ�ѷ���
        }
        PrintStack.pop();
        if (visit->right != nullptr && visit->right->visited == false) // ������ӽڵ�δ�����ʣ������ӽڵ���ջ
        {
            PrintStack.push(visit->right);
        }
        if (visit->left != nullptr && visit->left->visited == false) // ������ӽڵ�δ�����ʣ������ӽڵ���ջ
        {
            PrintStack.push(visit->left);
        }
    }

    // ������ɺ󣬽����нڵ�ķ���״̬����
    resetVisited(trNode);
    cout << endl;

}

/**
 * BST preorder traversal with recursion
 * @param trNode BST
 */
template<class T>
void BinarySortTree<T>::BST_preorderR(treeNode<T>* trNode)
{
    using namespace std;
    if (trNode == nullptr) 
    {
        cout << endl;
        return;
    }
    cout << trNode->value << " ";
    //treeNode<T>* lastVisitedNode = nullptr;
    if (lastVisitedNode != nullptr && (lastVisitedNode->left == trNode || lastVisitedNode->right == trNode))
    {
        //�����ǰ�ڵ�����һ�����ʽڵ�����ӽڵ�����ӽڵ㣬�������ýڵ�ķ���
    }
    else
    {
        lastVisitedNode = trNode;
        BST_preorderR(trNode->left);
        BST_preorderR(trNode->right);
    }
}

/**
 * BST inorder traversal without recursion
 * @param trNode BST
 * @param visit callback
 */
template<class T>
void BinarySortTree<T>::BST_inorderI(treeNode<T>* trNode, treeNode<T>* visit)
{
    using namespace std;

    treeNode<T>* temp = trNode;

    if (trNode == nullptr)
    {
        cout << "tree is empty,you need to init first" << endl;
        return ;
    }
    stack<treeNode<T>*> PrintStack;
    while (!PrintStack.empty() || trNode != nullptr)
    {
        //�����ӽڵ�������ջ
        while (trNode != nullptr)
        {
            PrintStack.push(trNode);
            trNode = trNode->left;
        }
        //��ջ��Ϊ�գ����ջ���ڵ�
        if (!PrintStack.empty())
        {
            visit = PrintStack.top();
            cout << visit->value << " ";
            PrintStack.pop();
            trNode = visit->right;
        }
        while (trNode != nullptr)
        {
            PrintStack.push(trNode);
            trNode = trNode->left;
        }
        //ջΪ��ʱ���������Ӻ͸��ڵ��Ѿ���������������������Һ���
        /*else
        {
            visit = visit->right;
        }*/
    }

    trNode = temp;
}

/**
 * BST inorder traversal with recursion
 * @param trNode BST
 */
template<class T>
void BinarySortTree<T>::BST_inorderR(treeNode<T>* trNode)
{
    using namespace std;
    if (trNode == nullptr || trNode->visited == true) return;
    BST_inorderR(trNode->left);
    cout << trNode->value << " ";
    trNode->visited = true;
    BST_inorderR(trNode->right);
    resetVisited(trNode);
}

/**
 * BST preorder traversal without recursion
 * @param trNode BST
 * @param visit callback
 */
template<class T>
void BinarySortTree<T>::BST_postorderI(treeNode<T>* trNode, treeNode<T>* visit)
{

    using namespace std;
    if (trNode == nullptr)
    {
        cout << "tree is empty,you need to init first" << endl;
        return ;
    }

   /*  stack<treeNode<T>*> PrintStack;
    PrintStack.push(trNode);
    visit = nullptr;//��¼��һ�η��ʵĽڵ�

   while (!PrintStack.empty())
    {
        treeNode<T>* tempNode = PrintStack.top();
        //���������û�з��ʹ�������������ջ
        if (tempNode->left != nullptr && visit != tempNode->left && visit != tempNode->right)
        {
            PrintStack.push(tempNode->left);
        }
        //���������û�з��ʹ�������������ջ��
        else if (tempNode->right != nullptr && visit != tempNode->right)
        {
            PrintStack.push(tempNode->right);
        }
        //��������������Ѿ����ʹ�����ô���ʸýڵ㣬�����ýڵ㵯��ջ
        else
        {
            PrintStack.pop();
            cout << tempNode->value << " ";
            visit = tempNode;//��Ƿ���
        }
    }*/

    stack<pair<treeNode<T>*, int>> PrintStack;
    PrintStack.push(make_pair(trNode, 0));

    while (!PrintStack.empty())
    {
        treeNode<T>* tempNode = PrintStack.top().first;
        int& state = PrintStack.top().second;

        if (tempNode->left != nullptr && state == 0)
        {
            PrintStack.push(make_pair(tempNode->left, 0));
            state = 1;
        }
        else if (tempNode->right != nullptr && state <= 1)
        {
            PrintStack.push(make_pair(tempNode->right, 0));
            state = 2;
        }
        else
        {
            PrintStack.pop();
            cout << tempNode->value << " ";
        }
    }
    //�����ʵ���У�����ʹ��pair�����ڵ��������״̬����һ�𡣷���״̬��3��ֵ��0��ʾ������δ���ʣ�1��ʾ�������ѷ��ʣ�2��ʾ�������ѷ��ʡ�
}

/**
 * BST postorder traversal with recursion
 * @param trNode BST
 */
template<class T>
void BinarySortTree<T>::BST_postorderR(treeNode<T>* trNode)
{
    using namespace std;
    if (trNode == nullptr|| trNode->visited == true) return;

    BST_postorderR(trNode->left);
    BST_postorderR(trNode->right);
    cout << trNode->value << " ";
    trNode->visited = true;
}

/**
 * BST level order traversal
 * @param teNode BST
 */
template<class T>
void BinarySortTree<T>::BST_levelOrder(treeNode<T>* trNode)
{
    using namespace std;

    if (trNode == nullptr)
    {
        cout << "tree is empty,you need to init first" << endl;
        return ;
    }
    treeNode<T>* tempNode;
    queue<treeNode<T>*> PrintQueue;
    PrintQueue.push(trNode);

    while (!PrintQueue.empty())
    {
        tempNode = PrintQueue.front();
        PrintQueue.pop();
        cout << tempNode->value << " ";
        //�Ӹ��ڵ���������Ѱ���ӽڵ㣬����ڵ���ڷ������
        if (tempNode->left != nullptr)
        {
            PrintQueue.push(tempNode->left);
        }
        if (tempNode->right != nullptr)
        {
            PrintQueue.push(tempNode->right);
        }
    }
}

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H

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
    treeNode<T>* root = nullptr;//根结点

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
    //确定数据插入位置，小向左，大向右
    while (temp->left != nullptr || temp->right != nullptr)
    {
        if (data == temp->value)
        {
            return 0;   // 数据已经存在，不需要插入
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
    //插入数据
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
    //寻找待删除的节点
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
    //当没有找到指定节点时
    if (delNode == nullptr)
    {
        cout << data << " did not found" << endl;
        return 0;
    }
    //如果待删除的节点是叶子节点
    if (delNode->left == nullptr && delNode->right == nullptr)
    {
        if (parent == nullptr)//如果待删除节点为根节点
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
    //当指定节点存在一个子节点
    else if (delNode->left == nullptr || delNode->right == nullptr)
    {
        treeNode<T>* child = (delNode->left != nullptr) ? delNode->left : delNode->right;
        if (parent == nullptr)//如果待删除节点为根节点
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
    //当指定节点的左右两个节点都存在
    if (delNode->left != nullptr && delNode->right != nullptr)
    {
        //寻找待删除节点的后继节点
        treeNode<T>* successor = delNode->right;
        parent = delNode;
        while (successor->left != nullptr)
        {
            parent = successor;
            successor = successor->left;
        }

        //将后继节点的值赋给待删除节点
        delNode->value = successor->value;

        //删除后继节点
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

    stack<treeNode<T>*> PrintStack;//存储节点指针

    //从根节点开始先将右子节点入栈再将左子节点入栈
    PrintStack.push(trNode);
    while (!PrintStack.empty())
    {
        visit = PrintStack.top();
        if (visit->visited == false) // 如果该节点还未被访问过，则输出它的值
        {
            cout << visit->value << " ";
            visit->visited = true; // 将访问状态置为已访问
        }
        PrintStack.pop();
        if (visit->right != nullptr && visit->right->visited == false) // 如果右子节点未被访问，则将右子节点入栈
        {
            PrintStack.push(visit->right);
        }
        if (visit->left != nullptr && visit->left->visited == false) // 如果左子节点未被访问，则将左子节点入栈
        {
            PrintStack.push(visit->left);
        }
    }

    // 遍历完成后，将所有节点的访问状态重置
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
        //如果当前节点是上一个访问节点的左子节点或右子节点，则跳过该节点的访问
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
        //将左子节点依次入栈
        while (trNode != nullptr)
        {
            PrintStack.push(trNode);
            trNode = trNode->left;
        }
        //若栈不为空，输出栈顶节点
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
        //栈为空时，表明左孩子和根节点已经遍历，接下来还需遍历右孩子
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
    visit = nullptr;//记录上一次访问的节点

   while (!PrintStack.empty())
    {
        treeNode<T>* tempNode = PrintStack.top();
        //如果左子树没有访问过，将左子树入栈
        if (tempNode->left != nullptr && visit != tempNode->left && visit != tempNode->right)
        {
            PrintStack.push(tempNode->left);
        }
        //如果右子树没有访问过，将右子树入栈。
        else if (tempNode->right != nullptr && visit != tempNode->right)
        {
            PrintStack.push(tempNode->right);
        }
        //如果左右子树都已经访问过，那么访问该节点，并将该节点弹出栈
        else
        {
            PrintStack.pop();
            cout << tempNode->value << " ";
            visit = tempNode;//标记访问
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
    //在这个实现中，我们使用pair将树节点与其访问状态绑定在一起。访问状态有3个值：0表示左子树未访问，1表示左子树已访问，2表示右子树已访问。
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
        //从根节点依次向下寻找子节点，如果节点存在放入队列
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

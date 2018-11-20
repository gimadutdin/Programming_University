#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
    this->root = nullptr;
    this->nodeCount = 0;
}

void Tree::addNode(TreeNode *v, int key, int value)
{
    if (root == nullptr)
    {
        root = new TreeNode(key, value);
        return;
    }
    if (key < v->getKey())
    {
        if (v->getLeft() != nullptr)
        {
            addNode(v->getLeft(), key, value);
        } else
        {
            v->setLeft(new TreeNode(key, value));
        }
    } else if (key > v->getKey())
    {
        if (v->getRight() != nullptr)
        {
            addNode(v->getRight(), key, value);
        } else
        {
            v->setRight(new TreeNode(key, value));
        }
    } else//key == v->getKey()
    {
        v->setValue(value);
    }
}

void Tree::addNode(int key, int value)
{
    Tree::addNode(root, key, value);
}

void Tree::show(TreeNode *v, int level)
{
    if (v == nullptr) return;
    for (int i = 0; i < level; i++)
    {
        cout << "    ";
    }
    cout << v->getKey() << "\n";
    Tree::show(v->getLeft(), level + 1);
    Tree::show(v->getRight(), level + 1);
}

void Tree::show()
{
    Tree::show(root);
}

void Tree::showBfs()
{
    Queue *q = new Queue();
    q->push(this->root);
    while (!q->isEmpty())
    {
        Queue *q2 = new Queue();
        while (!q->isEmpty())
        {
            TreeNode *t = q->pop();
            cout << t->getKey() << " ";
            if (t->getLeft() != nullptr)
            {
                q2->push(t->getLeft());
            }
            if (t->getRight() != nullptr)
            {
                q2->push(t->getRight());
            }
        }
        delete q;
        q = q2;
        cout << "\n";
    }
}

TreeNode *Tree::findNode(TreeNode *v, int key)
{
    if (v == nullptr)
        return nullptr;
    if (key < v->getKey())
    {
        return findNode(v->getLeft(), key);
    } else if (key > v->getKey())
    {
        return findNode(v->getRight(), key);
    } else//key == v->getKey()
    {
        return v;
    }
}

TreeNode *Tree::findNode(int key)
{
    return Tree::findNode(root, key);
}

void Tree::deleteNode(TreeNode *v, int key)
{
    if (v == nullptr) return;
    if (v->getLeft() != nullptr && v->getLeft()->getLeft() == nullptr && v->getLeft()->getRight() == nullptr && v->getLeft()->getKey() == key)
    {
        delete v->getLeft();
        v->setLeft(nullptr);
        return;
    }
    if (v->getRight() != nullptr && v->getRight()->getLeft() == nullptr && v->getRight()->getRight() == nullptr && v->getRight()->getKey() == key)
    {
        delete v->getRight();
        v->setRight(nullptr);
        return;
    }
    if (key < v->getKey())
    {
        deleteNode(v->getLeft(), key);
    } else if (key > v->getKey())
    {
        deleteNode(v->getRight(), key);
    } else//key == v->getKey()
    {
        if (v->getLeft() != nullptr && v->getRight() != nullptr)
        {
            //find minimal element in right subtree of v
            TreeNode *t = v->getRight();
            while (t->getLeft() != nullptr)
                t = t->getLeft();
            v->setKey(t->getKey());
            v->setValue(t->getValue());
            deleteNode(v->getRight(), t->getKey());
        } else
        {
            if (v->getLeft() != nullptr)
            {
                TreeNode *oldLeft = v->getLeft();
                v->setKey(oldLeft->getKey());
                v->setValue(oldLeft->getValue());
                v->setLeft(oldLeft->getLeft());
                v->setRight(oldLeft->getRight());
                delete oldLeft;
            } else if (v->getRight() != nullptr)
            {
                TreeNode *oldRight = v->getRight();
                v->setKey(oldRight->getKey());
                v->setValue(oldRight->getValue());
                v->setLeft(oldRight->getLeft());
                v->setRight(oldRight->getRight());
                delete oldRight;
            } else
            {
//                v->setLeft(nullptr);
//                v->setRight(nullptr);
//                //delete v;
            }
        }
    }
}

void Tree::deleteNode(int key)
{
    deleteNode(root, key);
}

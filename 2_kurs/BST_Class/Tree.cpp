#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree()
{
    this->root = nullptr;
    this->nodeCount = 0;
}

void Tree::addNode(Node *v, int key, int value)
{
    if (root == nullptr)
    {
        root = new Node(key, value);
        return;
    }
    if (key < v->getKey())
    {
        if (v->getLeft() != nullptr)
        {
            addNode(v->getLeft(), key, value);
        } else
        {
            v->setLeft(new Node(key, value));
        }
    } else if (key > v->getKey())
    {
        if (v->getRight() != nullptr)
        {
            addNode(v->getRight(), key, value);
        } else
        {
            v->setRight(new Node(key, value));
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

void Tree::show(Node *v, int level)
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

Node *Tree::findNode(Node *v, int key)
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

Node *Tree::findNode(int key)
{
    return Tree::findNode(root, key);
}

void Tree::deleteNode(Node *v, int key)
{
    if (v == nullptr) return;
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
            Node *t = v->getRight();
            while (t->getLeft() != nullptr)
                t = t->getLeft();
            v->setKey(t->getKey());
            v->setValue(t->getValue());
            deleteNode(v->getRight(), t->getKey());
        } else
        {
            if (v->getLeft() != nullptr)
            {
                Node *oldLeft = v->getLeft();
                v->setKey(oldLeft->getKey());
                v->setValue(oldLeft->getValue());
                v->setLeft(oldLeft->getLeft());
                v->setRight(oldLeft->getRight());
                delete oldLeft;
            } else if (v->getRight() != nullptr)
            {
                Node *oldRight = v->getRight();
                v->setKey(oldRight->getKey());
                v->setValue(oldRight->getValue());
                v->setLeft(oldRight->getLeft());
                v->setRight(oldRight->getRight());
                delete oldRight;
            } else
            {
                delete v;
            }
        }
    }
}

void Tree::deleteNode(int key)
{
    deleteNode(root, key);
}

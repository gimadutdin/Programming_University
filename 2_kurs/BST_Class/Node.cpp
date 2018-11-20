#include "Node.h"

Node::Node(int key, int value)
{
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

void Node::setKey(int key)
{
    this->key = key;
}

int Node::getKey()
{
    return this->key;
}

void Node::setValue(int value)
{
    this->value = value;
}

int Node::getValue()
{
    return this->value;
}

void Node::setLeft(Node *left)
{
    this->left = left;
}

Node *Node::getLeft()
{
    return this->left;
}

void Node::setRight(Node *right)
{
    this->right = right;
}

Node *Node::getRight()
{
    return this->right;
}

#include "TreeNode.h"

TreeNode::TreeNode(int key, int value)
{
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

void TreeNode::setKey(int key)
{
    this->key = key;
}

int TreeNode::getKey()
{
    return this->key;
}

void TreeNode::setValue(int value)
{
    this->value = value;
}

int TreeNode::getValue()
{
    return this->value;
}

void TreeNode::setLeft(TreeNode *left)
{
    this->left = left;
}

TreeNode *TreeNode::getLeft()
{
    return this->left;
}

void TreeNode::setRight(TreeNode *right)
{
    this->right = right;
}

TreeNode *TreeNode::getRight()
{
    return this->right;
}

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include "TreeNode.h"
//#include "QueueNode.h"
#include "Queue.h"

class Tree
{//binary search tree
    private:
    TreeNode *root;
    int nodeCount;

    void addNode(TreeNode *v, int key, int value);
    void show(TreeNode *v, int level = 0);
    TreeNode *findNode(TreeNode *v, int key);
    void deleteNode(TreeNode *v, int key);


    public:
    Tree();

    void addNode(int key, int value);
    TreeNode *findNode(int key);
    void deleteNode(int key);

    void show();
    void showBfs();
};



#endif // TREE_H_INCLUDED

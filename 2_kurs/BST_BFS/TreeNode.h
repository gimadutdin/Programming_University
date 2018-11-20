#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

class TreeNode
{
    private:
    int key, value;
    TreeNode *left, *right;

    public:
    TreeNode(int key, int value);
    void setKey(int key);
    int getKey();
    void setValue(int value);
    int getValue();

    void setLeft(TreeNode *left);
    TreeNode *getLeft();

    void setRight(TreeNode *right);
    TreeNode *getRight();

};

#endif // TREENODE_H_INCLUDED

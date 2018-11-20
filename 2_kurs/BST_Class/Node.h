#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

class Node
{
    private:
    int key, value;
    Node *left, *right;

    public:
    Node(int key, int value);
    void setKey(int key);
    int getKey();
    void setValue(int value);
    int getValue();

    void setLeft(Node *left);
    Node *getLeft();

    void setRight(Node *right);
    Node *getRight();

};

#endif // NODE_H_INCLUDED

#ifndef QUEUENODE_H_INCLUDED
#define QUEUENODE_H_INCLUDED
#include "TreeNode.h"

class QueueNode {
private:
    TreeNode *value;
    QueueNode *next;
    QueueNode *previous;
public:
    QueueNode(TreeNode* value);

    TreeNode* getValue();

    void setNext(QueueNode *next);

    QueueNode *getNext();

    void setPrevious(QueueNode *previous);

    QueueNode *getPrevious();
};

#endif // QUEUENODE_H_INCLUDED

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "QueueNode.h"

class Queue {
private:
    QueueNode *tail;
    QueueNode *head;
    int cnt;
public:
    Queue();
    void push(TreeNode *value);
    void print();
    void printReverse();
    bool isEmpty();
    TreeNode* pop();
};

#endif // QUEUE_H_INCLUDED

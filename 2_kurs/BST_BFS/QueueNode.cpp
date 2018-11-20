#include "QueueNode.h"

QueueNode::QueueNode(TreeNode* value) {
    this->value = value;
    this->next = nullptr;
}

TreeNode* QueueNode::getValue() {
    return this->value;
}


void QueueNode::setNext(QueueNode *next) {
    this->next = next;
}

QueueNode *QueueNode::getNext() {
    return this->next;
}

void QueueNode::setPrevious(QueueNode *previous) {
    this->previous = previous;
}

QueueNode *QueueNode::getPrevious() {
    return this->previous;
}

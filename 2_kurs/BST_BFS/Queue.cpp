#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    this->tail = nullptr;
    this->cnt = 0;
}

void Queue::push(TreeNode *value) {

    QueueNode *newNode = new QueueNode(value);
    if (this->cnt == 0) {
        this->tail = newNode;
        this->head = newNode;
    } else {
        newNode->setNext(this->tail);
        this->tail->setPrevious(newNode);
        this->tail = newNode;
    }
    cnt++;
}

void Queue::print() {
    //cout << "end -> ";
    QueueNode *currentNode = this->tail;
    for (int i = 0; i < this->cnt; i++) {
        cout << currentNode->getValue()->getKey() << " ";
        currentNode = currentNode->getNext();
    }
    //cout << " -> begin";
}

void Queue::printReverse() {
    //cout << "begin <- ";
    QueueNode *currentNode = this->head;
    for (int i = 0; i < this->cnt; i++) {
        cout << currentNode->getValue()->getKey() << " ";
        currentNode = currentNode->getPrevious();
    }
    //cout << " <- end";
}

TreeNode* Queue::pop() {
    if (this->cnt != 0) {
        TreeNode* valueFromQueue = this->head->getValue();
        QueueNode *temp = this->head;
        this->head = this->head->getPrevious();
        delete(temp);
        cnt--;
        return valueFromQueue;
    } else {
        throw "Empty queue!";
    }
}

bool Queue::isEmpty()
{
    return this->cnt == 0;
}

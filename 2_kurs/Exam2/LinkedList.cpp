#include "LinkedList.h"

LinkedList::LinkedList() {
    // this - указатель на экземпляр, для которого был
    // произведен вызов функции/конструктора
    (*this).top = nullptr;
    this->end = nullptr;
    this->count = 0;
}

bool LinkedList::isEmpty() {
    return this->top == nullptr;
}

void LinkedList::add(int value) {
    Node *newNode = new Node(value);
    if (this->end != nullptr) {
        this->end->next = newNode;
    } else {
        this->top = newNode;
    }
    this->end = newNode;
    this->count++;
}

void LinkedList::addToBegin(int value) {
    Node *newNode = new Node(value);
    newNode->next = this->top;
    this->top = newNode;
    this->count++;
}

int LinkedList::size() {
    return this->count;
}

int LinkedList::get(int index) {
    Node *t = this->top;
    for (int i = 0; i < index; i++)
    {
        t = t->next;
    }
    if (t != nullptr)
        return t->data;
    else return 0;
}

void LinkedList::remove(int index) {
    Node *t = this->top;
    for (int i = 0; i < index; i++)
    {
        t = t->next;
    }
    if (t == this->top)
    {
        Node *p = this->top->next;
        delete this->top;
        this->top = p;
        this->count--;
    } else if (t != nullptr)
    {
        Node *p = this->top;
        while (p->next != t)
        {
            p = p->next;
        }
        p->next = t->next;
        delete t;
        this->count--;
    }
}

bool LinkedList::contains(int value)
{
    Node *t = this->top;
    do
    {
        if (t->data == value)
            return true;
        t = t->next;
    } while (t != nullptr);
    return false;
}


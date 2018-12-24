#include "QueueListImpl.h"

QueueListImpl::QueueListImpl(IList *list) {
    this->list = list;
}

void QueueListImpl::push(int value) {
    this->list->addToBegin(value);
}

int QueueListImpl::pop() {
    int value = this->list->get(this->list->size() - 1);
    this->list->remove(this->list->size() - 1);
    return value;
}

bool QueueListImpl::contains(int value) {
    return this->list->contains(value);
}

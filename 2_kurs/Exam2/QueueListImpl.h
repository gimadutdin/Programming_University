#ifndef QUEUELISTIMPL_H_INCLUDED
#define QUEUELISTIMPL_H_INCLUDED

#include "IQueue.h"
#include "IList.h"

class QueueListImpl : public IQueue {
private:
    IList *list;
public:
    QueueListImpl(IList *list);
    void push(int value) override;
    int pop() override;
    bool contains(int value) override;
};

#endif // QUEUELISTIMPL_H_INCLUDED

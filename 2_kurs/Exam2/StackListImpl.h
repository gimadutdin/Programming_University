#ifndef EXAM2_STACKLINKEDLISTIMPL_H
#define EXAM2_STACKLINKEDLISTIMPL_H


#include "IStack.h"
#include "LinkedList.h"

class StackListImpl : public IStack {
private:
    IList *list;
public:
    StackListImpl(IList *list);
    void push(int value) override;
    int pop() override;
    bool contains(int value) override;
};


#endif //EXAM2_STACKLINKEDLISTIMPL_H

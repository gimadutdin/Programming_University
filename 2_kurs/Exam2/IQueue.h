#ifndef IQUEUE_H_INCLUDED
#define IQUEUE_H_INCLUDED

class IQueue {
public:
    virtual void push(int value) = 0;
    virtual int pop() = 0;
    virtual bool contains(int value) = 0;
};

#endif // IQUEUE_H_INCLUDED

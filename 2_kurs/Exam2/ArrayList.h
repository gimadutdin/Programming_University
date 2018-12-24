#ifndef EXAM2_ARRAYLIST_H
#define EXAM2_ARRAYLIST_H


#include "IList.h"
#include <cstdlib>

class ArrayList : public IList {
    int *arr;
    int maxSize, count;

    void addMemory();

    public:
    ArrayList();

    bool isEmpty() override;
    void add(int value) override ;
    void addToBegin(int value) override;
    int size() override;
    int get(int index) override;
    void remove(int index) override;
    bool contains(int value) override;
};


#endif //EXAM2_ARRAYLIST_H

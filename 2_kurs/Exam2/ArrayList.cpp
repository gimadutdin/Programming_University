#include "ArrayList.h"

ArrayList::ArrayList()
{
    this->count = 0;
    this->maxSize = 2;
    this->arr = new int[this->maxSize];
}

bool ArrayList::isEmpty() {
    return this->count == 0;
}

void ArrayList::add(int value) {
    if (this->count == this->maxSize)
    {
        addMemory();
    }
    this->arr[this->count] = value;
    this->count++;
}

void ArrayList::addToBegin(int value) {
    if (this->count == this->maxSize)
    {
        addMemory();
    }
    for (int i = this->count; i > 0; i--)
    {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[0] = value;
    this->count++;
}

int ArrayList::size() {
    return this->count;
}

int ArrayList::get(int index) {
    return this->arr[index];
}

void ArrayList::remove(int index) {
    for (int i = index; i < this->count - 1; i++)
    {
        this->arr[i] = this->arr[i + 1];
    }
    this->count--;
}

void ArrayList::addMemory()
{
    this->maxSize = (this->maxSize*3)/2;
    this->arr = (int *)realloc(this->arr, this->maxSize);
}

bool ArrayList::contains(int value)
{
    for (int i = 0; i < this->count; i++)
    {
        if (this->arr[i] == value)
        {
            return true;
        }
    }
    return false;
}

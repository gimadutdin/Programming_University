#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <cmath>

#include "Text.h"
#include "Dictionary.h"

class Vector
{
private:
    int *coordinates;
    int len;
public:
    Vector(Text *text, Dictionary *dict);
    ~Vector()
    {
        delete coordinates;
    }
    double compareWith(Vector *v);

    int getLen() {return len;}
    int getCoord(int i) {return coordinates[i];}

    void show();
};

#endif // VECTOR_H_INCLUDED

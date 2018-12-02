#include "Vector.h"

Vector::Vector(Text *text, Dictionary *dict)
{
    this->len = dict->getLen();
    this->coordinates = new int[this->len];
    for (int i = 0; i < this->len; i++)
    {
        this->coordinates[i] = text->getWordFrequency(dict->getWord(i));
    }
}

double Vector::compareWith(Vector *v2)
{
    double s = 0, m1 = 0, m2 = 0;
    for (int i = 0; i < this->getLen(); i++)
    {
        s += this->getCoord(i)*v2->getCoord(i);
    }
    for (int i = 0; i < this->getLen(); i++)
    {
        m1 += this->getCoord(i)*this->getCoord(i);
        m2 += v2->getCoord(i)*v2->getCoord(i);
    }
    m1 = sqrt(m1);
    m2 = sqrt(m2);
    return s/(m1*m2);
}

void Vector::show()
{
    for (int i = 0; i < this->len; i++)
    {
        std::cout << this->coordinates[i] << " ";
    }
}

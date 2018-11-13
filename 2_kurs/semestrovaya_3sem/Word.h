#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED
#include <stdlib.h>
#include <string.h>

class Word
{
private:
    char *letters;
    int len, max_len;

public:
    Word();
    void operator+=(char c);
    //void operator=(char str[]);
    int operator==(Word w2);
    void show();
    bool isEmpty();
    char* getString();
};

#endif // WORD_H_INCLUDED

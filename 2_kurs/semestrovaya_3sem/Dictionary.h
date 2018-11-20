#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

#include "Text.h"

class Dictionary
{
private:
    Text *dict;
public:
    Dictionary(Text *text1, Text *text2);
    //Text getText();
    void show();
};



#endif // DICTIONARY_H_INCLUDED

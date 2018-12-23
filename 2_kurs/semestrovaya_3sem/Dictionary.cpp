#include "Dictionary.h"
#include <iostream>
Dictionary::Dictionary(Text *text1, Text *text2)
{
    //delete dict;
    Text *text3 = text1->cpy();
    text3 = *text3 + text2;
    text3->lex_sort();
    text3->only_unique();//text3->show();
    dict = text3;
}

void Dictionary::show()
{
    dict->show();
}

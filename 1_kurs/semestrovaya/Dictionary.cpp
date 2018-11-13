#include "Dictionary.h"

Dictionary::Dictionary(Text *text)
{
    //delete dict;
    Text *text2 = text->cpy();
    text2->lex_sort();
    text2->only_unique();
    dict = text2;
}

void Dictionary::show()
{
    dict->show();
}

#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
#include "Word.h"

const char spec_chars[] = ",.:;()!?<>!@#$%^&*+-_/\{}|~\"";

class Text
{
private:
    Word **words;
    int len, max_len;

public:
    Text();
    void operator+=(Word *word);
    Text* operator+(Text *text);
    //void operator=(char str[]);
    //int operator==(Word w2);
    void show();
    void Normalize();
    Text* cpy();
    void lex_sort();
    void only_unique();
    int getWordFrequency(Word *word);

    int getLen() {return this->len;}
    Word* getWord(int i) {return this->words[i];}
};


#endif // TEXT_H_INCLUDED

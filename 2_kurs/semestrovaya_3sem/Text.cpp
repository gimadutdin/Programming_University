#include <iostream>
#include "Text.h"

Text::Text()
{
    this->len = 0;
    this->max_len = 10;
    this->words = new Word*[10];
}

void Text::operator+=(Word *word)
{
    if (len == max_len)
    {
        this->max_len = this->max_len*3/2 + 1;
        this->words = (Word **)realloc(this->words, this->max_len*sizeof(Word *));
    }
    this->words[len] = word;
    this->len++;
}

void Text::show()
{
    for (int i = 0; i < this->len; i++)
    {
        this->words[i]->show();
    }
}

void Text::Normalize()
{
    int words_count_1 = this->len, add_index = 0;
    Word **words2 = new Word*[words_count_1];
    char *w1;
    Word *w2;
    for (int i = 0; i < words_count_1; i++)
    {
        w1 = this->words[i]->getString();
        w2 = new Word();
        for (int j = 0; j < strlen(w1); j++)
        {
            bool add = true;
            for (int k = 0; k < strlen(spec_chars); k++)
            {
                if (w1[j] == spec_chars[k])
                {
                    add = false;
                    break;
                }
            }
            if (add)
            {
                *w2 += tolower(w1[j]);
            }
        }
        if (!w2->isEmpty())
        {
            words2[add_index] = w2;
            add_index++;
        } else
        {
            delete w2;
        }
        delete w1;
    }
    Word **t = this->words;

    this->words = words2;
    this->len = add_index;
    this->max_len = words_count_1;

    for (int i = 0; i < words_count_1; i++)
    {
        delete t[i];
    }
    delete t;
}

Text* Text::cpy()
{
    Text *text = new Text();
    for (int i = 0; i < this->len; i++)
    {
        *text += words[i];
    }
    return text;
}

void Text::lex_sort()
{
    for (int i = 0; i < this->len - 1; i++)
    {
        for (int j = i + 1; j < this->len; j++)
        {
            if (strcmp(this->words[i]->getString(), this->words[j]->getString()) > 0)
            {
                std::swap(this->words[i], this->words[j]);
            }
        }
    }
}

void Text::only_unique()
{
    Word **words2 = new Word*[this->len];
    int words_count_1 = this->len;
    int i = 0, add_index = 0;
    while (i < this->len)
    {
        words2[add_index] = this->words[i];
        add_index++;
        if (i == this->len - 1)
        {
            i++;
            continue;
        }
        //char *s1, *s2;
        while (i + 1 < this->len && strcmp(/*s1 = */this->words[i]->getString(), /*s2 = */this->words[i + 1]->getString()) == 0)
        {
            i++;
            //delete s1;
            //delete s2;
        }
        i++;
        //std::cout << "(" << this->words[i]->getString() << ")\n";
    }
    //Word **t = this->words;

    this->words = words2;
    this->len = add_index;
    //this->max_len = words_count_1;

//    for (int i = 0; i < words_count_1; i++)
//    {
//        delete t[i];
//    }
//    delete t;
}

Text* Text::operator+(Text *text2)
{
    Text *text = this->cpy();
    for (int i = 0; i < text2->len; i++)
    {
        *text += text2->words[i];
    }
    //text->show();
    return text;
}

int Text::getWordFrequency(Word *word)
{
    int cnt = 0;
    for (int i = 0; i < this->len; i++)
    {
        if (*this->words[i] == word)
        {
            cnt++;
        }
    }
    return cnt;
}

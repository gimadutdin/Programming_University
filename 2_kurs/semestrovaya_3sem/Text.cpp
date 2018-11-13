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
        this->max_len += 50;
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
    std::cout << "\n";
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
        while (i + 1 < this->len && strcmp(this->words[i]->getString(), this->words[i + 1]->getString()) == 0)
        {
            i++;
        }
        i++;
        //std::cout << "(" << this->words[i]->getString() << ")\n";
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

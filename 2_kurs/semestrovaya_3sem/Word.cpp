#include <iostream>
#include "Word.h"

Word::Word()
{
    //std::cout << "Yes!";
    this->len = 0;
    this->max_len = 10;
    this->letters = new char[10];
}

void Word::operator+=(char c)
{
    if (len == max_len)
    {
        this->max_len += 50;
        this->letters = (char *)realloc(this->letters, this->max_len*sizeof(char));
    }
    this->letters[len] = c;
    this->len++;
}

/*void Word::operator=(char str[])
{
    int str_len = strlen(str);
    this->letters = (char *)realloc(this->letters, str_len*sizeof(char));
    strcpy(this->letters, str);
    this->len = str_len;
    this->max_len = str_len + 10;
}*/

int Word::operator==(Word w2)
{
    return strcmp(this->letters, w2.letters);
}

void Word::show()
{
    //std::cout << "(((" << this->len << ")))";
    for (int i = 0; i < this->len; i++)
    {
        std::cout << this->letters[i];
    }
    std::cout << " ";
}

bool Word::isEmpty()
{
    return this->len == 0;
}

char* Word::getString()
{
    char *tmp = new char[this->len + 1];
    for (int i = 0; i < this->len; i++)
    {
        tmp[i] = this->letters[i];
    }
    tmp[this->len] = '\0';
    return tmp;
}

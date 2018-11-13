#include "Parser.h"

Parser::Parser(char str[])
{
    //std::cout << str;
    strcat(str, " ");
    int str_len = strlen(str);
    this->text = new Text();
    int pos = 0;
    Word *word = new Word();
    while (pos < str_len)
    {
        if (str[pos] == ' ')
        {
            if (!word->isEmpty())
            {
                *(this->text) += word;
                word = new Word();
            }
            pos++;
            continue;
        }
        *word += str[pos];
        pos++;
    }
}

Text* Parser::getText()
{
    return text;
}

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "Text.h"
#include <iostream>

class Parser
{
private:
    Text *text;
public:
    Parser(){}
    Text* Parse(char str[]);
};


#endif // PARSER_H_INCLUDED

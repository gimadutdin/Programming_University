#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "Text.h"
#include <iostream>

class Parser
{
private:
    Text *text;
public:
    Parser(char str[]);
    Text* getText();
};


#endif // PARSER_H_INCLUDED

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "Text.h"
#include <iostream>
#include <fstream>
#include <string>

class Parser
{
private:
    Text *text;
    char* readFile(char fileName[]);
public:
    Parser(){}
    Text* parseString(char str[]);
    Text* parseFromFile(char fileName[]);
};


#endif // PARSER_H_INCLUDED

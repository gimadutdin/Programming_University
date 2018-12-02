#include "Parser.h"

Text* Parser::parseString(char str[])
{
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
    return text;
}

Text* Parser::parseFromFile(char fileName[])
{
    char *fileContent = this->readFile(fileName);
    return this->parseString(fileContent);
}

char* Parser::readFile(char fileName[]) {
    std::ifstream ifs(fileName);
    if(ifs.is_open())
    {
        std::string s;
        s.assign((std::istreambuf_iterator<char>(ifs.rdbuf())), std::istreambuf_iterator<char>());
        char *res = new char[s.length() + 5];
        strcpy(res, s.c_str());
        return res;
        ifs.close();
    } else
    {
        std::cout << "Unable to open file" << std::endl;
        return NULL;
    }
}

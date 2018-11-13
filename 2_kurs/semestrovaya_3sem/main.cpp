#include <bits/stdc++.h>
#include "Parser.h"
#include "Dictionary.h"
using namespace std;

int main()
{
    char str[500] = "    PfsgGGHhbf,)))cvkjhk f; ;;..  u  abacaba abacaba  hello hello hello   AfgdsgfFERGRGsjhfrfgrfgrwgu   CdjFVFDFSBo   FBJFT jdjd    ";
//    cout << "Enter text:\n";
//    string s;
//    getline(cin, s);
//    str = (char *)s.c_str();
    Parser *p = new Parser(str);
    Text *text = p->getText();

    cout << "Initial text = ";text->show();

    text->Normalize();
    cout << "Normalized text = ";text->show();
    cout << "\nDictionary = ";
    Dictionary *dict = new Dictionary(text);
    dict->show();
    return 0;
}

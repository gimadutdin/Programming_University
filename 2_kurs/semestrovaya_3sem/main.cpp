#include <bits/stdc++.h>
#include "Parser.h"
#include "Dictionary.h"
using namespace std;

int main()
{
    char str1[500] = "    PfsgGGHhbf,)))cvkjhk f; ;;..  u  abacaba abacaba  hello hello hello   AfgdsgfFERGRGsjhfrfgrfgrwgu   CdjFVFDFSBo   FBJFT jdjd    ";
    char str2[500] = "ghuvfrxXuuhf fg:))fgf aaa?? aaa aaa bbb!!! yyy privet privet";

    Parser *p = new Parser();
    Text *text1 = p->Parse(str1);
    Text *text2 = p->Parse(str2);

    cout << "First text = ";text1->show();cout << "\n";
    cout << "Second text = ";text2->show();cout << "\n";

    text1->Normalize();
    text2->Normalize();
    cout << "Normalized first text = ";text1->show();cout << "\n";
    cout << "Normalized second text = ";text2->show();cout << "\n";

    cout << "\nDictionary from words of 1st and 2nd texts = ";
    Dictionary *dict = new Dictionary(text1, text2);
    dict->show();

    return 0;
}

//    cout << "Enter text:\n";
//    string s;
//    getline(cin, s);
//    str = (char *)s.c_str();

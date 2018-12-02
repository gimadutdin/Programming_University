#include <bits/stdc++.h>
#include "Parser.h"
#include "Dictionary.h"
#include "Vector.h"
using namespace std;

int main()
{
    //char str1[500] = "    PfsgGGHhbf,)))cvkjhk f; ;;..  u  abacaba abacaba  hello hello hello   AfgdsgfFERGRGsjhfrfgrfgrwgu   CdjFVFDFSBo   FBJFT jdjd    ";
    //char str2[500] = "ghuvfrxXuuhf fg:))fgf aaa?? aaa aaa bbb!!! yyy privet privet";

    Parser *p = new Parser();
    Text *text1 = p->parseFromFile("text1.txt");
    Text *text2 = p->parseFromFile("text2.txt");

    cout << "First text = ";text1->show();cout << "\n";
    cout << "Second text = ";text2->show();cout << "\n";

    text1->Normalize();
    text2->Normalize();
    cout << "Normalized first text = ";text1->show();cout << ")\n\n";
    cout << "Normalized second text = ";text2->show();cout << ")\n\n";

    cout << "\nDictionary from words of 1st and 2nd texts = ";
    Dictionary *dict = new Dictionary(text1, text2);
    dict->show();
    cout << "\n";

    Vector *vect1 = new Vector(text1, dict);cout << "\n\n\n";
    Vector *vect2 = new Vector(text2, dict);
    cout << "Vector 1 = ("; vect1->show(); cout << ")\n";
    cout << "Vector 2 = ("; vect2->show(); cout << ")\n";

    double sim_koef = vect1->compareWith(vect2);
    cout << "Text1 and Text2 similiarity koefficient = " << sim_koef << " or " << (int)(sim_koef*100) << "% \n";

    return 0;
}

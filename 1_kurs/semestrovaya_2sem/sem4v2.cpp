#include <bits/stdc++.h>
using namespace std;

const int ERROR = 19;
const int R = 3;
enum Type {ARRAY, NUMBER};

struct Var {
    Type type;
    char name[3];
    union {
        int arr[R];
        int value;
    };
    Var *next;
};

struct checkResult
{
    int prevState;
    int finalState;
    int lastPos;
};

int distSq(Var *x, Var *y)
{
    int res = 0;
    for (int i = 0; i < R; i++)
    {
        int t = x->arr[i] - y->arr[i];
        res += t*t;
    }
    return res;
}

int maxDiff(Var *x, Var *y)
{
    int res = 0;
    for (int i = 0; i < R; i++)
    {
        res = max(res, abs(x->arr[i] - y->arr[i]));
    }
    return res;
}

int crossProduct(Var *x, Var *y)
{
    int res = 0;
    for (int i = 0; i < R; i++)
    {
        res += x->arr[i]*y->arr[i];
    }
    return res;
}

void addVar(Var* &top, char name[], int arr[R])
{
    Var *v = new Var;
    v->type = ARRAY;
    strcpy(v->name, name);
    for (int i = 0; i < R; i++)
    {
        v->arr[i] = arr[i];
    }
    v->next = top;
    top = v;
}

void addVar(Var* &top, char name[], int value)
{
    Var *v = new Var;
    v->type = NUMBER;
    strcpy(v->name, name);
    v->value = value;
    v->next = top;
    top = v;
}

Var *findVar(Var *top, char name[])
{
    Var *v = top;
    while (v && strcmp(v->name, name) != 0)
    {
        v = v->next;
    }
    if (v) return v;
    return NULL;
}

Var *prev(Var *top, Var *v)
{
    Var *p = top, *pr = NULL;
    while (p && p != v)
    {
        pr = p;
        p = p->next;
    }
    return pr;
}

void deleteVar(Var* &top, Var *v)
{
    if (v == top)
    {
        Var *x = top;
        top = top->next;
        delete x;
    } else
    {
        Var *t = prev(top, v);
        if (t == NULL)
        {
            cout << "Memory error: element is not in the list";
            exit(-1);
        } else
        {
            t->next = v->next;
            delete v;
        }
    }
}

bool isLetter(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

checkResult analyze(char input[])
{
    int state = 0, prevState;
    int len = strlen(input);
    int digCounter, numCounter;
    checkResult r;

    int i = 0;
    while (i < len && state != ERROR) {
        char curChar = input[i];
        if (curChar == '#')
        {
            i++;
            continue;
        }
        //cout << "\n" << state << "  " << curChar << "  " << numCounter << "\n";
        prevState = state;
        switch (state)
        {
            case 0: {
                if (isLetter(curChar))
                {
                    state = 1;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 1: {
                if (isDigit(curChar))
                {
                    state = 2;
                } else if (isLetter(curChar))
                {
                    state = 11;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 2: {
                if (curChar == ':')
                {
                    state = 3;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 3: {
                if (curChar == '=')
                {
                    state = 4;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 4: {
                if (curChar == '(')
                {
                    numCounter = 1;
                    state = 5;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 5: {
                if (curChar == '+' || curChar == '-')
                {
                    digCounter = 1;
                    state = 6;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 6: {
                state = 7;
                while (digCounter <= 5)
                {
                    if (isDigit(curChar))
                    {
                        digCounter++;
                    } else
                    {
                        state = ERROR;
                        i++;//if we dont write this line, the position of error will be one less
                        break;
                    }
                    curChar = input[++i];
                }
                if (digCounter > 5)
                    i--;//!!!!!!!!!!!!!!!!!!!!!!
                break;
            }
            case 7: {
                if (numCounter < R)
                {
                    state = 8;
                } else
                {
                    state = 9;
                }
                i++;
                break;
            }
            case 8: {
                if (curChar == ',')
                {
                    state = 5;
                    numCounter++;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 9: {
                if (curChar == ')')
                {
                    state = 10;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 10: {
                if (curChar == ';')
                {
                    state = 0;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 11: {
                if (curChar == ':')
                {
                    state = 12;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 12: {
                if (curChar == '=')
                {
                    state = 13;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 13: {
                if (isLetter(curChar))
                {
                    state = 14;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 14: {
                if (isDigit(curChar))
                {
                    state = 15;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 15: {
                if (curChar == 'v' || curChar == '^' || curChar == '*')
                {
                    state = 16;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 16: {
                if (isLetter(curChar))
                {
                    state = 17;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 17: {
                if (isDigit(curChar))
                {
                    state = 18;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            case 18: {
                if (curChar == ';')
                {
                    state = 0;
                } else
                {
                    state = ERROR;
                }
                i++;
                break;
            }
            default: {
                state = ERROR;
            }
        }
    }
    r.finalState = state;
    r.prevState = prevState;
    r.lastPos = i - 1;
    return r;
}


void memTable(ofstream &f, Var *variables)
{
    Var *v = variables;
    while (v)
    {
        f << v->name << " = ";
        if (v->type == ARRAY)
        {
            f << "(";
            for (int i = 0; i < R; i++)
            {
                f << v->arr[i];
                if (i < R - 1) f << ",";
            }
            f << ")";
        } else//NUMBER
        {
            f << v->value;
        }
        f << "\n";
        v = v->next;
    }

}

void runProgram(ofstream &f, char input[], Var* &variables)
{
    int i = 0;
    int len = strlen(input);
    while (i < len)
    {
        if (input[i] == '#')
        {
            memTable(f, variables);
            f.flush();//is program ends not in main flush
            //will not run automatically
            //so we need to do it ourselves
            //otherwise file will be empty
            //exit(0);
            return;
        } else
        {
            char leftId[3];
            leftId[0] = input[i];
            i++;
            leftId[1] = input[i];
            leftId[2] = '\0';
            i++;
            if (isDigit(leftId[1]))//LD - id type 1
            {
                i += 3;//skip : = ( . Now will be sign of first number in the array
                int arr[R], pos = 0;
                for (int j = 0; j < R; j++)
                {
                    int sgn = (input[i] == '+' ? 1 : -1);
                    i++;
                    int num = 0;
                    for (int k = 0; k < 5; k++)
                    {
                        num = (num + (input[i] - '0'))*10;
                        i++;
                    }
                    num /= 10;
                    if (j < R - 1) i++;//if number is not last we need to skip ,
                    num *= sgn;
                    arr[j] = num;
                }
                i++;//skip )
                Var *res = findVar(variables, leftId);
                if (res == NULL)
                {
                    addVar(variables, leftId, arr);
                } else
                {
                    deleteVar(variables, res);
                    addVar(variables, leftId, arr);
                }
            } else//LL  - id type 2
            {
                i += 2;//skip : =
                char idX[3], idY[3];
                idX[0] = input[i];
                i++;
                idX[1] = input[i];
                idX[2] = '\0';
                i++;
                char op = input[i];
                i++;
                idY[0] = input[i];
                i++;
                idY[1] = input[i];
                idY[2] = '\0';
                i++;
                int value;
                Var *v1, *v2;
                v1 = findVar(variables, idX);
                v2 = findVar(variables, idY);
                if (v1 == NULL)
                {
                    f << "Runtime error: variable " << idX << " was not found";
                    f.flush();
                    exit(-1);
                }
                if (v2 == NULL)
                {
                    f << "Runtime error: variable " << idY << " was not found";
                    f.flush();
                    exit(-1);
                }
                if (op == 'v')
                {
                    value = distSq(v1, v2);
                } else if (op == '^')
                {
                    value = maxDiff(v1, v2);
                } else//*
                {
                    value = crossProduct(v1, v2);
                }
                Var *res = findVar(variables, leftId);
                if (res == NULL)
                {
                    addVar(variables, leftId, value);
                } else
                {
                    deleteVar(variables, res);
                    addVar(variables, leftId, value);
                }
            }
            i++;//skip ;
        }
    }
}

int fileSize(const char * fn){
    ifstream f(fn);int s = 0;
    while (!f.eof()) {f.get();s++;}
    f.close();
    return s - 1;
}

void readText(char *x, ifstream &f)
{
    int i = 0; while (f >> x[i++]);
}

void printError(ofstream &f, checkResult cr)
{
    f << "Error: at position " << cr.lastPos + 1 << " : ";
    switch (cr.prevState)
    {
        case 0: {
            f << "expected big letter";
            break;
        }
        case 1: {
            f << "expected big letter or digit";
            break;
        }
        case 2: {
            f << "expected :";
            break;
        }
        case 3: {
            f << "expected = ";
            break;
        }
        case 4: {
            f << "expected (";
            break;
        }
        case 5: {
            f << "expected + or -";
            break;
        }
        case 6: {
            f << "expected a digit";
            break;
        }
        //at state 7 cannot be error
        case 8: {
            f << "expected ,";
            break;
        }
        case 9: {
            f << "expected )";
            break;
        }
        case 10: {
            f << "expected ;";
            break;
        }
        case 11: {
            f << "expected :";
            break;
        }
        case 12: {
            f << "expected =";
            break;
        }
        case 13: {
            f << "expected big letter";
            break;
        }
        case 14: {
            f << "expected digit";
            break;
        }
        case 15: {
            f << "expected an operation v or ^ or *";
            break;
        }
        case 16: {
            f << "expected big letter";
            break;
        }
        case 17: {
            f << "expected digit";
            break;
        }
        case 18: {
            f << "expected ;";
            break;
        }
        default: {}
    }
    f << "\n";
}

int main()
{
    char *program = new char[fileSize("input.txt")];
    ifstream in("input.txt");
    readText(program, in);
    Var *variables = NULL;
    ofstream out("output.txt");
    checkResult res = analyze(program);
    if (res.finalState == 0)
    {
        cout << "Program is correct. Running...\n";
        runProgram(out, program, variables);
        cout << "Program was run successfully.";
    } else
    {
        cout << "Program is incorrect\n";
        out << "Program is incorrect\n";
        printError(out, res);
    }
    return 0;
}

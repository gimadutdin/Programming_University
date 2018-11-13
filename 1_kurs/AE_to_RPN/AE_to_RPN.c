#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char data;
    struct stackNode *next;
} stackNode;

bool stackEmpty(stackNode *top) {return (top == NULL);}

void stackPush(stackNode **top, char data)
{
    stackNode *p = (stackNode*)malloc(sizeof(stackNode));
    p->data = data;
    p->next = *top;
    *top = p;
}

char stackTop(stackNode *top) {return top->data;}

void stackPop(stackNode **top)
{
    stackNode *p = *top;
    *top = p->next;
    free(p);
}

bool isLetter(char x) {return x >= 'a' && x <= 'z';}
bool isOp(char x) {return (x == '+' || x == '-' || x == '*' || x == '/');}

int prior(char op)
{
    int res = 0;
    if (op == '(') res = 1;
    if (op == '+' || op == '-') res = 2;
    if (op == '*' || op == '/') res = 3;
    return res;
}

int main()
{
    char expr[100];
    printf("Enter an arithmetic expression with letters: ");
    scanf("%s", expr);
    printf("\nArithmetic expression: %s \n", expr);
    int pos = 0, exprLen = strlen(expr), posRes = 0;
    char *res = (char *)malloc(exprLen*sizeof(char) + 5);
    stackNode *stack = NULL;
    while (pos < exprLen)
    {
        char curChar = expr[pos];
        if (isLetter(curChar))
        {
            res[posRes] = curChar;
            posRes++;
        } else if (isOp(curChar))
        {
            if (stackEmpty(stack) || prior(curChar) > prior(stackTop(stack)))
            {
                stackPush(&stack, curChar);
            } else
            {
                while (!stackEmpty(stack) && prior(curChar) <= prior(stackTop(stack)))
                {
                    res[posRes] = stackTop(stack);
                    posRes++;
                    stackPop(&stack);
                }
                stackPush(&stack, curChar);
            }
        } else if (curChar == '(')
        {
            stackPush(&stack, curChar);
        } else if (curChar == ')')
        {
            while (stackTop(stack) != '(')
            {
                res[posRes] = stackTop(stack);
                posRes++;
                stackPop(&stack);
            }
            stackPop(&stack);
        }
        pos++;
    }
    while (!stackEmpty(stack))
    {
        res[posRes] = stackTop(stack);
        posRes++;
        stackPop(&stack);
    }
    res[posRes] = '\0';
    printf("Reverse polish notation: %s \n\n", res);
    return 0;
}

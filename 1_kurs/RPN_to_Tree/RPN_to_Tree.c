#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
typedef enum {VALUE, OP} Type;

typedef struct {
    Type type;
    union {int value;char op;};
    struct treeNode *left, *right;
} treeNode;

typedef struct {
    Type type;
    union {int value;char op;};
} exprElem;

typedef struct {
    treeNode *data;
    struct treeStackNode *next;
} treeStackNode;

bool stackEmpty(treeStackNode *top) {return (top == NULL);}

void stackPush(treeStackNode **top, void *data)
{
    treeStackNode *p = (treeStackNode*)malloc(sizeof(treeStackNode));
    p->data = data;
    p->next = *top;
    *top = p;
}

void *stackTop(treeStackNode *top) {return top->data;}

void stackPop(treeStackNode **top)
{
    treeStackNode *p = *top;
    *top = p->next;
    free(p);
}

treeNode *makeLeaf(Type type, int data)
{
    treeNode *t = (treeNode*)malloc(sizeof(treeNode));
    t->type = type;
    if (type == VALUE)
    {
        t->value = data;
    } else
    {
        t->op = (char)data;
    }
    t->left = NULL;
    t->right = NULL;
    return t;
}

treeNode *buildSyntaxTree(exprElem rpn[], int n)
{
    treeStackNode *stack = NULL;
    int stackSize = 0;
    int i = 0;
    while(i < n)
    {
        treeNode *el = makeLeaf(rpn[i].type, (rpn[i].type == VALUE) ? rpn[i].value : rpn[i].op);
        //printf("i = %d, stack = %d, el->type = %d\n", i, stack, el->type);
        if (el->type == VALUE)
        {
            stackPush(&stack, el);
            stackSize++;
        } else if (el->type == OP)
        {
            if (stackSize <= 1)
            {
                if (el->op == '-')
                {
                    treeStackNode *t = (treeStackNode *)(stackTop(stack));
                    stackPop(&stack);
                    t->data = (-*(int *)t->data);
                    stackPush(&stack, t);
                }
            } else
            {
                treeNode *r = (treeNode *)stackTop(stack);
                stackPop(&stack);
                treeNode *l = (treeNode *)stackTop(stack);
                stackPop(&stack);
                treeNode *res = (treeNode *)malloc(sizeof(treeNode));
                res->type = OP;
                res->op = el->op;
                res->left = l;
                res->right = r;
                stackPush(&stack, res);
            }
        }
        i++;
    }
    treeNode *tree = stackTop(stack);
    stackPop(&stack);
    return tree;
}

void showTree(treeNode *tree, int level)
{
    if (tree == NULL) return;
    int i;
    for (i = 0; i < level; i++)
        printf("    ");
    if (tree->type == VALUE)
        printf("%d\n", tree->value);
    else if (tree->type == OP)
        printf("%c\n", tree->op);
    showTree(tree->left, level + 1);
    showTree(tree->right, level + 1);
}

bool isNum(char *s)
{
    int len = strlen(s), i;
    bool res = true;
    for (i = 0; i < len && res; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            if (s[i] == '0' && i == 0)
                res = false;
        } else
            res = false;
    }
    return res;
}

int strInt(char *s)
{
    int len = strlen(s), res = 0, i;
    for (i = 0; i < len; i++)
    {
        res = (res + (s[i] - '0'))*10;
    }
    return res/10;
}

int main()
{
    exprElem expr[30];
    int n, i;
    printf("Enter number of elements in reverse polish notation: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element number %d: ", i);
        char s[20];
        scanf("%s", s);
        if (isNum(s))
        {
            expr[i].type = VALUE;
            expr[i].value = strInt(s);
        } else
        {
            expr[i].type = OP;
            expr[i].op = s[0];
        }
    }
    treeNode *tree = buildSyntaxTree(expr, n);
    showTree(tree, 0);
    return 0;
}

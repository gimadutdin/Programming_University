#include <iostream>
#include "IList.h"
#include "LinkedList.h"
#include "ArrayList.h"
#include "IStack.h"
#include "StackListImpl.h"
#include "IQueue.h"
#include "QueueListImpl.h"

int main() {
    int n;

    IList *linked_list1 = new LinkedList();
    IStack *stack1 = new StackListImpl(linked_list1);
    cout << "Stack based on linked list created." << endl;
    cout << "Enter number of elements: ";
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cout << ">> "; cin >> tmp;
        stack1->push(tmp);
    }
    int x;
    cout << "Enter a number: ";
    cin >> x;
    if (stack1->contains(x))
    {
        cout << "YES there is such element!\n";
    } else
    {
        cout << "NO there is no such element!\n";
    }
    cout << "Stack1:\n";
    for (int i = 0; i < n; i++)
    {
        tmp = stack1->pop();
        cout << tmp << "\n";
    }
    cout << "\n///////////////////////////////////////////////\n";

    IList *array_list1 = new ArrayList();
    IStack *stack2 = new StackListImpl(array_list1);
    cout << "Stack based on array list created." << endl;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << ">> "; cin >> tmp;
        stack2->push(tmp);
    }
    cout << "Enter a number: ";
    cin >> x;
    if (stack2->contains(x))
    {
        cout << "YES there is such element!\n";
    } else
    {
        cout << "NO there is no such element!\n";
    }
    cout << "Stack2:\n";
    for (int i = 0; i < n; i++)
    {
        tmp = stack2->pop();
        cout << tmp << "\n";
    }
    cout << "\n///////////////////////////////////////////////\n";

    IList *linked_list2 = new LinkedList();
    IQueue *queue1 = new QueueListImpl(linked_list2);
    cout << "Queue based on linked list created." << endl;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << ">> "; cin >> tmp;
        queue1->push(tmp);
    }
    cout << "Enter a number: ";
    cin >> x;
    if (queue1->contains(x))
    {
        cout << "YES there is such element!\n";
    } else
    {
        cout << "NO there is no such element!\n";
    }
    cout << "Queue1:\n";
    for (int i = 0; i < n; i++)
    {
        tmp = queue1->pop();
        cout << tmp << "\n";
    }

    cout << "\n///////////////////////////////////////////////\n";

    IList *array_list2 = new ArrayList();
    IQueue *queue2 = new QueueListImpl(array_list2);
    cout << "Queue based on array list created." << endl;
    cout << "Enter number of elements: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << ">> "; cin >> tmp;
        queue2->push(tmp);
    }
    cout << "Enter a number: ";
    cin >> x;
    if (queue2->contains(x))
    {
        cout << "YES there is such element!\n";
    } else
    {
        cout << "NO there is no such element!\n";
    }
    cout << "Queue2:\n";
    for (int i = 0; i < n; i++)
    {
        tmp = queue2->pop();
        cout << tmp << "\n";
    }

    return 0;
}

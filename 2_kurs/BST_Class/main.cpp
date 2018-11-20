#include <bits/stdc++.h>
#include "Tree.h"
using namespace std;

int main()
{
    Tree *bst = new Tree();
    int n, key, value;
    cout << "Enter n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> key >> value;
        bst->addNode(key, value);
    }
    bst->show();

    cout << endl << "Enter key of node to search: ";
    cin >> key;
    Node *f = bst->findNode(key);
    if (f != nullptr)
    {
        cout << "Node found: " << "(" << f->getKey() << ", " << f->getValue() << ")\n";
    } else
    {
        cout << "Node not found!";
    }

    cout << endl << "Enter key of node to delete: ";
    cin >> key;
    bst->deleteNode(key);

    bst->show();

    return 0;
}

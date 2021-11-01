#include <iostream>
#include <list>
#include "Tree.h"

using namespace std;

int main()
{
    Tree<int> aTree({ 45,74,28,32,45,44, 100 });

    list<int> myList;
    list<int> myListReverse;
    cout << "\n Inorder:\n";
    aTree.Listinorder(&myList);
    for (list<int>::iterator it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\n Inreverse:\n";
    aTree.Listinreverse(&myListReverse);

    for (list<int>::iterator it = myListReverse.begin(); it != myListReverse.end(); it++)
    {
        cout << *it << " ";
    }
}

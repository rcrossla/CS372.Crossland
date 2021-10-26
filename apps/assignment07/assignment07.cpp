//
//  main.cpp
//  TreeTest
//
//  Created by Adam Lewis on 10/3/16.
//  Copyright © 2016 Adam Lewis. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include "Tree.h"
#include "myTree.h"

using namespace std;

struct fields
{
    size_t numElements = 0;
    vector<int>* ptr = new vector<int>;
    Tree<int> aTree2;
};

fields * add(int);

auto f2 = [](int thing)->void {std::cout << thing << " "; };

int main(int argc, const char* argv[]) {

    fields *st;

    std::cout << "Tree test program\n";
    Tree<int> aTree({ 45,74,28,32,45,44, 100 });

    std::cout << "Preorder:\n";
    aTree.preorder(f2);
    std::cout << "\n Inorder:\n";
    aTree.inorder(f2);
    std::cout << "\n Postorder\n";
    aTree.postorder(f2);
    std::cout << std::endl;

    bool flag = false;


    flag = aTree.member(44);
    if (flag == true)
    {
        cout << "Number found" << endl;
    }
    else
    {
        cout << "Number NOT found" << endl;
    }


    flag = aTree.member(1);
    if (flag == true)
    {
        cout << "Number found" << endl;
    }
    else
    {
        cout << "Number NOT found" << endl;
    }

    // part3
   
    
    st = add(5);

    cout << "Number of elements: " << st->numElements << endl;

    cout << "Vector: ";
    for (int index = 0; index < st->numElements; index++) {
        cout << st->ptr->at(index) << " ";
    }
    cout << endl;

    cout << "tree: ";
    st->aTree2.inorder(f2);
    cout << endl;
    // part 4

    int randNum = 0;
    double vecTime, treeTime = 0.0;

    int sizes[] = { 1000,10000,100000 };
    int picks = 100;

    srand(time(NULL));

    fields* treePtr;
    vector<int> vec;

    cout << endl;
    cout << setw(20) << "Size" << setw(40) << "Vector Search (s)" << setw(40) << "Tree Search (s)" << endl;

    for (auto size : sizes)
    {
        treePtr = add(size);

        for (int i = 1; i <= picks; i++)
        {
            randNum = (rand() % size) + 1;
            vec.push_back(treePtr->ptr->at(randNum));
        }

        for (int i = 0; i < picks; i++)
        {
            vecTime = treeTime = 0.0;
            auto start = chrono::steady_clock::now();
            for (int x = 0; x < treePtr->numElements; x++)
            {
                if (vec.at(i) == treePtr->ptr->at(x)) {
                    x = treePtr->numElements;
                }
            }
            auto end = chrono::steady_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            vecTime += elapsed_seconds.count();

        }
        for (int i = 0; i < picks; i++)
        {
            auto start = chrono::steady_clock::now();
            for (int x = 0; x < treePtr->numElements; x++)
            {
                if (treePtr->aTree2.member(vec.at(i)))
                {
                    x = treePtr->numElements;
                }
            }
            auto end = chrono::steady_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            treeTime += elapsed_seconds.count();
        }

        cout << setw(20) << size  << setw(40) << vecTime / picks << setw(40) << treeTime / picks << endl;
        
    }
    
    return 0;
}

fields * add(int max)
{
    fields* ptr2 = new fields;
    int num = 0;

    srand(time(NULL));

    ptr2->numElements = max;

   for (int i = 0; i < max; i++)
    {
       num = (rand() % 100) + 1;
        ptr2->ptr->push_back(num);
    }

    sort(ptr2->ptr->begin(), ptr2->ptr->end());

    int temp;
    for (int i = 0; i < max; i++)
    {
        temp = ptr2->ptr->at(i);
        ptr2->aTree2 = ptr2->aTree2.insert(temp);
    }
    
    return ptr2;
}



//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
#include <iostream>

#include "../../include/Bag.h"
#include "../../include/ReceiptBag.h"
using namespace std;

template <typename Thing>
void printItem(Thing item) {
    cout << item << " ";
}

void function1();
void function2();

int main() {

    function1();
    function2();

}



void function1(){

    cout << "-------Bag Class Questions 1 and 2-------" << endl << endl;
    Bag<int> aBagOfIntegers;
    if (aBagOfIntegers.empty()) {
        cout << "Yep, the new bag is empty. " << endl;
    }
    for (int i = 10; i >= 0; i--) {
        aBagOfIntegers.insert(i);
    }
    aBagOfIntegers.traverse(printItem);
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << aBagOfIntegers.back() << " ";
        aBagOfIntegers.pop();
    }
    if (!aBagOfIntegers.empty()) {
        aBagOfIntegers.traverse(printItem);
        cout << endl;
    }
    aBagOfIntegers.insert(42);
    aBagOfIntegers.traverse(printItem);
}

void function2() {
    cout << endl << endl;
    cout << "-------Receipt Bag Class Question 3-------" << endl << endl;
    ReceiptBag<int> rBag;
    int receipt = 0;

    if (rBag.size() == 1) {

        cout << "Bag is empty. " << endl;
    }
    for (int i = 10; i >= 0; i--) {

        receipt = rBag.insertBag(i);
        rBag.insertReceipt(receipt);
    }
    cout << "Contents of Bag" << endl;
    rBag.traverseBag();

    cout << "Content of Receipts" << endl;
    rBag.traverseReceipt();
    cout << endl;

    cout << "Delete receipt num 101( number 9) from Bag" << endl;
    rBag.deleteBag(101);
    rBag.traverseBag();

    cout << "Delete receipt num 101 from receipts" << endl;
    rBag.deleteReceipt(101);
    rBag.traverseReceipt();
}
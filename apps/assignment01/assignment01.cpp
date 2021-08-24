//
// File:   assignment1.cpp
// Author: Rachel Crossland
// Purpose: 
// Illustrate some of the bad thins that can happen with
// pointers
//
#include <iostream>
#include <string>

using namespace std;

const int ARRAYSIZE = 100;

void functionOne();
void functionTwo();
void functionThree();
string* functionHelper();

int main() {

    functionOne();
    functionTwo();
    functionThree();


    return 0;
}

void functionOne() {

    cout << "function one" << endl;

    int* ptr1 = new int[ARRAYSIZE];
    for (int i = 0; i < ARRAYSIZE; i++) {
        *(ptr1 + i) = i;
    }

    int* ptr2 = ptr1;

    delete[] ptr1;

    for (int i = 0; i <= 9; i++) {
        cout << *(ptr2 + i) << endl;
    }

}

void functionTwo() {

    cout << "function two" << endl;

    int* ptr1 = new int[ARRAYSIZE];
    for (int i = 0; i < ARRAYSIZE; i++) {
        *(ptr1 + i) = i;
    }

    int* ptr2 = ptr1;

    delete ptr1;

    cout << "Address: " << ptr2 << endl;
    for (int i = 0; i <= 9; i++) {
        cout << *(ptr2 + i) << endl;
    }
}

void functionThree() {

    cout << "function three" << endl;

    string* ptr = functionHelper();

    cout << *ptr << endl;
}

string* functionHelper() {

    string myString[] = { "This is my string" };

    string* ptr = myString;

    return myString;
}
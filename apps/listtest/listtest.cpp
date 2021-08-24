//
// File:   listtest.cpp
// Author: Your Glorious Instructor <adam.lewis@athens.edu>
// Purpose:
// Demonstrate the use of our List class.
//
#include <iostream>
#include "cs372List.h"
using namespace std;

template <typename T>
void printItem(T item) {
  cout << item << " ";
}

int main() {
  List<int> aListOfIntegers;
  if (aListOfIntegers.empty()) {
    cout << "Yep, the new list is empty. " << endl;
  }
  for (int i = 10; i >= 0; i--) {
    aListOfIntegers.push_front(i);
  }
  aListOfIntegers.traverse(printItem);
  cout << endl;
  for (int i = 0; i < 10; i++) {
    cout << aListOfIntegers.back() << " ";
    aListOfIntegers.pop_back();
  }
  if (!aListOfIntegers.empty()) {
    aListOfIntegers.traverse(printItem);
    cout << endl;
  }
  aListOfIntegers.push_back(42);
  aListOfIntegers.traverse(printItem);
  return 0;
}

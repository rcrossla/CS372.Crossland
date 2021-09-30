
#include <iostream>
#include <fstream>
#include "./Vector.h"
using namespace std;




int main()
{
	ofstream myfile;

	myfile.open("tasks.txt");
	int number = 0;

	do
	{
		cout << "Select a number: " << endl << endl;
		cout << "1) Display all items" << endl;
		cout << "2) Display selected item" << endl;
		cout << "3) Mark a task as done" << endl;
		cout << "4) Exit program" << endl;

		cin >> number;

	} while (number < 1 || number > 4);


}

void function()
{




}


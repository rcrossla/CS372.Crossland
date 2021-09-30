
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void function(int);
int display();

int main()
{
	ofstream inputFile;

	inputFile.open("tasks.txt");
	int number = 0;
	string str;

	while (getline(cin, str))
	{
		if (str.size() > 0)
		{
			vector.push_back(str);
		}
	}


	


}
int display()
{
	do
	{
		cout << "Select a number: " << endl << endl;
		cout << "1) Display all items" << endl;
		cout << "2) Display selected item" << endl;
		cout << "3) Mark a task as done" << endl;
		cout << "4) Exit program" << endl;

		cin >> number;

	} while (number < 1 || number > 4);

	return number;
}
void function(int num)
{
	int choice = 0;
	string line = "";

	
	switch(num)
	{
		case 1:
		{
			while (!inputFile.eof())
			{
				cout << getline(inputFile, line) << endl;
			}
		}
		case 2:
		{
			
			cout << "Which item would you like to view: ";
			cin >> choice;

			cout << endl << endl;

			cout << vector.at(choice);

		}
		case 3:
		{
			cout << "Which task is done: ";
			cin >> choice;

			if (vector.at(choice) == 'U')
			{
				vector.at(choice) = 'D';
			}


		}
		default: 
		{

		}

	}



}


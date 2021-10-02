
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void function(int, vector<string>*);
int display();
void setChar(int, vector<string>*);
void updateFile(vector<string>, fstream *);



int main()
{
	vector<string> vec;
	fstream inputFile;

	inputFile.open("tasks.txt", ios::in | ios::out);

	int num = 0;
	string str;

	if (inputFile)
	{
		
		while(!inputFile.eof())
		{
			getline(inputFile, str);
			vec.push_back(str);
		}

		inputFile.close();
		
		while (num != 4)
		{
			num = display();
			function(num, &vec);
		}

		inputFile.open("tasks.txt", ios::in | ios:: out);

		updateFile(vec, &inputFile);
		inputFile.close();
	}
	else
	{
		cout << "file failed";
	}
}


int display()
{
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

	return number;
}

void function(int num, vector<string> *vec)
{
	int choice = 0;
		
	switch(num)
	{
		case 1:
		{

			cout << "case 1 opens" << endl;
			
			for(vector<string>::iterator i = vec->begin(); i != vec->end(); ++i)
			{
				cout << *i << endl;
			}
			cout << endl << endl;
			break;
		}
		case 2:
		{
			cout << "Which item would you like to view: ";
			cin >> choice;

			cout << endl << endl;

			choice -= 1;
			cout << (*vec)[choice];

			cout << endl << endl;

			break;
		}
		case 3:
		{
			string line = "";
			cout << "Which task is done: ";
			cin >> choice;

			choice -= 1;
			setChar(choice, vec);

			break;
		}
		default: 
		{
			num = 4;
		}
	}
}

void updateFile(vector<string> vec, fstream *inputFile)
{
	for (vector<string>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		cout << *i << endl;
		*inputFile << *i << endl;
	}
	
}

void setChar(int choice, vector<string> *vec)
{
	string tmpString = (*vec)[choice];

	cout << "mark as done" << endl;
	for (int i = 0; i < tmpString.length(); i++)
	{
		if (tmpString[i] == 'U')
		{
			tmpString[i] = 'D';
		}
	}

	(*vec)[choice] = tmpString;

	
}



#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


void function(int, vector<string>);
int display();
void set(string);

vector<string> vec;

int main()
{
	ifstream inputFile;

	inputFile.open("tasks.txt");

	int num = 0;
	string str;

	if (inputFile)
	{

		while(getline(inputFile,str))
		{
			vec.push_back(str);
		}

		inputFile.close();

		num = display();
		function(num, vec);
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
void function(int num, vector<string> vec)
{
	int choice = 0;
	string line = "";
		
	switch(num)
	{
		case 1:
		{

			cout << "case 1 opens";
			
			for(int i = 0; i < vec.size(); i++)
			{
				
				cout << vec[i] << endl;
			}
			break;
		}
		case 2:
		{
			cout << "Which item would you like to view: ";
			cin >> choice;

			cout << endl << endl;

			cout << vec[choice];

			break;
		}
		case 3:
		{
			cout << "Which task is done: ";
			cin >> choice;

			choice -= 1;
			line = vec[choice];

			set(line);

			break;
		}
		default: 
		{
			exit(0);
		}
	}
}

void set(string line)
{
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == 'U')
		{
			line[i] = 'D';
		}
	}

}


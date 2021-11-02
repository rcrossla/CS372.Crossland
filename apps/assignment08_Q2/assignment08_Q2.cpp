
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void fill(int, vector<string>*);
int display();
void updateFile(vector<string>, fstream *);
void changePriority(vector<tasks>*);

struct tasks
{
	int id = 0;
	char marked = ' ';
	string msg = " ";
	int priority = 0;

	bool operator<(const tasks& t) const { return priority < t.priority; }
};


int main()
{
	tasks checkList;

	vector<string> vec;
	
	vector<tasks> heapVec;
	
	fstream inputFile;

	inputFile.open("C:/Users/Rachel Crossland/Desktop/GitHub/CS372.Crossland/apps/assignment08_Q2/tasks2.txt", ios::in | ios::out);

	int num = 0;
	string str;
	tasks temptasks;
	int pos;

	if (inputFile)
	{
		

		while (!inputFile.eof())
		{
			int temp = 0;
			string tempStr = " ";

			getline(inputFile, str);

			temptasks.id = stoi(GetWord(&str));
			temptasks.marked = GetWord(&str)[0];
			
			pos = 0;
			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
				{
					pos = i;
				}
			}

			temptasks.msg = str.substr(0, pos);
			temptasks.priority = stoi(str.substr(pos));
			heapVec.push_back(temptasks);
		}

		inputFile.close();
		make_heap(heapVec.begin(), heapVec.end());

		
		while (num != 4)
		{
			num = display();
			fill(num, &heapVec);

			cout << "-------------------------------------------" << endl << endl;
		}

		inputFile.open("C:/Users/Rachel Crossland/Desktop/GitHub/CS372.Crossland/apps/assignment08_Q2/tasks2.txt", ios::in | ios:: out);

		updateFile(heapVec, &inputFile);
		inputFile.close();
	}
	else
	{
		cout << "file failed";
	}
}

string GetWord(string* inString)
{
	string returnString, tempString;
	int pos;
	pos = inString->find(' ') + 1;
	returnString = inString->substr(0, pos);
	tempString = inString->substr(pos);
	*inString = tempString;
	
	return returnString;
}
int display()
{
	int number = 0;
	do
	{
		
		cout << "1) Display all items" << endl;
		cout << "2) Display selected item" << endl;
		cout << "3) Mark a task as done" << endl;
		cout << "4) Change a tasks priority" << endl;
		cout << "5) Exit program" << endl << endl;
		cout << "Select a number: ";

		cin >> number;

	} while (number < 1 || number > 4);

	cout << endl << endl;

	return number;
}
void fill(int num, vector<tasks> *vec)
{
	int choice = 0;
		
	switch(num)
	{
		case 1:
		{

			for(vector<tasks>::iterator i = vec->begin(); i != vec->end(); ++i)
			{
				cout << i->id << " " << i->marked << " " << i->msg << " " << i->priority;
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
			cout << (*vec)[choice].id;

			cout << endl << endl;

			break;
		}
		case 3:
		{
			string line = "";
			cout << "Which task is done: ";
			cin >> choice;

			choice -= 1;
			(*vec)[choice].marked = 'D';
			break;
		}
		case 4:
		{
			changePriority(&*vec);
		}
		default: 
		{
			num = 4;
		}
	}
}
void changePriority(vector<tasks>* vec)
{
	tasks temptask;
	int choice = 0;

	cout << endl;
	cout << "PLease enter the Task number between 1 and " << vec->size() << endl;
	cin >> choice;

	if (choice >= 1 && choice <= vec->size())
	{
		for (auto& element : *vec)
		{
			if (element.id == choice)
			{
				temptask = (*vec)[choice - 1];
				temptask.marked = 'D';
				(*vec)[choice - 1] = temptask;
			} 
		}
	}
}
void updateFile(vector<tasks> vec, fstream *inputFile)
{
	for (vector<tasks>::iterator i = vec.begin(); i != vec.end(); ++i)
	{
		cout << i->id << " " << i->marked << " " << i->msg << " " << i->priority;
		*inputFile << i->id << " " << i->marked << " " << i->msg << " " << i->priority << endl;
	}
	
}



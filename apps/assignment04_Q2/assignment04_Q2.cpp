

// When outputing a map it prints the map out of order.
// The lines are correct just not in the correct sequence.

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <map>
#include <list>
#include <iomanip>
#include <algorithm> 

using namespace std;

list<string> myList;
list<string> myQueue;
map<string, string> myMap;

void buildMap(int, string, string);
void printMap();

int main()
{
    fstream inputFile;
    inputFile.open("file.txt");

    string space = " ";
    string word = "";
    

    myList.push_back(space);
    myList.push_back(space);
    myList.push_back(space);

    int numRead = 0;
    while (!inputFile.eof())
    {
        inputFile >> word;
        transform(word.begin(), word.end(), word.begin(), toupper);
        myList.push_back(word);
        numRead++;
    }
    myList.push_back(space);
    myList.push_back(space);
    myList.push_back(space);

    string listword = "";
    string queuestring = "";
    string keyWord = "";


    for (int i = 1; i <= 7; i++)
    {
        listword = myList.front();
        myQueue.push_back(listword);
        myList.pop_front();
    }

    bool flag = false;
    int counter = 1;
    do
    {
        keyWord = "";
        queuestring = "";
        int i = 1;

        buildMap(i, keyWord, queuestring);

        if (counter < numRead)
        {
            string temp = "";

            temp = myList.front();
            myList.pop_front();
            myQueue.push_back(temp);
            myQueue.pop_front();
        }
        else
        {
            flag = true;
        }

        counter++;

    } while (flag == false);

    printMap();

}

void buildMap(int i, string key, string queue)
{
    for (auto q : myQueue)
    {

        if (i == 4)
        {
            key = q;
            queue += key += ", ";
        }
        else
        {
            queue += q += ", ";
        }
        i++;
    }
    myMap.insert(pair<string, string>(key, queue));

}
void printMap()
{
    
    for (const auto& element : myMap)
    {
        cout << " \" " << element.second << "\"" << endl << endl;
    }
    
   
}

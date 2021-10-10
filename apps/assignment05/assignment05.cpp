#include <iostream>
#include <stack>
#include <chrono>

using namespace std;

void moveDisks(int, int, int, int);
void iterative(int, int, int, int);
int move(stack<int>&, stack <int>&);

stack<int> pole1;
stack<int> pole2;
stack<int> pole3;

int main()
{
	
	const int NUMDISKS = 50;
	const int FROMPEG = 1;
	const int TOPEG = 3;
	const int TEMPPEG = 2;

	double firstTime = 0.0;
	double secondTime = 0.0;

	for (int i = NUMDISKS; i >= 1; i--)
	{
		pole1.push(i);
	}

	cout << "RECURSIVE" << endl << endl;
	
	auto start = chrono::steady_clock::now();

	moveDisks(NUMDISKS, FROMPEG, TOPEG, TEMPPEG);
	cout << "All the pegs are moved!" << endl;

	auto end = chrono::steady_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	


	cout << "-------------------------------------------------------------------------" << endl << endl;

	cout << "ITERATIVE" << endl << endl;

	auto start2 = chrono::steady_clock::now();

	iterative(NUMDISKS, FROMPEG, TOPEG, TEMPPEG);
	cout << "All the pegs are moved!" << endl;

	auto end2 = chrono::steady_clock::now();
	chrono::duration<double>elapsed_seconds2 = end2 - start2;
	

	cout << "-------------------------------------------------------------------------" << endl << endl;
	
	cout << "Recursion time elapsed: " << elapsed_seconds.count() << "s\n";
	cout << endl << endl;
	cout << "Iterative time elapsed: " << elapsed_seconds2.count() << "s\n";

}
void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {

	if (num > 0) {
		moveDisks(num - 1, fromPeg, tempPeg, toPeg);
		//cout << "Move a disk from peg " << fromPeg << " to peg " << toPeg << endl;
		moveDisks(num - 1, tempPeg, toPeg, fromPeg);
	}
}
void iterative(int num, int fromPeg, int toPeg, int tempPeg) {

	int totalMoves = 0;
	totalMoves = (pow(2, num) - 1);
	int tempNum = 0;
	int flag = 0;

	if (num % 2 == 0) {
		

		for (int i = 1; i <= totalMoves; i++)
		{
			if (i % 3 == 1)
			{
				flag = move(pole1, pole2);

				if (flag == 1)
				{
					//cout << "Move a disk from peg " << fromPeg << " to peg " << tempPeg << endl;
				}
				else
				{
					//cout << "Move a disk from peg " << tempPeg << " to peg " << fromPeg << endl;

				}
			}
			if (i % 3 == 2)
			{
				flag = move(pole1, pole3);

				if (flag == 1)
				{
					//cout << "Move a disk from peg " << fromPeg << " to peg " << toPeg << endl;
				}
				else
				{
					//cout << "Move a disk from peg " << toPeg << " to peg " << fromPeg << endl;
				}


			}
			if (i % 3 == 0)
			{
				flag = move(pole2, pole3);

				if (flag == 1)
				{
					//cout << "Move a disk from peg " << tempPeg << " to peg " << toPeg << endl;
				}
				else
				{
					//cout << "Move a disk from peg " << toPeg << " to peg " << tempPeg << endl;
				}
			}
		}
	}
	else {

		for (int i = 1; i <= totalMoves; i++)
		{
			if (i % 3 == 1)
			{
				flag = move(pole1, pole3);

				if (flag == 1)
				{
					//cout << "Move a disk from peg " << fromPeg << " to peg " << toPeg << endl;
				}
				else
				{
					//cout << "Move a disk from peg " << toPeg << " to peg " << fromPeg << endl;
				}
			}
			if (i % 3 == 2)
			{
				flag = move(pole1, pole2);

				if (flag == 1)
				{
					//cout << "Move a disk from peg " << fromPeg << " to peg " << tempPeg << endl;
				}
				else
				{
					//cout << "Move a disk from peg " << tempPeg << " to peg " << fromPeg << endl;
				}
			}
			if (i % 3 == 0)
			{
				flag = move(pole2, pole3);

				if (flag == 1)
				{
					//cout << "Move a disk from peg " << tempPeg << " to peg " << toPeg << endl;
				}
				else
				{
					//cout << "Move a disk from peg " << toPeg << " to peg " << tempPeg << endl;
				}

			}

			
		}
	}
}
int move(stack<int> &x, stack <int> &y)
{
	int tempNum = 0;

	if (y.empty() == true)
	{

		tempNum = x.top();
		x.pop();
		y.push(tempNum);
		return 1;

	}
	else if (x.empty() == true)
	{
		tempNum = y.top();
		y.pop();
		x.push(tempNum);
		return 2;
	}
	else 
	{
		if (x.top() < y.top())
		{
			tempNum = x.top();
			x.pop();
			y.push(tempNum);
			return 1;
		}
		else
		{
			tempNum = y.top();
			y.pop();
			x.push(tempNum);
			return 2;
		}
		
	}	

}


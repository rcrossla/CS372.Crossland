#include <iostream>

using namespace std;

void moveDisks(int, int, int, int);
void iterative(int, int, int, int);

int main()
{
	const int NUMDISKS = 3;
	const int FROMPEG = 1;
	const int TOPEG = 3;
	const int TEMPPEG = 2;
	cout << "RECURSIVE" << endl << endl;
	moveDisks(NUMDISKS, FROMPEG, TOPEG, TEMPPEG);
	cout << "All the pegs are moved!" << endl;

	cout << "-------------------------------------------------------------------------" << endl << endl;

	cout << "ITERATIVE" << endl << endl;
	iterative(NUMDISKS, FROMPEG, TOPEG, TEMPPEG);
	cout << "All the pegs are moved!" << endl;

}
void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {

	if (num > 0) {
		moveDisks(num - 1, fromPeg, tempPeg, toPeg);
		cout << "Move a disk from peg " << fromPeg << " to peg " << toPeg << endl;
		moveDisks(num - 1, tempPeg, toPeg, fromPeg);
	}
}
void iterative(int num, int fromPeg, int toPeg, int tempPeg) {

	if (num % 2 == 0) {

		for (int i = num; i >= 0; --i)
		{

			cout << "even" << endl;
			cout << "Move a disk from peg " << fromPeg << " to peg " << tempPeg << endl;
			cout << "Move a disk from peg " << fromPeg << " to peg " << toPeg << endl;
			cout << "Move a disk from peg " << tempPeg << " to peg " << toPeg << endl;
		}
	}
	else {
	
		for (int i = num; i >= 0; --i)
		{

			cout << "Move a disk from peg " << fromPeg << " to peg " << toPeg << endl;
			cout << "Move a disk from peg " << fromPeg << " to peg " << tempPeg << endl;
			cout << "Move a disk from peg " << toPeg << " to peg " << tempPeg << endl;
			cout << "Move a disk from peg " << fromPeg << " to peg " << toPeg << endl;

			cout << "Move a disk from peg " << tempPeg << " to peg " << fromPeg << endl;
			cout << "Move a disk from peg " << tempPeg << " to peg " << toPeg << endl;	
			cout << "Move a disk from peg " << fromPeg << " to peg " << toPeg << endl;

		}
	}
	
	
}


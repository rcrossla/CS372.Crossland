
#include <iostream>
#include <cctype>
#include <cstring>
#include <stack>
using namespace std;

void readAndEvaluate(istream& ins);
void evaluateStackTops(stack<double>& numbers, stack<char>& ops);
void readAndEvaluate2(istream& ins);
void evaluateStackTops2(stack<double>& numbers, stack<char>& ops);

int main()
{
	//postfix
	cout << "Type a fully parenthsized expression" << endl;
	
	readAndEvaluate(cin);

	cin.ignore();
	cout << endl << endl;

	//prefix
	cout << "Type a fully parenthsized expression" << endl;
	readAndEvaluate2(cin);

	return 0;

}


void readAndEvaluate(istream& ins) {
	const char DECIMAL = '.';
	const char RIGHTPAREN = ')';
	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;
	while (ins && ins.peek() != '\n') {
		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
			ins >> number;
			numbers.push(number);

		}
		else if (strchr("+-*/", ins.peek()) != NULL) {
			ins >> symbol;
			operations.push(symbol);
		}
		else if (ins.peek() == RIGHTPAREN) {
			ins.ignore();
			evaluateStackTops(numbers, operations);	
			
		}
		else {
			ins.ignore();

		}
	}
	

}

void evaluateStackTops(stack<double>& numbers, stack<char>& operations) {
	

	while (!numbers.empty())
	{
		cout << numbers.top() << " ";
		numbers.pop();

	}

	while (!operations.empty())
	{
		cout << operations.top() << " ";
		operations.pop();
	}
	


}


void readAndEvaluate2(istream& ins) {
	const char DECIMAL = '.';
	const char RIGHTPAREN = ')';
	stack<double> numbers;
	stack<char> operations;
	double number;
	char symbol;
	while (ins && ins.peek() != '\n') {
		if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) {
			ins >> number;
			numbers.push(number);

		}
		else if (strchr("+-*/", ins.peek()) != NULL) {
			ins >> symbol;
			operations.push(symbol);
		}
		else if (ins.peek() == RIGHTPAREN) {
			ins.ignore();
			evaluateStackTops2(numbers, operations);

		}
		else {
			ins.ignore();

		}
	}


}

void evaluateStackTops2(stack<double>& numbers, stack<char>& operations) {

	while (!operations.empty())
	{
		cout << operations.top() << " ";
		operations.pop();
	}

	while (!numbers.empty())
	{
		cout << numbers.top() << " ";
		numbers.pop();

	}
	


}

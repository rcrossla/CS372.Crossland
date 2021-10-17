#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<chrono>
#include<iomanip>


using namespace std;

int anyEqual(int, vector<vector<int>>);
void fill(int, vector<vector<int>>*);

int arr[8] = { 10,20,30,40,50,100,500,1000};

int main()
{
	srand(time(NULL));

	vector<vector<int>> Array;
	int num = 0;
	int equal = 0;
	double avg = 0.0;
	double sum = 0.0;


	cout << left << setw(20) << "For array size" << setw(50) << "Average time to find duplicate" << endl << endl;
	
	for (int x = 0; x <= 7; x++)
	{
		num = arr[x];

		for (int i = 0; i <= 20; i++)
		{
			fill(num, &Array);
	
			auto start = chrono::steady_clock::now();

			equal = anyEqual(num, Array);

			auto end = chrono::steady_clock::now();
			chrono::duration<double> elapsed_seconds = end - start;

			sum += elapsed_seconds.count();

			Array.clear();
		}

		avg = sum / 20;

		cout << left << setw(8) << num << right << setw(42) << avg << endl;
		

	}

	


}
void fill(int num,vector<vector<int>> *A) {
	vector<int> temp;

	for (auto row = 0; row < num; ++row)
	{
		for (auto col = 0; col < num; ++col)
		{
			int randomNum = rand() % 20 + 1;
			temp.push_back(randomNum);
		}
		A->push_back(temp);
		temp.clear();
	}
}
int anyEqual(int n, vector<vector<int>> A) {

	int i, j, k, m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				for (m = 0; m < n; m++)
				{

					if (A[i][j] == A[k][m] && !(i == k && j == m))
					{
						return 1;
					}
				}
			}
		}
	}
}
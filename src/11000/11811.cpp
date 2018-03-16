#include<iostream>
using namespace std;

int N;
int arr[1001];
int matrix[1001][1001];
int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> matrix[i][j];
	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
		{
			arr[i] |= matrix[i][j];
			arr[j] |= matrix[i][j];
		}

	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}
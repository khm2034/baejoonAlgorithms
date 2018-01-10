#include <iostream>

using namespace std;

void input();
void solution();

int T;
int inputData[101];
int outputData[101];
long long dp[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 0, };

int main()
{
	input();
	solution();
	return 0;
}

void input() 
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> inputData[i];
	}
}

void solution()
{
	for (int t = 0; t < T; t++)
	{
		for (int i = 9; i <= inputData[t]; i++)
			dp[i] = dp[i - 1] + dp[i - 5];

		cout << dp[inputData[t]] << endl;
	}
}
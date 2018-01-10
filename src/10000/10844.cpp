#include<iostream>

using namespace std;

void solution();
int num;
int dp[101][10] = { 0, };
unsigned long long result = 0;

int main()
{
	cin >> num;

	solution();

	cout << result%1000000000 << endl;
	return 0;
}

void solution()
{
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= num; i++)
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				dp[i][j] = (dp[i - 1][j + 1]) % 1000000000;
			else if (j == 9)
				dp[i][j] = (dp[i - 1][j - 1]) % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1])%1000000000;
		}

	for (int i = 0; i <= 9; i++)
		result = (result + dp[num][i]) % 1000000000;
}